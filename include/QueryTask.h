 ///
 /// @file    QueryTask.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-21 16:06:41
 ///
 
#ifndef __ZXK666_QUERYTASK_H__
#define __ZXK666_QUERYTASK_H__

#include "MyDict.h"
#include "Threadpool.h"
#include "TcpServer.h"
#include "Noncopyable.h"
#include "CacheManager.h"

#include <queue>
#include <json/json.h>

namespace zxk666
{

struct MyResult
{
	MyResult(string word, int freq, int dist)
	: _word(word)
	, _freq(freq)
	, _dist(dist)
	{}

	string _word;
	int _freq;
	int _dist;
};

struct MyCompare
{
	bool operator()(MyResult left, MyResult right)
	{
		if(left._dist != right._dist)
			return left._dist > right._dist;
		else if(left._freq != right._freq) 
			return left._freq < right._freq;
		else 
			return left._word > right._word;
	}
};

class QueryTask
: zxk666::Noncopyable
, public zxk666::Task
{
public:
	QueryTask(const string & query, MyDict & dict, int num, zxk666::TcpConnectionPtr conn, CacheManager & mgr)
	: _queryWord(query.substr(0, query.size() - 1))
	, _dict(dict.getDict())
	, _index(dict.getIndexTable())
	, _num(num)
	, _conn(conn)
	, _cacheMgr(mgr)
	{
		if(!isUTF8(_queryWord))
		{
			for(auto & c : _queryWord)
				c = tolower(c);
		}
	}
void process();

private:
	void queryIndex(const string &);
	int getDistance(const string &);
	void listResult();
	string toJson();
private:
	string _queryWord;
	set<string> _diff;
	vector<pair<string, int>> & _dict;
	map<string, set<int>> & _index;
	size_t _num;
	priority_queue<MyResult, vector<MyResult>, MyCompare> _resultque;
	zxk666::TcpConnectionPtr _conn;
	CacheManager & _cacheMgr;
};

}//end of namespace zxk666

#endif
