 ///
 /// @file    StrUtils.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-21 15:49:29
 ///
 
#ifndef __ZXK666_STRUTILS_H__
#define __ZXK666_STRUTILS_H__

#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace zxk666
{

int min(int a, int b, int c);

bool isUTF8(const string &one);

vector<string> Str2Vec(const string & str);

}//end of namespace zxk666
#endif
