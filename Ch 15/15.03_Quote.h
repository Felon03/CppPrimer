#pragma once
/* 定义Quote类和print_total函数*/
#include<string>
#include<iostream>

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price)
		: bookNo(book), price(sales_price) {}
	
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n*price; }

	virtual ~Quote() = default;
private:
	std::string bookNo;    // 书籍的ISBN编号
protected:
	double price = 0.0;    // 派生类有权访问，但禁止其他用户访问，表示价格
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " total due: " << ret << std::endl;
	return ret;
}