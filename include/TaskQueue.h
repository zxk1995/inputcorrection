 ///
 /// @file    TaskQueue.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-20 00:13:42
 ///
 
#ifndef __ZXK666_TASKQUEUE_H__
#define __ZXk666_TASKQUEUE_H__

#include "MutexLock.h"
#include "Condition.h"

#include <queue>

namespace zxk666
{

class Task;

class TaskQueue
{
public:
	TaskQueue(size_t queSize)
	: _queSize(queSize)
	, _mutex()
	, _notFull(_mutex)
	, _notEmpty(_mutex)
	, _flag(true)
	{}

	void push(Task*);
	Task * pop();

	bool empty() const
	{ return _que.size() == 0; }

	bool full() const
	{ return _que.size() == _queSize; }

	void wakeup() 
	{
		_flag = false;
		_notEmpty.notifyAll();
	}

private:
	size_t _queSize;
	std::queue<Task*> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	bool _flag;
};

}//end of namespace zxk666

#endif
