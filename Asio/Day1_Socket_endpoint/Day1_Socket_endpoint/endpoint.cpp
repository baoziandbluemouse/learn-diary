#pragma once
#include "endpoint.h"
#include <boost/asio.hpp>
#include <iostream>
int client_end_point()
{
    //假设这是一个客户端，他想要建立socket通信，
    //那么他就要根据对方提供的地址与端口建立一个endpoint
    // Socket是实际的通信通道，endpoint来指定要连接的服务器地址和端口
    std::string raw_ip_address = "127.4.8.1";
    unsigned short port_num = 3333;
    //假设给定了对方的端口号，地址
    boost::system::error_code ec;
    auto ip_address = boost::asio::ip::address::from_string(raw_ip_address, ec);
    //将字符串形式的IP地址解析转换为 boost::asio::ip::address 对象
    //转换过程中如果出现错误(如格式不合法),会将错误信息写入到 ec 参数中
    if (ec.value() != 0)
    {
        // Provided IP address is invalid. Breaking execution.
        std::cout << "Failed to parse the IP address. Error code = " << ec.value()
                  << ". Message: " << ec.message();
        return ec.value();
    }
    //接下来将ip地址与端口号绑定到一起
    boost::asio::ip::tcp::endpoint(ip_address, port_num);
    return 0;
}

int server_end_point()
{
    //假设这是一个服务端，那么他的endpoint指定的地址与端口，会在bind之后的listen环节被监听
    unsigned short port_num = 3333;
    auto ip_address = boost::asio::ip::address_v4::any(); //服务器经常用这种方式绑定自己的地址
    boost::asio::ip::tcp::endpoint ep(ip_address, port_num); //绑定
    return 0;
}

int create_tcp_socket()
{
    //创建socket分为4步，创建上下文iocontext，选择协议，生成socket，打开socket。
    boost::asio::io_context ioc;                                //创建了上下文
    boost::asio::ip::tcp protocol = boost::asio::ip::tcp::v4(); //选择ipv4协议
    boost::asio::ip::tcp::socket sok(ioc);
    boost::system::error_code ec;
    sok.open(protocol, ec); //用ipv4打开，如果失败就报错
    if (ec.value() != 0)
    {
        // Failed to open the socket.
        std::cout << "Failed to open the socket! Error code = " << ec.value()
                  << ". Message: " << ec.message();
        return ec.value();
    }

    //在现在的boost库，可以使用更高效的建立方式,看下面的acceptor
    //这两种方法都是可用的，看具体情况使用
}

int create_acceptor_socket()
{
    //对于服务端，有两个socket，第二个socket是acceptor，用于接收新的连接
    boost::asio::io_context ioc;
    boost::asio::ip::tcp::socket acceptor(
        ioc, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 3333));
    //这种方式直接将建立socket，bind绑定连接一起做了，直接实现了listen
    return 0;
}

int bind_acceptor_socket()
{
    //旧版本绑定endpoint与socket的方式
    //这里endpoint和socket都是新生成的
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
    //客户端连接服务器指定的端点进行连接
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;
    //这里我们直接假设服务器的端点
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
    //如果给到的不是ip地址，而是域名，我们可以使用asio提供的域名解析方法来进行连接
    //不过这种方法不常用，所以了解即可
    std::string host = "llfc.hub";
    std::string port_num = "3333";
    boost::asio::io_context ios;
    boost::asio::ip::tcp::resolver::query resolver_query(
        host, port_num, boost::asio::ip::tcp::resolver::query::numeric_service);
    //生成一个用于查询的对象
    //生成一个域名解析器
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
    //缓冲队列的容量大小
    //它决定了服务器在短时间内可以处理的最大连接数。
    //缓冲队列用于存储那些已完成三次握手但尚未被服务器程序接受的连接。
    //同样生成一个假设的端点,还有服务端的acceptor，另一个socket
    unsigned short port_num = 3333;
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::any(), port_num);
    boost::asio::io_context ios;
    try
    {
        boost::asio::ip::tcp::acceptor acceptor(ios, ep.protocol());
        acceptor.bind(ep);
        //传入缓冲队列的大小
        acceptor.listen(BACKLOG_SIZE);

        boost::asio::ip::tcp::socket sock(ios); //用来跟客户端通信
        acceptor.accept(sock);                  //接收到的新连接让sock来处理
    }
    catch (boost::system::system_error &e)
    {
        std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what();

        return e.code().value();
    }
}
