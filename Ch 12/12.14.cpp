/* �������Լ��汾����shared_ptr����connection�ĺ���*/
#include<iostream>
#include<memory>
#include<string>

struct connection
{
	std::string ip;
	int port;
	connection(std::string _ip, int _port) : ip(_ip), port(_port) {}
};

struct destination
{
	std::string ip;
	int port;
	destination(std::string _ip, int _port) : ip(_ip), port(_port) {}
};

connection connect(destination* p_dest)
{
	std::shared_ptr<connection> p_conn(new connection(p_dest->ip, p_dest->port));
	// �ȼ�����
	//std::shared_ptr<connection> p_c(std::make_shared<connection>(p_dest->ip, p_dest->port));
	std::cout << "creating connection(" << p_conn.use_count() << ")" << std::endl;
	return *p_conn;
}

void disconnect(connection p_conn)
{
	std::cout << "connection close(" << p_conn.ip << ":" << p_conn.port << ")"
		<< std::endl;
}

// ɾ����(deleter)����������ܵ�������Ϊconnection*�Ĳ���
void end_connection(connection* p_conn)
{
	disconnect(*p_conn);
}

void f(destination &d)
{
	connection conn = connect(&d);
	std::shared_ptr<connection> p(&conn, end_connection);
}

int main()
{
	destination dest("192.168.0.110", 8000);
	f(dest);

	return 0;
}