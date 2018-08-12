 ///
 /// @file    Timer.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-20 00:22:55
 ///
 
#ifndef __ZXK666_TIMER_H__
#define __ZXK666_TIMER_H__

#include <functional>

namespace zxk666
{

class Timer
{
public:
	using TimerCallback = std::function<void()>;

	Timer(int initialTime, int intervalTime, TimerCallback && cb);

	~Timer();

	void start();
	void stop();

private:
	int createTimerFd();
	void setTimerfd(int initialTime, int intervalTime);
	void handleRead();

private:
	int _fd;
	int _initialTime;
	int _intervalTime;
	TimerCallback _cb;
	bool _isStarted;
};

}//end of namespace zxk666

#endif
