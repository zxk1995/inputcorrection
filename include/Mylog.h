 ///
 /// @file    Mylog.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-19 23:51:42
 ///
 
#ifndef __ZXK666_MYLOG_H__
#define __ZXK666_MYLOG_H__

#include <log4cpp/Category.hh>
#include <iostream>
#include <string>
using std::cout;
using std::endl;

using namespace log4cpp;

namespace zxk666
{

class Mylog
{
public:
	static Mylog * getInstance();
	static void destroy();
	
	void warn(const char * msg);
	void info(const char * msg);
	void error(const char * msg);
	void debug(const char * msg);

private:
	Mylog();
	~Mylog();

private:
	Category & _root;
	static Mylog * _pInstance;
};

}//end of namespace zxk666

#define prefix(msg) string("[").append(__FILE__)\
		.append(":").append(__FUNCTION__)\
		.append(":").append(std::to_string(__LINE__))\
		.append("]").append(msg).c_str()

#define LogWarn(msg) zxk666::Mylog::getInstance()->warn(prefix(msg))
#define LogInfo(msg) zxk666::Mylog::getInstance()->info(prefix(msg))
#define LogError(msg) zxk666::Mylog::getInstance()->error(prefix(msg))
#define LogDebug(msg) zxk666::Mylog::getInstance()->debug(prefix(msg))


#endif
