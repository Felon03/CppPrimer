/*测试8.1定义函数，调用参数为cin*/
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
	istream &is = read(cin);
	cout << is.rdstate() << endl;
	
	return 0;
}