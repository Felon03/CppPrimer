/*编写程序，讲一个list中的char *指针(指向C风格字符串)元素赋值给一个vector中的string*/
#include<iostream>
#include<string>
#include<list>
#include<vector>

using namespace std;

int main()
{
	list<const char *> oldStyle{ "hello world", "The Elder Scroll V: Skyrim", "Grand Theft Auto V" };
	vector<string> newStr;
	newStr.assign(oldStyle.cbegin(), oldStyle.cend());

	for (const auto &x : newStr)
		cout << x << endl;
	return 0;
}