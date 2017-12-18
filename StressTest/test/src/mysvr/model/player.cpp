#include <muduo/net/InetAddress.h>
#include "player.h"
#include "cs_enum.pb.h"
#include "cs_game.pb.h"

void CPlayer::onUnknownMessage(
        const muduo::net::TcpConnectionPtr& conn,
        const MessagePtr& message,                                                       
        muduo::Timestamp receiveTime)
{
    LOG_INFO << "onUnknownMessage: " << message->head().cmdid();
}

void CPlayer::ReigsterReqCallback()
{
        dispatcher_.registerMessageCallback<cs::CSGetGameSvrMinLoadRes>(
            cs::CS_GET_GAME_SVR_MIN_LOAD_RES,                
            boost::bind(&CPlayer::onGetGameSvrMinLoadRes, this, _1, _2, _3));
        
        dispatcher_.registerMessageCallback<cs::CSLoginRes>(
            cs::CS_LOGIN_RES,                
            boost::bind(&CPlayer::onLoginRes, this, _1, _2, _3));
}

void CPlayer::onBalanceSvrConnection(const muduo::net::TcpConnectionPtr& conn)
{
    if (conn->connected())
    {
        cs::CSGetGameSvrMinLoadReq stReq;
        codec_.send(cs::CS_GET_GAME_SVR_MIN_LOAD_REQ, GetNextMsgSeqID(), conn, stReq);
    }
    else
    {
        LOG_INFO << "BalanceSvr disconnect...";
        //loop_->quit();
    }
}

void CPlayer::onGetGameSvrMinLoadRes(const muduo::net::TcpConnectionPtr&,
                                const boost::shared_ptr<cs::CSGetGameSvrMinLoadRes>& message,
                                muduo::Timestamp)
{
    LOG_INFO << "Get GameSvr IP PORT" << message->DebugString().c_str();
    std::string GameSvrIP = message->hosts(0).ip();
    int iGameSvrPort      = message->hosts(0).port();
    muduo::net::InetAddress listenAddr(GameSvrIP, (uint16_t)iGameSvrPort);

    pGameClient_.reset(new muduo::net::TcpClient(loop_, listenAddr, "PlayerClient"));
    pGameClient_->setConnectionCallback(
        boost::bind(&CPlayer::onGameSvrConnection, this, _1));
    pGameClient_->setMessageCallback(
        boost::bind(&ProtobufCodec::onMessage, &codec_, _1, _2, _3));
    LOG_INFO << account_ << " start tcp...";
    pGameClient_->connect();
}

void CPlayer::onGameSvrConnection(const muduo::net::TcpConnectionPtr& conn)
{
    if (conn->connected())
    {
        LOG_INFO<< account_ << " end tcp..." << conn->localAddress().toIpPort();

        cs::CSLoginReq stReq;
        stReq.set_playeraccount(account_);
        stReq.set_token("gaomin");
        stReq.mutable_versionresource()->set_gameversion("0.8.0");
        stReq.mutable_versionresource()->set_ostype("ANDROID");
        stReq.mutable_versionresource()->set_chanmerchant("Default");
        stReq.set_plattype("XLCW");
        stReq.set_playerpasswd("123");
        
        LOG_INFO << account_ << " start login...";
        codec_.send(cs::CS_LOGIN_REQ, GetNextMsgSeqID(), conn, stReq);
    }
    else
    {
        LOG_INFO << account_<< "GameSvr disconnect...";
        //loop_->quit();
    }
}


void CPlayer::onLoginRes(const muduo::net::TcpConnectionPtr&,
                                const boost::shared_ptr<cs::CSLoginRes>& message,
                                muduo::Timestamp)
{
    LOG_INFO << account_ << " end login...";
    LOG_INFO << message->DebugString().c_str();
}

