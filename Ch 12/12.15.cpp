/* 重写第一题的程序，用lambda代替end_connection函数*/
#include<iostream>
#include<memory>
#include<string>

struct connection
{
	std::string ip;
	int port;
	connection(std::string _ip, int _port) :ip(_ip), port(_port) {}
};

struct destination
{
	std::string ip;
	int port;
	destination(std::string _ip, int _port) :ip(_ip), port(_port) {}
};

connection connect(destination* dest)
{
	std::shared_ptr<connection> p_conn(new connection(dest->ip, dest->port));
	std::cout << "established connection(" << p_conn.use_count() << ")"
		<< std::endl;
	return *p_conn;
}

void disconnect(connection conn)
{
	std::cout << "connection close(" << conn.ip << ":" << conn.port << ")"
		<< std::endl;
}

void f(destination &d)
{
	connection conn = connect(&d);
	std::shared_ptr<connection> p(&conn,
		[](connection *conn) {disconnect(*conn); });
	//std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main()
{
	destination dest("192.168.1.110", 8000);
	f(dest);

	return 0;
}