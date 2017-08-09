#pragma once
/* 定义Disc_quote类*/
#include"15.03_Quote.h"
#include<string>

using std::string;

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const string &book, double p, size_t qty, double disc)
		: Quote(book, p), quantity(qty), discount(disc)
	{
	}
	virtual double net_price(size_t) const = 0;
protected:
	size_t quantity = 0;    // 折扣适用的购买数量
	double discount = 0.0;    // 表示折扣的小数值
};