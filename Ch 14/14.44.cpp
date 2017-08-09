/* 编写一个简单的桌面计算器使其能处理二元运算*/
#include<iostream>
#include<functional>
#include<map>
#include<string>

int main()
{
	std::map<std::string, std::function<int(int, int)>> binops = {
		{"+", std::plus<int>()},
		{"-", std::minus<int>()},
		{"*", std::multiplies<int>()},
		{"/", std::divides<int>()},
		{"%",std::modulus<int>()}
	};

	std::cout << binops["+"](10, 5)
		<< " " << binops["-"](10, 5)
		<< " " << binops["*"](10, 5)
		<< " " << binops["/"](10, 5)
		<< " " << binops["%"](10, 5)
		<< std::endl;

	return 0;
}