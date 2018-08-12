 ///
 /// @file    Thread.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-20 00:02:12
 ///
 
#ifndef __ZXK666_THREAD_H__
#define __ZXK666_THREAD_H__

#include "Noncopyable.h"
#include "Mylog.h"

#include <string>

using std::string;

namespace zxk666
{

class Thread
: Noncopyable
{
public:
	Thread();
	virtual ~Thread();

	void start();
	void join();

	bool isRunning() const { return _isRunning; }

private:
	virtual void run() = 0;
	static void * threadFunc(void *);

private:
	pthread_t _pthid;
	bool _isRunning;
};

}//end of namespace zxk666


#endif
