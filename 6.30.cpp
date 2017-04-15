/*编译第200页的str_subrange函数，看看你的编译器是如何处理函数中的错误的*/
#include<iostream>
#include<string>

using namespace std;

bool str_sunrange(const string &str1, const string &str2)
{
	// 大小相同： 此时用普通的相等性判断结果作为返回值
	if (str1.size() == str2.size())
		return str1 == str2;
	// 得到较短string对象的大小，条件运算符
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	// 检查两个string对象的对应字符是否相等，以较短的字符串长度为限
	for (decltype(size) i = 0; i != size; ++i)
	{
		if (str1[i] != str2[i])
			return;		// 错误 #1：没有返回值，编译器将报错
	}
	// 错误 #2：控制流可能尚未返回任何值就结束了函数的执行
	// 编译器可能检查不出这一错误

}

int main()
{
	string str1 = "asdf";
	string str2 = "qwerty";

	cout << str_sunrange(str1, str2) << endl;

	return 0;
}