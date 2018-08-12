 ///
 /// @file    Socket.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-19 22:38:27
 ///
 
#ifndef __ZXK666_SOCKET_H__
#define __ZXK666_SOCKET_H__

#include "Noncopyable.h"

namespace zxk666
{
class InetAddress;
class Socket
: Noncopyable
{
public:
	Socket(int sockfd);
	Socket();
	~Socket();

	void shutdownWrite();
	int fd() const { return _sockfd; }
	
	void nonblock();

	static InetAddress getLocalAddr(int sockfd);
	static InetAddress getPeerAddr(int sockfd);
private:
	int _sockfd;
};

}//end of namespace zxk666

#endif
