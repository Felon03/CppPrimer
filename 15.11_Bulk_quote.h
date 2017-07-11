#pragma once
/* 定义虚函数debug，输出类的数据成员*/
#include"15.11_Quote.h"

class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double p, size_t qty, double disc)
		: Quote(book, p), min_qty(qty), discount(disc)
	{
	}

	virtual double net_price(size_t cnt) const override
	{
		if (cnt >= min_qty) return cnt*(1 - discount)*price;
		else return cnt*price;
	}
	virtual void debug() const override
	{
		Quote::debug();
		std::cout << "\tmin_qty: " << min_qty << "\tdiscount: " << discount << std::endl;
	}
private:
	size_t min_qty = 0;
	double discount = 0.0;
};

