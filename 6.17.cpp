/*编写一个函数，判断string对象中是否含有大写字母。编写另一个函数，把string对象全部改成小写形式*/
#include<iostream>
#include<string>

using namespace std;

bool has_Capital(const string &s)
{
	for (auto beg = s.begin(); beg != s.end(); ++beg)
		if (isupper(*beg))
			return true;
	return false;
}

string lower_string(string &s)
{
	for (auto &x : s)
		if (isupper(x))
		{
			x = tolower(x);		// 如果是大写字母，改为小写
		}

	return s;
}

int main()
{
	string str("Hello World!");
	cout << boolalpha << has_Capital(str) << endl;		// std::boolalpha 以true false的形式输出
	cout << lower_string(str) << endl;

	return 0;
}