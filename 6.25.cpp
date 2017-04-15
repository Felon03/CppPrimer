/*编写一个main函数，令其接受两个实参。把实参的内容连接成一个string对象并输出*/
#include<iostream>
#include<string>

using namespace std;

int main(int argc, char **argv)
{
	string str;
	for (size_t i = 1; i != argc; ++i)
	{
		str += argv[i];
		str += " ";
	}
	
	cout << str << endl;

	return 0;
}