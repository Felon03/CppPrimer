#pragma once
/* 编写类型转换运算符讲一个Sales_data对象分别转换成string和double
	你认为这些运算符的返回值应该是什么
	operator std::string() const { return bookNo; }
	operator double() const { return revenue; / return avg_price(); }
*/
#include<iostream>
#include<string>

class Sales_data {
	friend std::istream& operator >> (std::istream&, Sales_data&);
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);

public:
	Sales_data(const std::string &s, unsigned n, double p)
		:bookNo(s), units_sold(n), revenue(n *p) {}
	Sales_data() : Sales_data("", 0, 0.0f) {}
	Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f) {}
	Sales_data(std::istream &is);

	Sales_data& operator=(const std::string&);
	Sales_data& operator+=(const Sales_data&);
	// 类型转换运算符
	explicit operator std::string() const { return bookNo; }
	explicit operator double() const { return revenue; }

	std::string isbn() const { return bookNo; }

private:
	inline double avg_price() const;

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

std::istream& operator >> (std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}
