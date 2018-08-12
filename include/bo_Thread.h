 ///
 /// @file    bo_Thread.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-21 15:08:57
 ///
 
#ifndef __ZXK666_BO_THREAD_H__
#define __ZXK666_BO_THREAD_H__

#include "Noncopyable.h"

#include <pthread.h>
#include <functional>
using std::function;

namespace zxk666
{

class boThread
: Noncopyable
{
	using boThreadCallback = function<void()>;
public:
	boThread(boThreadCallback && cb);
	~boThread();
	
	void start();
	void join();

	bool isRunning() const { return _isRunning; }

private:
	static void * threadFunc(void *);
private:
	pthread_t _pthid;
	bool _isRunning;
	boThreadCallback _cb;
};

}//end of namespace zxk666

#endif
