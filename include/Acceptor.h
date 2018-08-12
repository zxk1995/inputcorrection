 ///
 /// @file    Acceptor.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-19 22:29:37
 ///
 
#ifndef __ZXK666_ACCEPTOR_H__
#define __ZXK666_ACCEPTOR_H__

#include "Socket.h"
#include "InetAddress.h"

namespace zxk666
{

class Acceptor
{
public:
	Acceptor(int listenfd, const InetAddress & addr);

	void ready();
	int accept();

	int fd() const {return _listenSock.fd(); }
private:
	void setReuseAddr(bool on);
	void setReusePort(bool on);
	void bind();
	void listen();

private:
	Socket _listenSock;
	InetAddress _addr;
};

}//end fo namespace zxk666

#endif
