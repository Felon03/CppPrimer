#pragma once
/* 为Sales_data编写重载的输入、输出、加法和复合赋值运算符*/
#include<string>
#include<iostream>

class Sales_data {
	// 运算符重载
	friend std::istream& operator >> (std::istream&,Sales_data&);		// >> Sales_data not const
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);	// << const Sales_data
	friend Sales_data operator+(const Sales_data&, const Sales_data&);	// +
public:
	Sales_data(const std::string &s, unsigned n, double p)
		:bookNo(s), units_sold(n), revenue(p) {}
	Sales_data() :Sales_data("", 0, 0.0f) {}
	Sales_data(const std::string &s) :Sales_data(s, 0, 0.0f) {}
	Sales_data(std::istream &is);

	// 重载+=运算符
	Sales_data& operator+=(const Sales_data&);
	std::string isbn() const { return bookNo; }
private:
	inline double avg_price() const;

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

std::istream& operator >> (std::istream &is, Sales_data &rhs);
std::ostream& operator<<(std::ostream &os, const Sales_data &rhs);
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

inline double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}