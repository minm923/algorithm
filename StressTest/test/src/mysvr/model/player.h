#ifndef _STRESS_TEST_PLAYER_H_
#define _STRESS_TEST_PLAYER_H_

#include <string>
#include <boost/noncopyable.hpp>
#include <boost/bind.hpp>
#include <boost/scoped_ptr.hpp>
#include <muduo/net/TcpClient.h>
#include <muduo/net/EventLoop.h>
#include <muduo/base/Logging.h>

#include "codec.h"
#include "dispatcher.h"
#include "cs_enum.pb.h"
#include "cs_game.pb.h"
#include "cs_login.pb.h"

struct PlayerData
{
    std::string sPlayerName;
    int         iPlayerID;
    int         iMsgSeqID;
};

class CPlayer : boost::noncopyable
{
public:    
    CPlayer(muduo::net::EventLoop* loop,
            const muduo::net::InetAddress& serverAddr,
            const std::string& account)
    : 
      account_(account),                
      loop_(loop),            
      balanceClient_(loop, serverAddr, "PlayerClient"),
      codec_(boost::bind(&ProtobufDispatcher::onProtobufMessage, &dispatcher_, _1, _2, _3)),
      dispatcher_(boost::bind(&CPlayer::onUnknownMessage, this, _1, _2, _3))
    {
        balanceClient_.setConnectionCallback(
            boost::bind(&CPlayer::onBalanceSvrConnection, this, _1));                
        balanceClient_.setMessageCallback(
            boost::bind(&ProtobufCodec::onMessage, &codec_, _1, _2, _3));

        ReigsterReqCallback();
        
        stPlayerData_.iMsgSeqID = 1;
    }

    void ReigsterReqCallback();

    void onUnknownMessage(
        const muduo::net::TcpConnectionPtr& conn,
        const MessagePtr& message,                                                       
        muduo::Timestamp receiveTime); 

    void onBalanceSvrConnection(const muduo::net::TcpConnectionPtr& conn);

    void onGetGameSvrMinLoadRes(const muduo::net::TcpConnectionPtr&,
                                const boost::shared_ptr<cs::CSGetGameSvrMinLoadRes>& message,
                                muduo::Timestamp);

    void onGameSvrConnection(const muduo::net::TcpConnectionPtr& conn);

    void onLoginRes(const muduo::net::TcpConnectionPtr&,
                                const boost::shared_ptr<cs::CSLoginRes>& message,
                                muduo::Timestamp);

    void start()
    {
        balanceClient_.connect();
    }

    inline int GetNextMsgSeqID()
    { return stPlayerData_.iMsgSeqID++; }

    std::string GetAccount()
    { return account_;}

private:
    std::string account_;
    muduo::net::EventLoop* loop_;    
    muduo::net::TcpClient  balanceClient_;
    ProtobufCodec          codec_;
    ProtobufDispatcher     dispatcher_;
    PlayerData             stPlayerData_;
    boost::scoped_ptr<muduo::net::TcpClient>  pGameClient_;
};

#endif
