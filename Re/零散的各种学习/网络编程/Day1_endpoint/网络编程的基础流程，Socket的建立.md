---
date: 2025-10-23
tags:
  - 网络编程
---
# 网络编程的根基


![](零散的各种学习/网络编程/Day1_endpoint/process.jpg)


如图，网络编程的所有基本都是基于这张图的流程。

这是一个客户-服务端模式的通信方式，根据计算机网络，我们知道，两台主机的进程想要进行通信，首先要**得知对方的IP地址以及端口号(port)**，在网络编程中，当我们获取到了对方的IP地址以及端口号，我们会使用一个叫*endpoint*的数据结构将这两个玩意进行绑定。

但是之后要怎么做？根据流程图，我们还需要一个最关键的数据结构：**Socket(套接字)**

- **Socket** 是通信的端点，是程序与操作系统之间进行网络通信的接口.它既可以用于创建连接，也可以用于发送和接收数据。

有了这两个数据结构后，我们就可以实现流程图上用于**建立连接**的所有函数，他们分别是

- *socket()*
- *bind()*
- *connect()*
- *accept()*
- *listen()*

此外，由于考虑到代码的模块化，通常我们建立endpoint也会再用一个函数，即*endpoint()*

接下来我们通过具体代码来逐个讲解函数，代码为C++，使用的是Boost的asio库

# endpoint()

首先，由于是客户端-服务器模式，所以客户端与服务器都有各自的建立方式

客户端：

```cpp
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
	return 0;
}
```


服务端：

```cpp
int server_end_point() {
	//假设这是一个服务端，那么他的endpoint指定的地址与端口，会在bind之后的listen环节被监听
	unsigned short port_num = 3333;
	auto ip_address = boost::asio::ip::address_v4::any();//服务器经常用这种方式绑定自己的地址
	boost::asio::ip::tcp::endpoint ep(ip_address, port_num); //绑定
	return 0;
}
```


# socket()

socket()函数，就是用于建立一个socket数据结构

其中，客户端只需建立一个socket，但服务端要建立两个socket，分别为 Listening Socket,以及 Communication Socket.

通信套接字的典型操作为read(),write(),属于后续的部分，我们现在主要讲监听套接字

客户端:

```cpp
int create_tcp_socket() {
	//创建socket分为4步，创建上下文iocontext，选择协议，生成socket，打开socket。
	boost::asio::io_context ioc; //创建了上下文
	boost::asio::ip::tcp protocol = boost::asio::ip::tcp::v4(); //选择ipv4协议
	boost::asio::ip::tcp::socket sok(ioc);
	boost::system::error_code ec;
	sok.open(protocol, ec);//用ipv4打开，如果失败就报错
	if (ec.value() != 0) {
		// Failed to open the socket.
		std::cout
			<< "Failed to open the socket! Error code = "
			<< ec.value() << ". Message: " << ec.message();
		return ec.value();
	}

	//在现在的boost库，可以使用更高效的建立方式,看下面的acceptor
	//这两种方法都是可用的，看具体情况使用
}
```

服务端：

```cpp
int create_acceptor_socket() {
	//对于服务端，有两个socket，第二个socket是acceptor，用于接收新的连接
	boost::asio::io_context ioc;
	boost::asio::ip::tcp::socket acceptor(ioc, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),3333));
	//此为boost新版本建立socket方式
	//这种方式直接将建立socket，bind绑定连接一起做了
	return 0;
}
```

由此可见，一个Socket包含了**ip协议(protocol),port,以及上下文(io_context)**，这是绑定完成后的。

# bind()

对于客户端来说，bind相当于connect操作中的一部分

对于服务端来说，bind就是把endpoint与socket进行绑定。

bind函数在旧版本的socket生成方式中使用，新版本有简化版可以直接在构造时将endpoint与socket绑定，**使用哪种方法看具体情况，不一概而论**

使用socket的bind()来绑定

```cpp
int bind_acceptor_socket() {
	//旧版本绑定endpoint与socket的方式
	//这里endpoint和socket都是新生成的
	unsigned short port_num = 3333;
	boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::any(), port_num);
	boost::asio::io_context ioc;
	boost::asio::ip::tcp::socket acceptor(ioc,ep.protocol());
	boost::system::error_code ec;
	acceptor.bind(ep, ec);
	if (ec.value() != 0) {
		// Failed to bind the acceptor socket. Breaking
		// execution.
		std::cout << "Failed to bind the acceptor socket."
			<< "Error code = " << ec.value() << ". Message: "
			<< ec.message();

		return ec.value();
	}

	return 0;
}
```


# connect()

客户端专属，没啥好说的，使用socket的connect()来连接

```cpp
int connect_to_end() {
	//客户端连接服务器指定的端点进行连接
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;
	//这里我们直接假设服务器的端点
	try {
		boost::asio::ip::tcp::endpoint
			ep(boost::asio::ip::address::from_string(raw_ip_address),
				port_num);
		boost::asio::io_context ios;
		boost::asio::ip::tcp::socket sock(ios, ep.protocol());
		sock.connect(ep);
	}
	catch (boost::system::system_error &e) {
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}
}
```

这里还有一种DNS解析的连接方式，但很少见，只需了解即可

```cpp
int dns_connect_to_end() {
	//如果给到的不是ip地址，而是域名，我们可以使用asio提供的域名解析方法来进行连接
	//不过这种方法不常用，所以了解即可
	std::string host = "llfc.hub";
	std::string port_num = "3333";
	boost::asio::io_context ios;
	boost::asio::ip::tcp::resolver::query resolver_query(host, port_num, boost::asio::ip::tcp::resolver::query::numeric_service);
	//生成一个用于查询的对象
	//生成一个域名解析器
	boost::asio::ip::tcp::resolver resolver(ios);
	try {
		boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(resolver_query);
		boost::asio::ip::tcp::socket sok(ios);
		boost::asio::connect(sok, it);
	}
	catch (boost::system::system_error& e) {
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}
}
```


# listen()

当有客户端连接时，服务器需要接收连接，建立监听套接字后，使用listen()方法，开始进行监听


```cpp
int accept_new_connection() {
	const int BACKLOG_SIZE = 30;
	//缓冲队列的容量大小
	//它决定了服务器在短时间内可以处理的最大连接数。
	//缓冲队列用于存储那些已完成三次握手但尚未被服务器程序接受的连接。
	//同样生成一个假设的端点,还有服务端的acceptor，另一个socket
	unsigned short port_num = 3333;
	boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::any(),
		port_num);
	boost::asio::io_context  ios;
	try {
		boost::asio::ip::tcp::acceptor acceptor(ios, ep.protocol());
		acceptor.bind(ep);
		//传入缓冲队列的大小
		acceptor.listen(BACKLOG_SIZE);

		boost::asio::ip::tcp::socket sock(ios);//用来跟客户端通信
		acceptor.accept(sock);//接收到的新连接让sock来处理

	}
	catch (boost::system::system_error& e) {
		std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
	}
}
```