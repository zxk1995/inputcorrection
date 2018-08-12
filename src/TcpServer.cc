 ///
 /// @file    TcpServer.cc
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-22 16:26:05
 ///
 
#include "TcpServer.h"
#include "InetAddress.h"
#include "SocketUtil.h"
#include <iostream>
using std::cout;
using std::endl;


namespace zxk666
{

TcpServer::TcpServer(const string & ip, unsigned short port)
: _acceptor(createSocketFd(), InetAddress(ip.c_str(), port))
, _poller(_acceptor)
{
}

void TcpServer::start()
{
	_acceptor.ready();
	_poller.setConnectionCallback(_connectionCallback);
	_poller.setMessageCallback(_messageCallback);
	_poller.setCloseCallback(_closeCallback);
	_poller.loop();
}

void TcpServer::stop()
{
	_poller.unloop();
}
	
void TcpServer::setConnectionCallback(TcpServerCallback cb)
{	_connectionCallback = cb;	}
void TcpServer::setMessageCallback(TcpServerCallback cb)
{	_messageCallback = cb;	}
void TcpServer::setCloseCallback(TcpServerCallback cb)
{	_closeCallback = cb;	}

}//end of namespace zxk666
