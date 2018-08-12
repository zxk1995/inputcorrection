 ///
 /// @file    Threadpool.cc
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-22 16:55:09
 ///
 
#include "Threadpool.h"

#include "WorkerThread.h"

#include <unistd.h>

using namespace zxk666;


void Threadpool::start()
{
	for(size_t idx = 0; idx < _threadNum; ++idx)
	{
		shared_ptr<Thread> pThread(new WorkerThread(*this));
		_threads.push_back(std::move(pThread));
	}

	for(auto & pThread : _threads)
	{
		pThread->start();
	}
}

//运行在主线程中
void Threadpool::stop()
{
	if(!_isExit) {
		while(!_taskQue.empty()) {
			::sleep(1);
			cout << ">>> Threadpool sleep 1 s" << endl;
		}

		_isExit = true;
		cout << ">>> Threadpool -> stop: _isExit = " << _isExit << endl;

		_taskQue.wakeup();

		for(auto & pthread : _threads) {
			pthread->join();
		}
	}
}

Threadpool::~Threadpool()
{
	if(!_isExit) {
		stop();
	}
}


void Threadpool::addTask(Task * ptask)
{
	_taskQue.push(ptask);
}

Task * Threadpool::getTask()
{
	return _taskQue.pop();
}

//子线程要做的事情
void Threadpool::threadFunc()
{
	while(!_isExit)
	{
		Task * ptask = getTask();
		if(ptask){
			ptask->process();//执行任务的时间不确定
            delete ptask;
        }
	}
}
