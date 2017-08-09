#pragma once
/* 为Quote类体系添加一个名为debug的虚函数，令其分别显示每个类的数据成员*/
#include<string>
#include<iostream>

class Quote {
public:
	Quote() = default;
	Quote(const std::string &s, double p)
		:bookNo(s), price(p)
	{
	}

	std::string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n*price; }
	virtual void debug() const 
	{ 
		std::cout << "data members:\n" << "\tbookNo: " << bookNo << "\tprice: " << price << std::endl; 
	}

	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " total due: " << ret << std::endl;
	return ret;
}