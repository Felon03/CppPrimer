#pragma once
/*头文件不应该包含using声明*/
#include<string>
struct Sales_data
{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
