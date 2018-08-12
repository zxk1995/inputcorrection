 ///
 /// @file    StrUtils.cc
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-21 23:36:50
 ///
 
#include "StrUtils.h"

using namespace std;

namespace zxk666
{

int min(int a, int b, int c)
{
	int tmp = a < b ? a : b;
	return tmp < c ? tmp : c;
}

bool isUTF8(const string & one)
{
	return (one[0] & 0xe0 && one[1] & 0x80 && one[2] & 0x80);
}

vector<string> Str2Vec(const string & rhs)
{
	vector<string> ret;
	if(isUTF8(rhs))
	{
		for(string::size_type col = 0; col <rhs.size(); col +=3)
		{
			string sing = rhs.substr(col, 3);
			ret.push_back(sing);
		}
	}else{
		for(string::size_type col = 0;col <rhs.size(); ++col)
		{
			string sing = rhs.substr(col, 1);
			ret.push_back(sing);
		}
	}
	return ret;
}

}//end of namespace zxk666
