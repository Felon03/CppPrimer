/*ʹ��Ϊ8.1.2�ڵ�һ����ϵ����д�ĺ�����ӡһ��istringstream���������*/
#include<sstream>
#include<iostream>
#include<string>

using namespace std;

istream &read(istream &is)
{
	string buf;
	while (is >> buf)
		cout << buf << endl;
	is.clear();
	return is;
}

int main()
{
	istringstream iss("hello");
	read(iss);
	return 0;
}