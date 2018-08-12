 ///
 /// @file    TimerThread.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-21 15:13:52
 ///
 
#ifndef __ZXK666_TIMERTHREAD_H__
#define __ZXK666_TIMERTHREAD_H__

#include "Timer.h"
#include "bo_Thread.h"

#include <functional>

namespace zxk666
{

class TimerThread
{
public:
	using TimerCallback = std::function<void()>;
	TimerThread(int, int, TimerCallback && cb);
	~TimerThread();

	void start();
	void stop();

private:
	Timer _timer;
	boThread _subThread;
	bool _isStarted;
};

}//end of namespace zxk666

#endif
