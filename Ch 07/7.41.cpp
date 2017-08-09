/*使用委托构造函数编写Sales_data类*/
#include"7.41.h"

// 成员函数定义
Sales_data &Sales_data::combine(const Sales_data & rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

// 友元函数定义
std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue;
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data tmp = lhs;
	tmp.combine(rhs);
	return tmp;
}
