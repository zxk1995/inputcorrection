 ///
 /// @file    MutexLock.cc
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-21 22:32:55
 ///
 
#include "MutexLock.h"

#include <iostream>
using std::cout;
using std::endl;

namespace zxk666
{

MutexLock::MutexLock()
: _isLocking(false)
{
	if(pthread_mutex_init(&_mutex, NULL))
	{
		cout << "error: create mutex error!" << endl;
	}
}

MutexLock::~MutexLock()
{
	if(pthread_mutex_destroy(&_mutex))
	{
		cout << "error: destroy mutex error!" << endl;
	}
}

void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
	_isLocking = true;
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
	_isLocking = false;
}

bool MutexLock::isLocking() const
{
	return _isLocking;
}

pthread_mutex_t * MutexLock::getMutexLockPtr()
{
	return &_mutex;
}

}//end of namespace zxk666
