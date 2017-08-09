#include "16.02_compare.h"
#include "Sales_data.h"
#include<iostream>

int main()
{
	std::cout << compare(1, 0) << std::endl;
	std::cout << compare(0, 1) << std::endl;
	std::cout << compare(1, 1) << std::endl;
	std::cout << compare_str("hello", "world") << std::endl;
	//Sales_data data1, data2;
	//std::cout << compare(data1, data2) << std::endl;
	//
	// Error
    // 二进制“<”: 没有找到接受“const Sales_data”类型的左操作数的运算符(或没有可接受的转换)	
	//
	return 0;
}