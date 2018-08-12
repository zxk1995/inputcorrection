 ///
 /// @file    Threadpool.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-20 00:28:59
 ///
 
#ifndef __ZXK666_THREADPOOL_H__
#define __ZXK666_THREADPOOL_H__

#include "TaskQueue.h"

#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

namespace zxk666
{

class Task
{
public:
	virtual void process() = 0;
	virtual ~Task() {};
};

class Thread;
class WorkerThread;

class Threadpool
{
	friend WorkerThread;
public:
	Threadpool(size_t threadNum, size_t queSize)
	: _threadNum(threadNum)
	, _queSize(queSize)
	, _taskQue(_queSize)
	, _isExit(false)
	{
		_threads.reserve(_threadNum);
	}

	~Threadpool();

	void start();
	void stop();
	void addTask(Task*);

private:
	void threadFunc();
	Task * getTask();

private:
	size_t _threadNum;
	size_t _queSize;
	vector<shared_ptr<Thread> > _threads;
	TaskQueue _taskQue;
	bool _isExit;
};

}//end of namespace zxk666

#endif
