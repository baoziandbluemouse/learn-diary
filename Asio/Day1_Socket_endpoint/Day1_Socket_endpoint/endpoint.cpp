#pragma once
#include "endpoint.h"
#include <boost/asio.hpp>
#include <iostream>
int client_end_point() {
	//假设这是一个客户端，他想要建立socket通信，
	//那么他就要根据对方提供的地址与端口建立一个endpoint
	//Socket是实际的通信通道，endpoint来指定要连接的服务器地址和端口
	std::string raw_ip_address = "127.4.8.1";
	unsigned short port_num = 3333;
	//假设给定了对方的端口号，地址
	boost::system::error_code ec;
	auto ip_address = boost::asio::ip::address::from_string(raw_ip_address, ec);
	//将字符串形式的IP地址解析转换为 boost::asio::ip::address 对象
	//转换过程中如果出现错误(如格式不合法),会将错误信息写入到 ec 参数中
	if (ec.value() != 0) {
		// Provided IP address is invalid. Breaking execution.
		std::cout
			<< "Failed to parse the IP address. Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}
	//接下来将ip地址与端口号绑定到一起
	boost::asio::ip::tcp::endpoint(ip_address, port_num);
}

int server_end_point() {
	//假设这是一个服务端，那么他的endpoint指定的地址与端口，会在bind之后的listen环节被监听
	//
	unsigned short port_num = 3333;
	auto ip_address = boost::asio::ip::address_v4::any();//服务器经常用这种方式绑定自己的地址
}