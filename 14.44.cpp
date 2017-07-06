/* ��дһ���򵥵����������ʹ���ܴ����Ԫ����*/
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