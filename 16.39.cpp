/*
    对16.1.1节(第578页)中的原始版本的compare函数，使用一个显示模板实参
	使得可以向函数传递两个字符串字面常量
*/

#include<iostream>

template<typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

int main()
{
	std::cout << compare<std::string>("abc", "def") << std::endl;
	std::cout << compare<std::string>("def", "abc") << std::endl;
	std::cout << compare<std::string>("abc", "abc") << std::endl;
}