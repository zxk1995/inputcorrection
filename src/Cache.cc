 ///
 /// @file    Cache.cc
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-22 19:42:50
 ///
 
#include "Cache.h"

using namespace zxk666;


string Cache::get(string key)
{
	auto it = _cacheMap.find(key);
	if(it != _cacheMap.end())
	{
		Node* node = it->second;
		remove(node);
		setHead(node);
		return node->_jsonfile;
	}
	else
		return string();
}

void Cache::set(string key, string value)
{
	if(_isUpdating)
	{
		while(_isUpdating);
	}
	_isSetting = true;
	auto it = _cacheMap.find(key);
	if(it != _cacheMap.end())
	{
		Node* node = it->second;
		node->_jsonfile = value;
		remove(node);
		setHead(node);
	}else{
		Node* newNode = new Node(key, value);
		if(_cacheMap.size() == _size)
		{
			auto toDel = _cacheMap.find(_tail->_query);
			Node* todel = _tail;
			remove(_tail);
			delete todel;
			_cacheMap.erase(toDel);
		}
		++_newCacheCnt;
		setHead(newNode);
		_cacheMap[key] = newNode;
	}
	_isSetting = false;
}

void Cache::remove(Node * node)
{
	if(node->prev != NULL)
	{
		node->prev->next = node->next;
	}else{
		_head = node->next;
	}
	if(node->next != NULL)
	{
		node->next->prev = node->prev;
	}else{
		_tail = node->prev;
	}
}

void Cache::setHead(Node* node)
{
	node->next = _head;
	node->prev = NULL;
	if(_head != NULL)
	{
		_head->prev = node;
	}
	_head = node;
	if(_tail == NULL)
	{
		_tail = _head;
	}
}

void Cache::writeToFile(const string & cachePath)
{
	ofstream os(cachePath);
	Node* cur = _tail;
	while(cur != _head->prev)
	{
		os << cur->_query << " " << cur->_jsonfile << endl;
		cur = cur->prev;
	}
	os.close();
}

void Cache::readFromFile(const string & cachePath)
{
	ifstream is(cachePath);
	string key;
	string value;
	while(is >> key >> value)
	{
		set(key, value);
	}
	_newCacheCnt = 0;
	is.close();
}


