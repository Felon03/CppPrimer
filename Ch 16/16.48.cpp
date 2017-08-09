/*
    16.48 编写你自己版本的debug_rep函数
*/

#include <iostream>
#include <sstream>
#include <string>

// 声明
template<typename T> 
std::string debug_rep(const T &t);

template<typename T>
std::string debug_rep(T *p);

std::string debug_rep(const std::string &s);

std::string debug_rep(char *p);

std::string debug_rep(const char *p);

// 定义
template<typename T>
std::string debug_rep(const T &t)
{
	std::cout << "debug_rep(const T&)" << std::endl;
	std::ostringstream ret;
	ret << t;    // 使用T的输出运算符打印t的一个表示形式
	return ret.str();    // 返回ret绑定的string的一个副本
}

template<typename T>
std::string debug_rep(T * p)
{
	std::cout << "debug_rep(T*)" << std::endl;
	std::ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);    // 打印p指向的值
	else
		ret << " null pointer";    // 或指出p为空
	return ret.str();    // 返回ret绑定的string的一个副本
}

std::string debug_rep(const std::string &s)
{
	std::cout << "debug_rep(const string&)" << std::endl;
	return '"' + s + '"';
}


std::string debug_rep(char *p)
{
	std::cout << "debug_rep(char*)" << std::endl;
	return debug_rep(std::string(p));
}

std::string debug_rep(const char *p)
{
	std::cout << "debug_rep(const char*)" << std::endl;
	return debug_rep(std::string(p));
}


// main func
int main()
{
	int i = 10;
	std::string s("hi");
	const std::string *sp = &s;
	char *a = "hello";
	const char *b = a;

	std::cout << debug_rep(i) << std::endl;
	std::cout << "===============\n";
	std::cout << debug_rep(s) << std::endl;
	std::cout << "===============\n";
	std::cout << debug_rep(sp) << std::endl;
	std::cout << "===============\n";
	std::cout << debug_rep("hello world")<<::std::endl;
	std::cout << "===============\n";
	std::cout << debug_rep(a) << std::endl;
	std::cout << "===============\n";
	std::cout << debug_rep(b) << std::endl;
	std::cout << "===============\n";
}