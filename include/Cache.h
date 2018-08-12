 ///
 /// @file    Cache.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-21 16:32:30
 ///
 
#ifndef __ZXK666_CACHE_H__
#define __ZXK666_CACHE_H__

#include "MutexLock.h"
#include "Noncopyable.h"

#include <vector>
#include <assert.h>
#include <map>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

namespace zxk666
{

struct Node{
	string _query;
	string _jsonfile;
	Node * prev, *next;
	Node(string key, string value)
	: _query(key)
	, _jsonfile(value)
	, prev(NULL)
	, next(NULL)
	{}
};

class Cache
{
	friend class CacheManager;
public:
	Cache(size_t size = 10)
	{
		_size = size;
		_head = NULL;
		_tail = NULL;
		_newCacheCnt = 0;
		_isUpdating = false;
		_isSetting = false;
	}

	string get(string);
	void set(string, string);
	void readFromFile(const string &);
	void writeToFile(const string &);
	void setUpdateTag() { _isUpdating = true; }
	void removeUpdateTag() { _isUpdating = false; }
	void waitSet()
	{
		if(_isSetting)
		{
			while(_isSetting);
		}
	}
	bool getSettinStatus() { return _isSetting; }
private:
	void remove(Node*);
	void setHead(Node*);
private:
	size_t _size;
	map<string, Node* > _cacheMap;
	int _newCacheCnt;
	Node*_head, *_tail;
	Node*_entry;
	bool _isUpdating;
	bool _isSetting;
};

}//end of namespace zxk666

#endif
