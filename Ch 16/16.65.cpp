/*
    16.65 在16.63节中我们定义了两个重载的debug_rep版本，
	一个接受const char*参数，另一个接受char*参数。
	将这两个函数重写为特例化版本。	
*/

#include<iostream>
#include<sstream>
#include<vector>
#include<string>

//template<typename T> std::string debug_rep(const T &t);
// 声明
template<typename T> std::string debug_rep(T *p);
// 特例化
template<> std::string debug_rep(const char *p);
template<> std::string debug_rep(char *p);

int main()
{
	//char p[] = "hello world";
	char *p = "hello cpp";
	const char *cp = p;

	std::cout << debug_rep(p) << "\n";
	std::cout << debug_rep(cp) << "\n";

	return 0;
}

template<typename T> std::string debug_rep(T *p)
{
	std::cout << "debug_rep(T)" << std::endl;
	std::ostringstream ret;
	ret << p;
	return ret.str();
}

// 定义
template<> std::string debug_rep(const char *p)
{
	std::cout << "debug_rep(const char*)" << std::endl;
	std::string ret(p);
	return ret;
}

template<> std::string debug_rep(char *p)
{
	std::cout << "debug_rep(char*)" << std::endl;
	std::string ret(p);
	return ret;
}