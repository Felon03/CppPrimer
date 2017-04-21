/*修改Sales_data类使其隐藏实现的细节*/
#pragma once
#include<string>
class Sales_data;
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
Sales_data add(const Sales_data &, const Sales_data &);

class Sales_data
{
	friend std::istream &read(std::istream &, Sales_data &);
	friend std::ostream &print(std::ostream &, const Sales_data &);
	friend Sales_data add(const Sales_data &, const Sales_data &);
public:
	// 构造函数
	Sales_data() = default;	// 默认构造函数
	Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n*p) {}
	Sales_data(std::istream &is) { read(is, *this); }
	// 编写一个构造函数，令其用我们提供的雷内初始值显式地初始化成员 7.14
	//Sales_data() : units_sold(0), revenue(0) {}

private:
	// 成员变量
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

public:
	// 成员函数
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data &);
};
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.bookNo << " " << item.units_sold << " " << item.revenue;
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

