 ///
 /// @file    Noncopyable.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-19 22:44:16
 ///
 
#ifndef __ZXK666_NONCOPYABLE_H__
#define __ZXK666_NONCOPYABLE_H__

namespace zxk666
{

class Noncopyable
{
protected:
	Noncopyable() {}
	~Noncopyable() {}
private:
	Noncopyable(const Noncopyable&);
	Noncopyable & operator=(const Noncopyable&);
};

}//end of namespace zxk666

#endif
