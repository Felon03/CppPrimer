/*使用为8.1.2节第一个联系所编写的函数打印一个istringstream对象的内容*/
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