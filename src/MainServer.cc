 ///
 /// @file    MainServer.cc
 /// @author  zxk666(1332971744@qq.com)
 /// @date    2018-07-22 05:03:25
 ///
 
#include "MainServer.h"

using namespace zxk666;

Threadpool *g_threadpool = NULL;
CacheManager *g_cacheMgr = NULL;

void onConnection(const zxk666::TcpConnectionPtr & conn)
{
	cout << "hello" << endl;
	cout << conn->toString() << endl;
	string loginfo = conn->toString() + " The link was established.";
	LogInfo(loginfo);
	conn->send("Connection Established.");
}

void onMessage(const zxk666::TcpConnectionPtr & conn)
{
	string query(conn->receive());
	QueryTask * ptask(new QueryTask(query, *MyDict::getInstance("", ""), 5, conn, *g_cacheMgr));
	cout << "QueryTask Added. sockIO = " << conn->getSockfd() << " " << ptask << endl;
	g_threadpool->addTask(ptask);
}

void onClose(const TcpConnectionPtr & conn)
{
	string loginfo = conn->toString() + " close.";
	LogInfo(loginfo);
	cout << conn->toString() << " closed" << endl;
}

void MainServer::start()
{
	LogInfo("Server Startd");
	//_dict = MyDict::getInstance(_configMap["cnDictPath"], _configMap["_enDictPath"]);
	_dict = MyDict::getInstance("../data/cnDict.dat", "../data/enDict.dat");
	_dict->init();
	_cacheMgr.initCache();
	_timer.start();
	g_threadpool = &_threadpool;
	g_cacheMgr = &_cacheMgr;
	_threadpool.start();
	_tcpserver.setConnectionCallback(&::onConnection);
	_tcpserver.setMessageCallback(&::onMessage);
	_tcpserver.setCloseCallback(&::onClose);
	_tcpserver.start();
}

void MainServer::stop()
{
	_dict->Delete();
	Config::getInstance("asd")->Delete();
	_tcpserver.stop();
	_threadpool.stop();
}


