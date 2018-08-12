 ///
 /// @file    Config.cc
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-21 21:36:22
 ///
 
#include "Config.h"

using namespace zxk666;

Config * Config::_pInstance = NULL;

Config::Config(const string & path)
{
	ifstream is(path);
	string section; 
	string content;
	while(is >> section >> content)
	{
		_configMap.insert(std::make_pair(section, content));
	}
	is.close();
}
