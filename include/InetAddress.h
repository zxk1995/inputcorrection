 ///
 /// @file    InetAddress.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-19 22:47:26
 ///
 
#ifndef __ZXK666_INETADDRESS_H__
#define __ZXK666_INETADDRESS_H__

#include <netinet/in.h>
#include <string>

namespace zxk666
{

class InetAddress
{
public:
	InetAddress(short port);

	InetAddress(const char * pIp, short port);

	InetAddress(const struct sockaddr_in & addr);
	
	const struct sockaddr_in * getSockAddrPtr() const;
	std::string ip() const;
	unsigned short port() const;

private:
	struct sockaddr_in _addr;
};

}//end of namespace zxk666

#endif
