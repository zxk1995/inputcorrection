 ///
 /// @file    Thread.cc
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-22 10:15:38
 ///
 

#include "Thread.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace zxk666; 


Thread::Thread()
: _pthid(0)
, _isRunning(false)
{}


void Thread::start()
{
	pthread_create(&_pthid, NULL, threadFunc, this);
	_isRunning = true;
}

void * Thread::threadFunc(void * arg)
{
	Thread * pthread = static_cast<Thread*>(arg);
	if(pthread)
		pthread->run();// 执行任务

	return NULL;
}

void Thread::join()
{
	pthread_join(_pthid, NULL);
	_isRunning = false;
}

Thread::~Thread()
{
	if(_isRunning)	
	{
		pthread_detach(_pthid);// 将运行的线程交给系统进行托管
		_isRunning = false;
	}
}



