#ifndef STRESS_TEST_CODEC_H
#define STRESS_TEST_CODEC_H

#include <muduo/net/Buffer.h>
#include <muduo/net/TcpConnection.h>

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

#include <google/protobuf/message.h>

#include <string>
#include "cs_message.pb.h"
#include "cs_enum.pb.h"

typedef boost::shared_ptr<cs::CSPKG> MessagePtr;

class ProtobufCodec : boost::noncopyable
{
 public:

  enum ErrorCode
  {
    kNoError = 0,
    kInvalidLength,
    kCheckSumError,
    kInvalidNameLen,
    kUnknownMessageType,
    kParseError,
    kDecryptError,
    kUncompressError,
  };

  typedef boost::function<void (const muduo::net::TcpConnectionPtr&,
                                const MessagePtr&,
                                muduo::Timestamp)> ProtobufMessageCallback;

  typedef boost::function<void (const muduo::net::TcpConnectionPtr&,
                                muduo::net::Buffer*,
                                muduo::Timestamp,
                                ErrorCode)> ErrorCallback;

  explicit ProtobufCodec(const ProtobufMessageCallback& messageCb)
    : messageCallback_(messageCb),
      errorCallback_(defaultErrorCallback)
  {
  }

  ProtobufCodec(const ProtobufMessageCallback& messageCb, const ErrorCallback& errorCb)
    : messageCallback_(messageCb),
      errorCallback_(errorCb)
  {
  }

  void onMessage(const muduo::net::TcpConnectionPtr& conn,
                 muduo::net::Buffer* buf,
                 muduo::Timestamp receiveTime);

  void send(const cs::EnmCmdID eCmdID, const int iMsgSeqID,
            const muduo::net::TcpConnectionPtr& conn,
            const google::protobuf::Message& message);

  static const muduo::string& errorCodeToString(ErrorCode errorCode);
  static void fillEmptyBuffer(muduo::net::Buffer* buf, const google::protobuf::Message& message);
  static google::protobuf::Message* createMessage(const std::string& type_name);
  static MessagePtr parse(const char* buf, int len, ErrorCode* errorCode);

 private:
  static void defaultErrorCallback(const muduo::net::TcpConnectionPtr&,
                                   muduo::net::Buffer*,
                                   muduo::Timestamp,
                                   ErrorCode);

  ProtobufMessageCallback messageCallback_;
  ErrorCallback errorCallback_;

  const static std::string sInitKey_;

  const static int MAX_MSG_BUFF_SIZE = 32768;
  static char  UncompresBuff[MAX_MSG_BUFF_SIZE]; 
  static char  CompresBuff[MAX_MSG_BUFF_SIZE]; 

  const static int MIN_ZLIB_SIZE = 256;

  const static int kHeaderLen = sizeof(int32_t);
  const static int kMinMessageLen = kHeaderLen; 
  const static int kMaxMessageLen = 64*1024*1024; // same as codec_stream.h kDefaultTotalBytesLimit
};

#endif  // STRESS_TEST_CODEC_H
