#include "codec.h"

#include <muduo/base/Logging.h>
#include <muduo/net/Endian.h>
#include <muduo/net/protorpc/google-inl.h>

#include <google/protobuf/descriptor.h>

#include <zlib.h>  // uncompress

#include "cs_enum.pb.h"
#include <boost/make_shared.hpp>
#include "XXTeaMgr.h"
#include <stdio.h>

#pragma GCC diagnostic ignored "-Wold-style-cast"

using namespace muduo;
using namespace muduo::net;

const std::string ProtobufCodec::sInitKey_ = "dzKYiBUnWyG7GMdn";
char ProtobufCodec::UncompresBuff[MAX_MSG_BUFF_SIZE] = {0};
char ProtobufCodec::CompresBuff[MAX_MSG_BUFF_SIZE] = {0};

void ProtobufCodec::fillEmptyBuffer(Buffer* buf, const google::protobuf::Message& message)
{
  assert(buf->readableBytes() == 0);

  // code copied from MessageLite::SerializeToArray() and MessageLite::SerializePartialToArray().
  GOOGLE_DCHECK(message.IsInitialized()) << InitializationErrorMessage("serialize", message);

  int byte_size = message.ByteSize();
  buf->ensureWritableBytes(byte_size);

  uint8_t* start = reinterpret_cast<uint8_t*>(buf->beginWrite());
  uint8_t* end = message.SerializeWithCachedSizesToArray(start);
  
  if (end - start != byte_size)
  {
    ByteSizeConsistencyError(byte_size, message.ByteSize(), static_cast<int>(end - start));
  }

  buf->hasWritten(byte_size);

  int32_t len = sockets::hostToNetwork32(static_cast<int32_t>(buf->readableBytes()));
  buf->prepend(&len, sizeof len);
}

//
// no more google code after this
//

//
// FIXME: merge with RpcCodec
//

namespace
{
  const string kNoErrorStr = "NoError";
  const string kInvalidLengthStr = "InvalidLength";
  const string kCheckSumErrorStr = "CheckSumError";
  const string kInvalidNameLenStr = "InvalidNameLen";
  const string kUnknownMessageTypeStr = "UnknownMessageType";
  const string kParseErrorStr = "ParseError";
  const string kDecryptErrorStr = "DecryptError";
  const string kUncompressErrorStr = "UncompressError";      
  const string kUnknownErrorStr = "UnknownError";
}

const string& ProtobufCodec::errorCodeToString(ErrorCode errorCode)
{
  switch (errorCode)
  {
   case kNoError:
     return kNoErrorStr;
   case kInvalidLength:
     return kInvalidLengthStr;
   case kCheckSumError:
     return kCheckSumErrorStr;
   case kInvalidNameLen:
     return kInvalidNameLenStr;
   case kUnknownMessageType:
     return kUnknownMessageTypeStr;
   case kParseError:
     return kParseErrorStr;
   case kDecryptError:         
     return kDecryptErrorStr;
   case kUncompressError:
     return kUncompressErrorStr;
   default:
     return kUnknownErrorStr;
  }
}

void ProtobufCodec::defaultErrorCallback(const muduo::net::TcpConnectionPtr& conn,
                                         muduo::net::Buffer* buf,
                                         muduo::Timestamp,
                                         ErrorCode errorCode)
{
  LOG_ERROR << "ProtobufCodec::defaultErrorCallback - " << errorCodeToString(errorCode);
  if (conn && conn->connected())
  {
    conn->shutdown();
  }
}

int32_t asInt32(const char* buf)
{
  int32_t be32 = 0;
  ::memcpy(&be32, buf, sizeof(be32));
  return sockets::networkToHost32(be32);
}

void ProtobufCodec::onMessage(const TcpConnectionPtr& conn,
                              Buffer* buf,
                              Timestamp receiveTime)
{
  while (buf->readableBytes() >= kMinMessageLen + kHeaderLen)
  {
    const int32_t len = buf->peekInt32();
    if (len > kMaxMessageLen || len < kMinMessageLen)
    {
      errorCallback_(conn, buf, receiveTime, kInvalidLength);
    }
    else if (buf->readableBytes() >= implicit_cast<size_t>(len + kHeaderLen))
    {
      ErrorCode errorCode = kNoError;
      MessagePtr message = parse(buf->peek()+kHeaderLen, len, &errorCode);
      if (errorCode == kNoError && message)
      {
        messageCallback_(conn, message, receiveTime);
        buf->retrieve(kHeaderLen+len);
      }
      else
      {
        errorCallback_(conn, buf, receiveTime, errorCode);
      }
    }
    else
    {
      break;
    }
  }
}

void ProtobufCodec::send(
    const cs::EnmCmdID eCmdID, 
    const int iMsgSeqID,
    const muduo::net::TcpConnectionPtr& conn,
    const google::protobuf::Message& message)
{
    bool ret = true;
    cs::CSPKG stPkg;
    stPkg.mutable_head()->set_cmdid(eCmdID);
    stPkg.mutable_head()->set_msgseqid(iMsgSeqID);

    std::string sBody;
    ret = message.SerializeToString(&sBody);
    assert(true == ret);// TODO 失败写日志

    if ((int)sBody.size() >= MIN_ZLIB_SIZE)
    {
        stPkg.mutable_head()->set_compresstype(cs::ENM_COMPRESS_TYPE_ZLIB);
        uLongf iCompressLen = sizeof(CompresBuff);
        const int iRetCode = compress((Bytef *) CompresBuff, &iCompressLen,
            (Bytef *) sBody.c_str(), (int)sBody.size());
        assert(iRetCode == Z_OK);// TODO 失败写日志
        sBody.assign(CompresBuff, iCompressLen);
    }
    else
    {
        stPkg.mutable_head()->set_compresstype(cs::ENM_COMPRESS_TYPE_NONE);
    }

    if ((int)sBody.size() > 0)
    {
        uint32_t iXXTeaLen = 0;
        stPkg.mutable_head()->set_encrypttype(cs::ENM_ENCRYPT_TYPE_XXTEA);
        char* pXXTeaData = (char *) CXXTeaMgr::Instance()->xxtea_encrypt((unsigned char *)sBody.c_str(),
                            (int)sBody.size(), (unsigned char *) sInitKey_.c_str(),
                            &iXXTeaLen);
        assert(pXXTeaData != NULL);
        sBody.assign(pXXTeaData, iXXTeaLen);
    }
    else
    {
        stPkg.mutable_head()->set_encrypttype(cs::ENM_ENCRYPT_TYPE_NONE);
    }

    stPkg.set_body(sBody.c_str(), sBody.size());

    muduo::net::Buffer buf;
    fillEmptyBuffer(&buf, stPkg);
    conn->send(&buf);
}

google::protobuf::Message* ProtobufCodec::createMessage(const std::string& typeName)
{
  google::protobuf::Message* message = NULL;
  const google::protobuf::Descriptor* descriptor =
    google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(typeName);
  if (descriptor)
  {
    const google::protobuf::Message* prototype =
      google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
    if (prototype)
    {
      message = prototype->New();
    }
  }
  return message;
}

MessagePtr ProtobufCodec::parse(const char* buf, int len, ErrorCode* error)
{
    MessagePtr message = boost::make_shared<cs::CSPKG>();

    if (message->ParseFromArray(buf, len))
    {
        *error = kNoError;
        const char * pBody = message->body().c_str();         
        int       iBodyLen = (int)message->body().size();

        if (message->head().encrypttype() == cs::ENM_ENCRYPT_TYPE_XXTEA)
        {
            uint32_t iXXTeaLen = 0;
            char * pXXTeaData = NULL;
            pXXTeaData = (char*)CXXTeaMgr::Instance()->xxtea_decrypt((unsigned char *) pBody, iBodyLen, (unsigned char *) sInitKey_.c_str(), &iXXTeaLen);
            if (NULL == pXXTeaData)
            {
                *error = kDecryptError;
                return message;
            }
            else
            {
                pBody    = pXXTeaData;
                iBodyLen =  (int) iXXTeaLen;
            }
        }

        if (message->head().compresstype() == cs::ENM_COMPRESS_TYPE_ZLIB)                
        {
            uLongf iUncompressLen = sizeof(UncompresBuff);
            const int iRetCode = uncompress((Bytef *) UncompresBuff, &iUncompressLen, (Bytef *) pBody, iBodyLen);
            if (Z_OK != iRetCode)
            {
                *error = kUncompressError;            
                return message;
            }
            else
            {
                pBody    = UncompresBuff;
                iBodyLen = (int) iUncompressLen;
            }
        }
        
        message->set_body(pBody, iBodyLen);        
    }
    else
    {
        *error = kParseError;
    }

    return message;
}
