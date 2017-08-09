/*
    16.56 编写并测试可变参数版本的errorMsg
*/
#include<iostream>
#include<sstream>
#include<memory>

// 声明
template<typename T> std::string debug_rep(const T &t);

template<typename T> std::string debug_rep(T *p);

std::string debug_rep(const std::string &s);

std::string debug_rep(char *p);

std::string debug_rep(const char *p);

template<typename T> 
std::ostream &print(std::ostream &os, const T &t);

template<typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args&... rest);

template<typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args&... rest);

int main()
{
	errorMsg(std::cout, 1, 2, 3, 4, 9.0f, "hello", "cpp");
	std::cout << "\n";
	return 0;
}

// 定义
template<typename T>
std::string debug_rep(const T & t)
{
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

template<typename T>
std::string debug_rep(T *p)
{
	std::ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

std::string debug_rep(const std::string &s)
{
	return '"' + s + '"';
}

std::string debug_rep(char *p)
{
	return debug_rep(std::string(p));
}

std::string debug_rep(const char *p)
{
	return debug_rep(std::string(p));
}

template<typename T>
std::ostream &print(std::ostream &os, const T &t)
{
	return os << t;
}

template<typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args&... rest)
{
	os << t << ",";
	return print(os, rest...);
}

template<typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args&... rest)
{
	// print(os, debug_rep(a1), debug_rep(a2), ... , debug_rep(an);
	return print(os, debug_rep(rest)...);
}
