#include "PlayerMgr.h"
#include "player.h"
#include <string>
#include <sstream>
#include <muduo/base/Logging.h>
#include <boost/bind.hpp>


int CPlayerMgr::iPlayerAccountStart = 2000;

CPlayerMgr::CPlayerMgr(muduo::net::EventLoop* loop, 
                       const muduo::net::InetAddress& serverAddr,
                       const int iPlayerSum,
                       const int iSeconds)
    : Loop_(loop),        
      iPlayerNum_(0),
      iPlayerSum_(iPlayerSum),
      iSeconds_(iSeconds),
      iPlayerPerS_(iPlayerSum/iSeconds),
      serverAddr_(serverAddr),
      started_(false),
      threadPool_(new muduo::net::EventLoopThreadPool(loop))
{

}


void CPlayerMgr::setThreadNum(const int numThreads)
{
    assert(0 <= numThreads);
    threadPool_->setThreadNum(numThreads);
}

void CPlayerMgr::start()
{
    if (!started_)
    {
        started_ = true;        
        threadPool_->start();

        std::string sAccount;
        std::stringstream ss;

        for (int i=0; i<iPlayerSum_; ++i)
        {
            Loop_->assertInLoopThread();
            muduo::net::EventLoop* ioLoop = threadPool_->getNextLoop();
            
            ss << iPlayerAccountStart++;
            ss >> sAccount;
            ss.clear();

            LOG_INFO << "Player Account : " << sAccount;
            CPlayer* pPlayer = new CPlayer(ioLoop, serverAddr_, sAccount);
            pPlayers_.push_back(pPlayer);
        }

        timerId_ = Loop_->runEvery(1.0,
            boost::bind(&CPlayerMgr::pipeline_start, this));
    }
}

void CPlayerMgr::pipeline_start()
{
    if (iPlayerNum_ >= iPlayerSum_)
    {
        Loop_->cancel(timerId_);
    }
    else
    {
        int iCount = 0;
        while(iPlayerNum_ < iPlayerSum_ && iCount < iPlayerPerS_)
        {
            LOG_INFO << pPlayers_[iPlayerNum_].GetAccount() << " fucking ...";
            pPlayers_[iPlayerNum_++].start();
            ++iCount;
        }
    }
}
