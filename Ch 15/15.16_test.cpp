#include"15.16_Limit_quote.h"
#include<string>
#include<iostream>

using std::string;

int main()
{
	Limit_quote limit("0-201-78345-X", 20.00, 10, 0.5);
	//Disc_quote disc("0-201-78345-X", 20.00, 10, 0.5);    // 15.17 Error: "Disc_quote": 不能实例化抽象类
	print_total(std::cout, limit, 20);
	std::cout << limit.net_price(20) << std::endl;
	return 0;
}