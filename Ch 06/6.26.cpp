/*编写一个程序，时期接受本节所示的选项；输出传递给main函数实参的内容*/
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char **argv)		// argv是一个数组，它的元素指向C风格字符串指针，第一个形参argc表示数组中字符串的数量
{
	string str;
	for (auto i = 1; i != argc; ++i)
		cout << argv[i] << endl;

	return 0;
}
