/*
    16.41 编写一个新的sum版本，它的返回类型保证足够大，足以容纳加法结果
*/
#include<iostream>

template<typename T>
auto sum(T v1, T v2) -> decltype(v1 + v2)
{
	return v1 + v2;
}

int main()
{
	auto s = sum(12346789000000, 1234567890000);
	std::cout << s << std::endl;
	return 0;
}