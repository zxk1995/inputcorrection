 ///
 /// @file    TcpConnection.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-19 23:10:07
 ///
 
#ifndef __ZXK666_TCPCONNECTION_H__
#define __ZXK666_TCPCONNECTION_H__

#include "Noncopyable.h"
#include "InetAddress.h"
#include "Socket.h"
#include "SocketIO.h"
#include "Mylog.h"

#include <string>
#include <memory>
#include <functional>

namespace zxk666
{

class EpollPoller;
class TcpConnection;
typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;

class TcpConnection
: Noncopyable
, public std::enable_shared_from_this<TcpConnection>
{
	friend class QueryTask;
public:
	typedef std::function<void(const TcpConnectionPtr &)> TcpConnectionCallback;
	TcpConnection(int sockfd, EpollPoller * loop);
	~TcpConnection();

	std::string receive();
	void send(const std::string & msg);
	void sendInLoop(const std::string & msg);
	void shutdown();

	std::string toString();

	void setConnectionCallback(TcpConnectionCallback cb);
	void setMessageCallback(TcpConnectionCallback cb);
	void setCloseCallback(TcpConnectionCallback cb);

	void handleConnectionCallback();
	void handleMessageCallback();
	void handleCloseCallback();
	int getSockfd() { return _sockIO.getFd(); }
	EpollPoller * getLoop() { return _loop; }

private:
	Socket _sockfd;
	SocketIO _sockIO;
	const InetAddress _localAddr;
	const InetAddress _peerAddr;
	bool _isShutdownWrite;
	EpollPoller * _loop;

	TcpConnectionCallback _onConnectionCb;
	TcpConnectionCallback _onMessageCb;
	TcpConnectionCallback _onCloseCb;
};

}//end of namespace zxk666

#endif


