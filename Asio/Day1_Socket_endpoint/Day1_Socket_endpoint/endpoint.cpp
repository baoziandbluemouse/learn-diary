#pragma once
#include "endpoint.h"
#include <boost/asio.hpp>
#include <iostream>
int client_end_point() {
	//��������һ���ͻ��ˣ�����Ҫ����socketͨ�ţ�
	//��ô����Ҫ���ݶԷ��ṩ�ĵ�ַ��˿ڽ���һ��endpoint
	//Socket��ʵ�ʵ�ͨ��ͨ����endpoint��ָ��Ҫ���ӵķ�������ַ�Ͷ˿�
	std::string raw_ip_address = "127.4.8.1";
	unsigned short port_num = 3333;
	//��������˶Է��Ķ˿ںţ���ַ
	boost::system::error_code ec;
	auto ip_address = boost::asio::ip::address::from_string(raw_ip_address, ec);
	//���ַ�����ʽ��IP��ַ����ת��Ϊ boost::asio::ip::address ����
	//ת��������������ִ���(���ʽ���Ϸ�),�Ὣ������Ϣд�뵽 ec ������
	if (ec.value() != 0) {
		// Provided IP address is invalid. Breaking execution.
		std::cout
			<< "Failed to parse the IP address. Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}
	//��������ip��ַ��˿ںŰ󶨵�һ��
	boost::asio::ip::tcp::endpoint(ip_address, port_num);
}

int server_end_point() {
	//��������һ������ˣ���ô����endpointָ���ĵ�ַ��˿ڣ�����bind֮���listen���ڱ�����
	//
	unsigned short port_num = 3333;
	auto ip_address = boost::asio::ip::address_v4::any();//���������������ַ�ʽ���Լ��ĵ�ַ
}