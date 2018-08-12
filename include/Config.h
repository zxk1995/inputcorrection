 ///
 /// @file    Config.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-21 15:58:46
 ///
 
#ifndef __ZXK666_CONFIG_H__
#define __ZXK666_CONFIG_H__

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

namespace zxk666
{

class Config
{
public:
	static Config * getInstance(const string & rhs)
	{
		if(_pInstance)
		{
			_pInstance = new Config(rhs);
		}
		return _pInstance;
	}

	void Delete()
	{
		if(_pInstance)
			delete _pInstance;
	}

	map<string, string> & getConfigMap() { return _configMap; }

private:
	Config(const string &);
	~Config() {}
private:
	static Config * _pInstance;
	string _filepath;
	map<string, string> _configMap;
};

}//end of namespace zxk666

#endif
