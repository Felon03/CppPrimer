#pragma once
/* ����Quote���print_total����*/
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
	std::string bookNo;    // �鼮��ISBN���
protected:
	double price = 0.0;    // ��������Ȩ���ʣ�����ֹ�����û����ʣ���ʾ�۸�
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " total due: " << ret << std::endl;
	return ret;
}