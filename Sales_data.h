#pragma once
/*头文件不应该包含using声明*/
#include<string>
struct Sales_data
{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	// 7.2
	// 添加新成员combine和isbn
	std::string isbn() { return bookNo; }
	Sales_data& combine(const Sales_data&);
};

// combine具体函数
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;			// 返回调用改函数的对象
}
