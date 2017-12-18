#ifndef STRESS_TEST_DISPATCHER_H
#define STRESS_TEST_DISPATCHER_H

#include <muduo/net/Callbacks.h>

#include <google/protobuf/message.h>

#include <map>

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#ifndef NDEBUG
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_base_of.hpp>
#endif

#include "cs_message.pb.h"
#include "cs_enum.pb.h"

#pragma GCC diagnostic ignored "-Wold-style-cast"

typedef boost::shared_ptr<cs::CSPKG> MessagePtr;

class Callback : boost::noncopyable
{
 public:
  virtual ~Callback() {};
  virtual void onMessage(const muduo::net::TcpConnectionPtr&,
                         const MessagePtr& message,
                         muduo::Timestamp) const = 0;
};

template <typename T>
class CallbackT : public Callback
{
#ifndef NDEBUG
  BOOST_STATIC_ASSERT((boost::is_base_of<google::protobuf::Message, T>::value));
#endif
 public:
  typedef boost::function<void (const muduo::net::TcpConnectionPtr&,
                                const boost::shared_ptr<T>& message,
                                muduo::Timestamp)> ProtobufMessageTCallback;

  CallbackT(const ProtobufMessageTCallback& callback)
    : callback_(callback)
  {
  }

  virtual void onMessage(const muduo::net::TcpConnectionPtr& conn,
                         const MessagePtr& message,
                         muduo::Timestamp receiveTime) const
  {
    boost::shared_ptr<cs::CSPKGBody_S2C> bodys2c = boost::make_shared<cs::CSPKGBody_S2C>();
    bool bRet = bodys2c->ParseFromString(message->body());
    assert(bRet == true);

    boost::shared_ptr<T> concrete = boost::make_shared<T>();
    bRet = concrete->ParseFromString(bodys2c->body());
    if (bRet)
    {
        callback_(conn, concrete, receiveTime);
    }
    else
    {
        LOG_INFO << bodys2c->DebugString();
    }
  }

 private:
  ProtobufMessageTCallback callback_;
};

class ProtobufDispatcher
{
 public:
  typedef boost::function<void (const muduo::net::TcpConnectionPtr&,
                                const MessagePtr& message,
                                muduo::Timestamp)> ProtobufMessageCallback;

  explicit ProtobufDispatcher(const ProtobufMessageCallback& defaultCb)
    : defaultCallback_(defaultCb)
  {
  }

  void onProtobufMessage(const muduo::net::TcpConnectionPtr& conn,
                         const MessagePtr& message,
                         muduo::Timestamp receiveTime) const
  {
    cs::EnmCmdID eCmdID = (cs::EnmCmdID) message->head().cmdid();      
    CallbackMap::const_iterator it = callbacks_.find(eCmdID);
    if (it != callbacks_.end())
    {
      it->second->onMessage(conn, message, receiveTime);
    }
    else
    {
      defaultCallback_(conn, message, receiveTime);
    }
  }

  template<typename T>
  void registerMessageCallback(const cs::EnmCmdID eCmdID, const typename CallbackT<T>::ProtobufMessageTCallback& callback)
  {
    boost::shared_ptr<CallbackT<T> > pd(new CallbackT<T>(callback));
    callbacks_[eCmdID] = pd;
  }

 private:
  typedef std::map<const cs::EnmCmdID, boost::shared_ptr<Callback> > CallbackMap;

  CallbackMap callbacks_;
  ProtobufMessageCallback defaultCallback_;
};
#endif  // STRESS_TEST_DISPATCHER_H

