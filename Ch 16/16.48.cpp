/*
    16.48 ��д���Լ��汾��debug_rep����
*/

#include <iostream>
#include <sstream>
#include <string>

// ����
template<typename T> 
std::string debug_rep(const T &t);

template<typename T>
std::string debug_rep(T *p);

std::string debug_rep(const std::string &s);

std::string debug_rep(char *p);

std::string debug_rep(const char *p);

// ����
template<typename T>
std::string debug_rep(const T &t)
{
	std::cout << "debug_rep(const T&)" << std::endl;
	std::ostringstream ret;
	ret << t;    // ʹ��T������������ӡt��һ����ʾ��ʽ
	return ret.str();    // ����ret�󶨵�string��һ������
}

template<typename T>
std::string debug_rep(T * p)
{
	std::cout << "debug_rep(T*)" << std::endl;
	std::ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);    // ��ӡpָ���ֵ
	else
		ret << " null pointer";    // ��ָ��pΪ��
	return ret.str();    // ����ret�󶨵�string��һ������
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