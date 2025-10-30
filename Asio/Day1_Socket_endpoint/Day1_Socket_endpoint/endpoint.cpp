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

void use_const_buffer()
{
    std::string buf = "hello,world";
    boost::asio::const_buffer asio_buf(buf.c_str(), buf.length()); //��һ�����׵�ַ���ڶ����ǳ���
    std::vector<boost::asio::const_buffer> buffers_sequence;
    buffers_sequence.push_back(asio_buf);
}

void use_buffer_str()
{
    boost::asio::const_buffers_1 output_buf = boost::asio::buffer("hello world");
}

void use_buffer_array()
{
    const size_t BUF_SIZE_BYTES = 20;
    std::unique_ptr<char[]> buf(new char[BUF_SIZE_BYTES]); // new����׵�ַ����unique_ptr��
    auto input_buf = boost::asio::buffer(static_cast<void *>(buf.get()), BUF_SIZE_BYTES);
    //��һ������buffer����һ��ָ�룬�ڶ�������buffer���ָ������������ռ䣬����������
}

void write_to_socket(boost::asio::ip::tcp::socket &sock)
{
    std::string buf = "hello world";
    std::size_t total_bytes_written = 0;
    //ѭ�����͵ķ���
    //ʹ��wirte_some���������᷵���Լ�д����ֽ���
    while (total_bytes_written != buf.length())
    {
        total_bytes_written += sock.write_some(boost::asio::buffer(
            buf.c_str() + total_bytes_written, buf.length() - total_bytes_written));
        //һ�η����꣬��total_bytes_written����¼ƫ����
    }
}

int send_data_by_write_some()
{
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;
    try
    {
        boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string(raw_ip_address),
                                          port_num);
        boost::asio::io_context ioc;
        boost::asio::ip::tcp::socket sock(ioc, ep.protocol());
        sock.connect(ep);
        write_to_socket(sock);
    }
    catch (boost::system::system_error &e)
    {
        std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what();

        return e.code().value();
    }
    return 0;
}

int send_data_by_send()
{
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;
    try
    {
        boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string(raw_ip_address),
                                          port_num);
        boost::asio::io_context ioc;
        boost::asio::ip::tcp::socket sock(ioc, ep.protocol());
        sock.connect(ep);
        std::string buf = "hello,world";
        int send_length = sock.send(boost::asio::buffer(buf.c_str(), buf.length()));
        // <0 ϵͳ������ =0 �Զ˹ر� >0 ֱ��Ϊbuf.length����
        if (send_length <= 0)
        {
            std::cout << "send failed" << std::endl;
            return 0;
        }
    }
    catch (boost::system::system_error &e)
    {
        std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what();

        return e.code().value();
    }
    return 0;
}

int send_data_by_wirte()
{
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;
    try
    {
        boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string(raw_ip_address),
                                          port_num);
        boost::asio::io_context ioc;
        boost::asio::ip::tcp::socket sock(ioc, ep.protocol());
        sock.connect(ep);
        std::string buf = "hello,world";
        int send_length = boost::asio::write(sock, boost::asio::buffer(buf.c_str(), buf.length()));
        // <0 ϵͳ������ =0 �Զ˹ر� >0 ֱ��Ϊbuf.length����
        if (send_length <= 0)
        {
            std::cout << "send failed" << std::endl;
            return 0;
        }
    }
    catch (boost::system::system_error &e)
    {
        std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what();

        return e.code().value();
    }
    return 0;
}

std::string read_from_socket(boost::asio::ip::tcp::socket &sock)
{
    const unsigned char MESSAGE_SIZE = 7;
    char buf[MESSAGE_SIZE];
    std::size_t total_bytes_read = 0;
    while (total_bytes_read != MESSAGE_SIZE)
    {
        total_bytes_read += sock.read_some(
            boost::asio::buffer(buf + total_bytes_read, MESSAGE_SIZE - total_bytes_read));
    }
    return std::string(buf, total_bytes_read);
}

int read_data_by_read_some()
{
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;
    try
    {
        boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string(raw_ip_address),
                                          port_num);
        boost::asio::io_context ioc;
        boost::asio::ip::tcp::socket sock(ioc, ep.protocol());
        sock.connect(ep);
        read_from_socket(sock);
    }
    catch (boost::system::system_error &e)
    {
        std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what();
        return e.code().value();
    }
    return 0;
}

int read_data_by_receive()
{
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;
    try
    {
        boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string(raw_ip_address),
                                          port_num);
        boost::asio::io_context ioc;
        boost::asio::ip::tcp::socket sock(ioc, ep.protocol());
        sock.connect(ep);
        const unsigned char BUFF_SIZE = 7;
        char buffer_receive[BUFF_SIZE];
        int receive_length = sock.receive(boost::asio::buffer(buffer_receive, BUFF_SIZE));
        if (receive_length <= 0)
        {
            std::cout << "read fail" << std::endl;
        }
    }
    catch (boost::system::system_error &e)
    {
        std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what();
        return e.code().value();
    }
    return 0;
}

int read_data_by_read()
{
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;
    try
    {
        boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string(raw_ip_address),
                                          port_num);
        boost::asio::io_context ioc;
        boost::asio::ip::tcp::socket sock(ioc, ep.protocol());
        sock.connect(ep);
        const unsigned char BUFF_SIZE = 7;
        char buffer_receive[BUFF_SIZE];
        int receive_length =
            boost::asio::read(sock, boost::asio::buffer(buffer_receive, BUFF_SIZE));
        if (receive_length <= 0)
        {
            std::cout << "read fail" << std::endl;
        }
    }
    catch (boost::system::system_error &e)
    {
        std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what();
        return e.code().value();
    }
    return 0;
}
