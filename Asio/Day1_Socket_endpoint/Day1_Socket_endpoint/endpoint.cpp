#pragma once
#include "endpoint.h"
#include <boost/asio.hpp>
#include <iostream>
int client_end_point()
{
    //��������һ���ͻ��ˣ�����Ҫ����socketͨ�ţ�
    //��ô����Ҫ���ݶԷ��ṩ�ĵ�ַ��˿ڽ���һ��endpoint
    // Socket��ʵ�ʵ�ͨ��ͨ����endpoint��ָ��Ҫ���ӵķ�������ַ�Ͷ˿�
    std::string raw_ip_address = "127.4.8.1";
    unsigned short port_num = 3333;
    //��������˶Է��Ķ˿ںţ���ַ
    boost::system::error_code ec;
    auto ip_address = boost::asio::ip::address::from_string(raw_ip_address, ec);
    //���ַ�����ʽ��IP��ַ����ת��Ϊ boost::asio::ip::address ����
    //ת��������������ִ���(���ʽ���Ϸ�),�Ὣ������Ϣд�뵽 ec ������
    if (ec.value() != 0)
    {
        // Provided IP address is invalid. Breaking execution.
        std::cout << "Failed to parse the IP address. Error code = " << ec.value()
                  << ". Message: " << ec.message();
        return ec.value();
    }
    //��������ip��ַ��˿ںŰ󶨵�һ��
    boost::asio::ip::tcp::endpoint(ip_address, port_num);
    return 0;
}

int server_end_point()
{
    //��������һ������ˣ���ô����endpointָ���ĵ�ַ��˿ڣ�����bind֮���listen���ڱ�����
    unsigned short port_num = 3333;
    auto ip_address = boost::asio::ip::address_v4::any(); //���������������ַ�ʽ���Լ��ĵ�ַ
    boost::asio::ip::tcp::endpoint ep(ip_address, port_num); //��
    return 0;
}

int create_tcp_socket()
{
    //����socket��Ϊ4��������������iocontext��ѡ��Э�飬����socket����socket��
    boost::asio::io_context ioc;                                //������������
    boost::asio::ip::tcp protocol = boost::asio::ip::tcp::v4(); //ѡ��ipv4Э��
    boost::asio::ip::tcp::socket sok(ioc);
    boost::system::error_code ec;
    sok.open(protocol, ec); //��ipv4�򿪣����ʧ�ܾͱ���
    if (ec.value() != 0)
    {
        // Failed to open the socket.
        std::cout << "Failed to open the socket! Error code = " << ec.value()
                  << ". Message: " << ec.message();
        return ec.value();
    }

    //�����ڵ�boost�⣬����ʹ�ø���Ч�Ľ�����ʽ,�������acceptor
    //�����ַ������ǿ��õģ����������ʹ��
}

int create_acceptor_socket()
{
    //���ڷ���ˣ�������socket���ڶ���socket��acceptor�����ڽ����µ�����
    boost::asio::io_context ioc;
    boost::asio::ip::tcp::socket acceptor(
        ioc, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 3333));
    //���ַ�ʽֱ�ӽ�����socket��bind������һ�����ˣ�ֱ��ʵ����listen
    return 0;
}

int bind_acceptor_socket()
{
    //�ɰ汾��endpoint��socket�ķ�ʽ
    //����endpoint��socket���������ɵ�
    unsigned short port_num = 3333;
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::any(), port_num);
    boost::asio::io_context ioc;
    boost::asio::ip::tcp::socket acceptor(ioc, ep.protocol());
    boost::system::error_code ec;
    acceptor.bind(ep, ec);
    if (ec.value() != 0)
    {
        // Failed to bind the acceptor socket. Breaking
        // execution.
        std::cout << "Failed to bind the acceptor socket."
                  << "Error code = " << ec.value() << ". Message: " << ec.message();

        return ec.value();
    }

    return 0;
}

int connect_to_end()
{
    //�ͻ������ӷ�����ָ���Ķ˵��������
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;
    //��������ֱ�Ӽ���������Ķ˵�
    try
    {
        boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string(raw_ip_address),
                                          port_num);
        boost::asio::io_context ios;
        boost::asio::ip::tcp::socket sock(ios, ep.protocol());
        sock.connect(ep);
    }
    catch (boost::system::system_error &e)
    {
        std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what();

        return e.code().value();
    }
}

int dns_connect_to_end()
{
    //��������Ĳ���ip��ַ���������������ǿ���ʹ��asio�ṩ������������������������
    //�������ַ��������ã������˽⼴��
    std::string host = "llfc.hub";
    std::string port_num = "3333";
    boost::asio::io_context ios;
    boost::asio::ip::tcp::resolver::query resolver_query(
        host, port_num, boost::asio::ip::tcp::resolver::query::numeric_service);
    //����һ�����ڲ�ѯ�Ķ���
    //����һ������������
    boost::asio::ip::tcp::resolver resolver(ios);
    try
    {
        boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(resolver_query);
        boost::asio::ip::tcp::socket sok(ios);
        boost::asio::connect(sok, it);
    }
    catch (boost::system::system_error &e)
    {
        std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what();

        return e.code().value();
    }
}

int accept_new_connection()
{
    const int BACKLOG_SIZE = 30;
    //������е�������С
    //�������˷������ڶ�ʱ���ڿ��Դ���������������
    //����������ڴ洢��Щ������������ֵ���δ��������������ܵ����ӡ�
    //ͬ������һ������Ķ˵�,���з���˵�acceptor����һ��socket
    unsigned short port_num = 3333;
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::any(), port_num);
    boost::asio::io_context ios;
    try
    {
        boost::asio::ip::tcp::acceptor acceptor(ios, ep.protocol());
        acceptor.bind(ep);
        //���뻺����еĴ�С
        acceptor.listen(BACKLOG_SIZE);

        boost::asio::ip::tcp::socket sock(ios); //�������ͻ���ͨ��
        acceptor.accept(sock);                  //���յ�����������sock������
    }
    catch (boost::system::system_error &e)
    {
        std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what();

        return e.code().value();
    }
}
