/*
    16.50 定义16.49中的函数，令他们打印一条身份信息。检查结果是否和16.49给出的相同
*/

#include<iostream>

template<typename T>void f(T)
{
	std::cout << "call f(T) a" << std::endl;
}

template<typename T> void f(const T*)
{
	std::cout << "call f(const T*) b" << std::endl;
}

template<typename T> void g(T)
{
	std::cout << "call g(T) c" << std::endl;
}

template<typename T> void g( T*)
{
	std::cout << "call g(T*) d" << std::endl;
}

// main func
int main()
{
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42); g(p); g(ci); g(p2);
	f(42); f(p); f(ci); f(p2);

	return 0;
}