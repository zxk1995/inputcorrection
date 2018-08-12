 ///
 /// @file    MyDict.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-21 15:37:37
 ///
 
#ifndef __ZXK666_MYDICT_H__
#define __ZXK666_MYDICT_H__

#include "StrUtils.h"

#include <map>
#include <set>

using std::map;
using std::set;
using std::cout;
using std::endl;
using std::string;

namespace zxk666
{

class MyDict
{
public:
	static MyDict * getInstance(const string & p1, const string & p2)
	{
		if(!_pInstance)
		{
			_pInstance = new MyDict(p1, p2);
		}
		return _pInstance;
	}
	void init();
	void initDict();
	void initIndex();

	vector<pair<string, int>> & getDict() { return _dict; }
	map<string, set<int>> & getIndexTable() { return _index; }
	
	void list();//for test
	static void Delete()
	{
		if(_pInstance)
			delete _pInstance;
	}
private:
	MyDict(const string & cnPath, const string & enPath)
	: _enPath(enPath)
	, _cnPath(cnPath)
	{}

	~MyDict() {}
private:
	string _enPath;
	string _cnPath;
	static MyDict * _pInstance;
	vector<pair<string, int> > _dict;
	map<string, set<int> > _index;
};

}//end of namespace zxk666

#endif
