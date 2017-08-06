/*
	16.51 调用本节的每个foo，确定sizeof...(Args)和sizeof...(rest)分别返回什么
	16.52 编写一个程序验证16.51的答案
*/

#include<iostream>
#include<string>

template<typename T, typename... Args>
void foo(const T &t, const Args& ...rest)
{
	std::cout << "sizeof...(Args)" << " " 
		<< sizeof...(Args) << std::endl
		<< "sizeof...(rest)" << " "
		<< sizeof...(rest) << std::endl;
}

// main func
int main()
{
	int i = 0;
	double d = 3.14;
	std::string s = "how now brown cow";
	foo(i, s, 42, d);    // 包中有三个参数
	foo(s, 42, "hi");    // 包中有两个参数
	foo(d, s);    // 保重有一个参数
	foo("hi");    // 空包

	return 0;
}