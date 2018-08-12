 ///
 /// @file    TcpServer.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-21 15:18:27
 ///
 
#ifndef __ZXK666_TCPSERVER_H__
#define __ZXK666_TCPSERVER_H__

#include "Acceptor.h"
#include "EpollPoller.h"
#include "Mylog.h"

#include <string>

using std::string;

namespace zxk666
{

class TcpServer
{
public:
	typedef EpollPoller::EpollCallback TcpServerCallback;
	TcpServer(const string & ip, unsigned short port);
	TcpServer(unsigned short port);
	
	void start();
	void stop();

	void setConnectionCallback(TcpServerCallback cb);
	void setMessageCallback(TcpServerCallback cb);
	void setCloseCallback(TcpServerCallback cb);

private:
	Acceptor _acceptor;
	EpollPoller _poller;

	TcpServerCallback _connectionCallback;
	TcpServerCallback _messageCallback;
	TcpServerCallback _closeCallback;
};

}//end of namespace zxk666

#endif
