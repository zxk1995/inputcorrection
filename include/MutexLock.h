 ///
 /// @file    MutexLock.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-19 22:52:50
 ///
 
#ifndef __ZXK666_MUTEXLOCK_H__
#define __ZXK666_MUTEXLOCK_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace zxk666
{

class MutexLock
: Noncopyable
{
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();

	bool isLocking() const;
	pthread_mutex_t * getMutexLockPtr();

private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock & mutex)
	: _mutex(mutex)
	{
		mutex.lock();
	}

	~MutexLockGuard()
	{
		_mutex.unlock();
	}
private:
	MutexLock & _mutex;
};

}//end of namespcae zxk666

#endif


