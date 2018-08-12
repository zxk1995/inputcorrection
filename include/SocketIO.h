 ///
 /// @file    SocketIO.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-19 23:05:35
 ///
 
#ifndef __ZXK666_SOCKETIO_H__
#define __ZXK666_SOCKETIO_H__

#include <stdio.h>

namespace zxk666
{

class SocketIO
{
public:
	SocketIO(int sockfd);

	size_t readn(char * buf, size_t count);
	size_t writen(const char * buf, size_t count);
	size_t readline(char * buf, size_t max_len);
	int getFd() { return _sockfd; }

private:
	size_t recv_peek(char * buf, size_t count);

private:
	int _sockfd;
};

}//end of namespace zxk666


#endif
