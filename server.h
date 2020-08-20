#pragma once
#ifndef CHATROOM_SERVER_H
#define CHATROOM_SERVER_H

#include <string>

#include "common.h"

using namespace std;

// 服务端类，用来处理客户端请求
class Server {

public:
	// 无参数构造函数
	Server();
	~Server();
	// 初始化服务器端设置
	void Init();

	// 关闭服务
	void Close();

	// 启动服务端
	void Start();

private:
	// 广播消息给所有客户端
	int SendBroadcastMessage(int clientfd);

	// 服务器端serverAddr信息
	struct sockaddr_in serverAddr;
	/*sockaddr_in在头文件#include<netinet/in.h>或#include <arpa/inet.h>中定义，该结构体解决了sockaddr的缺陷，把port和addr 分开储存在两个变量中
	struct sockaddr_in{
		sa_family_t sin_family;//地址簇（Address Family）
		uint16_t	sin_port;//16位TCP/UDP端口号
		struct in_addr sin_addr;//32位IP地址
		char sin_zero[8];//不使用
	}
	
	 sin_port和sin_addr都必须是网络字节序（NBO），一般可视化的数字都是主机字节序（HBO）
	*/

	//创建监听的socket
	int listener;

	// epoll_create创建后的返回值
	int epfd;

	// 客户端列表
	list<int> clients_list;
};
#endif
