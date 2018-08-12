 ///
 /// @file    InetAddress.cc
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-21 22:23:53
 ///
 
#include "InetAddress.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

namespace zxk666
{

InetAddress::InetAddress(short port)
{
	::memset(&_addr, 0, sizeof(_addr));
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(port);
	_addr.sin_addr.s_addr = INADDR_ANY;
}

InetAddress::InetAddress(const char * pIp, short port)
{
	::memset(&_addr, 0, sizeof(_addr));
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(port);
	_addr.sin_addr.s_addr = inet_addr(pIp);
}

InetAddress::InetAddress(const struct sockaddr_in & addr)
: _addr(addr)
{}

const struct sockaddr_in * InetAddress::getSockAddrPtr() const
{
	return &_addr;
}

std::string InetAddress::ip() const
{
	return std::string(inet_ntoa(_addr.sin_addr));
}

unsigned short InetAddress::port() const
{
	return ntohs(_addr.sin_port);
}


}//end of namespace zxk666
