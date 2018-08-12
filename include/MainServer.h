 ///
 /// @file    MainServer.h
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-21 17:35:32
 ///
 
#ifndef __ZXK666_MAINSERVER_H__
#define __ZXK666_MAINSERVER_H__

#include "CacheManager.h"
#include "TcpServer.h"
#include "Threadpool.h"
#include "MyDict.h"
#include "QueryTask.h"
#include "Config.h"
#include "TimerThread.h"
#include "Mylog.h"

#include <iostream>
#include <memory>
#include <string>

void onConnection(const zxk666::TcpConnectionPtr&);
void onMessage(const zxk666::TcpConnectionPtr&);
void onClose(const zxk666::TcpConnectionPtr&);

namespace zxk666
{

class MainServer
{
	friend void onConnection(const zxk666::TcpConnectionPtr&);
	friend void onMessage(const zxk666::TcpConnectionPtr&);
	friend void onClose(const zxk666::TcpConnectionPtr&);

public:
	MainServer(const string & configPath)
	: _configMap(Config::getInstance(configPath)->getConfigMap())
	//, _threadpool(std::stoi(_configMap["ThreadpoolCap"]), std::stoi(_configMap["TaskQueSize"]))
	, _threadpool(4, 5)
	//, _tcpserver(_configMap["ServerIP"], (stoi(_configMap["Port"])))
	, _tcpserver("192.168.227.128", 9999)
	//, _cacheMgr(_configMap["cachePath"])
	, _cacheMgr("../data/Cache")
	, _timer(5, 5, bind(&CacheManager::periodcUpdate, &_cacheMgr))
	{}

	void start();
	void stop();

private:
	  std::map<string, string> & _configMap;
	  zxk666::Threadpool _threadpool;
	  zxk666::TcpServer _tcpserver;
	  zxk666::MyDict* _dict;
	  zxk666::CacheManager _cacheMgr;
	  zxk666::TimerThread _timer;
};

}//end of namespace zxk666

#endif
