#ifndef _STRESS_TEST_PLAYERMGR_H
#define _STRESS_TEST_PLAYERMGR_H

#include <boost/noncopyable.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/scoped_ptr.hpp>

#include <muduo/net/EventLoopThreadPool.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>

class CPlayer;

class CPlayerMgr : boost::noncopyable
{
public:
    explicit CPlayerMgr(muduo::net::EventLoop* loop,
                        const muduo::net::InetAddress& serverAddr,            
                        const int iPlayerSum,
                        const int iSeconds);

    void setThreadNum(const int numThreads);

    void start();

private:    

    void pipeline_start();

    static int iPlayerAccountStart;

    muduo::net::EventLoop* Loop_;
    int iPlayerNum_;
    const int iPlayerSum_;
    const int iSeconds_;
    const int iPlayerPerS_;
    const muduo::net::InetAddress serverAddr_;
    bool started_;
    boost::scoped_ptr<muduo::net::EventLoopThreadPool> threadPool_;
    muduo::net::TimerId timerId_;
    boost::ptr_vector<CPlayer> pPlayers_;
};

#endif
