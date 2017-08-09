/*使用委托构造函数重新编写Sales_data类，给每个构造函数体添加一条语句，令其一旦执行就打印一条信息*/
#pragma once

#include<string>
#include<iostream>

class Sales_data
{
	friend std::istream &read(std::istream &is, Sales_data &item);
	friend std::ostream &print(std::ostream &os, const Sales_data &item);
	friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
	Sales_data(const std::string &s, unsigned n, double price) : bookNo(s), units_sold(n), revenue(n*price) 
	{
		std::cout << "Sales_data(const std::string &, unsigned, double)" << std::endl;
	}
	Sales_data() : Sales_data("", 0, 0.0f) 
	{
		std::cout << "Sales_data()" << std::endl;
	}
	Sales_data(const std::string &s) :Sales_data(s, 0, 0.0f)
	{
		std::cout << "Sales_data(std::string &)" << std::endl;
	}
	Sales_data(std::istream &is) : Sales_data()
	{
		std::cout << "Sales_data(std::istream &)" << std::endl;
		read(is, *this);
	}

	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &);

private:
	double avg_price() const;

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

inline double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}

std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);