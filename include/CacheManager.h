 ///
 /// @file    CacheManager.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-21 16:25:55
 ///
 
#ifndef __ZXK666_CACHEMANAGER_H__
#define __ZXK666_CACHEMANAGER_H__

#include "Cache.h"
#include "Mylog.h"

namespace zxk666
{

class CacheManager
{
public:
	CacheManager(const string & path)
	: _cacheDiskPath(path)
	{}
	void initCache();
	Cache & getCache();
	string & getPath() { return _cacheDiskPath; }
	void periodcUpdate();
private:
	vector<Cache> _cacheList;
	map<pthread_t, size_t> _Thread2Cache;
	string _cacheDiskPath;
};

}//end of namespace zxk666

#endif
