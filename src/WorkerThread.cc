 ///
 /// @file    WorkerThread.cc
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-22 17:26:03
 ///
 

#include "WorkerThread.h"
#include "Threadpool.h"


using namespace zxk666;

void WorkerThread::run()
{
	_threadpool.threadFunc();
}
