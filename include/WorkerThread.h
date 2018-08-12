 ///
 /// @file    WorkerThread.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-20 00:06:38
 ///
 
#ifndef __ZXK666_WORKERTHREAD_H__
#define __ZXK666_WORKERTHREAD_H__

#include "Thread.h"
#include "Mylog.h"

#include <iostream>

using namespace std;

namespace zxk666
{

class Threadpool;

class WorkerThread
: public Thread
{
public:
	WorkerThread(Threadpool & threadpool)
	: _threadpool(threadpool)
	{
		LogWarn("A new workerthread has created.");
		cout << "WorkerThread()" << endl;
	}

	~WorkerThread() { cout << "~WorkerThread()" << endl; }
private:
	void run();
	Threadpool & _threadpool;
};

}//end of namespace zxk666

#endif
