#include <muduo/base/AsyncLogging.h>
#include <muduo/base/Logging.h>
#include <muduo/base/Thread.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <boost/shared_ptr.hpp>

#include <boost/bind.hpp>

#include <utility>

#include <stdio.h>
#include <unistd.h>

#include <iostream>
#include <player.h>
#include <PlayerMgr.h>

using namespace muduo;
using namespace muduo::net;

int kRollSize = 500*1000*1000;

boost::scoped_ptr<muduo::AsyncLogging> g_asyncLog;

void asyncOutput(const char* msg, int len)
{
  g_asyncLog->append(msg, len);
}

void setLogging(const char* argv0)
{
  //muduo::Logger::setLogLevel(Logger::INFO);         
  muduo::Logger::setOutput(asyncOutput);
  char name[256];
  strncpy(name, argv0, 256);
  g_asyncLog.reset(new muduo::AsyncLogging(::basename(name), kRollSize));
  g_asyncLog->start();
}

int main(int argc, char* argv[])
{
    setLogging(argv[0]);
    LOG_INFO << "pid = " << getpid() << ", tid = " << CurrentThread::tid();

    EventLoop loop;
    InetAddress listenAddr("192.168.1.240", 11588);
    int iPlayerSum = 200;
    int iSeconds   = 1;

    CPlayerMgr PlayerMgr(&loop, listenAddr, iPlayerSum, iSeconds);
    PlayerMgr.setThreadNum(4);
    PlayerMgr.start();
    loop.loop();

    return 0;    
}

