#pragma once
/* 定义virtual debug函数，显示每个数据成员*/
#include"15.11_Quote.h"

class Limit_quote : public Quote {
public:
	Limit_quote() = default;
	Limit_quote(const std::string &book, double p, size_t qty, double disc)
		: Quote(book, p), limit_qty(qty), discount(disc)
	{
	}

	virtual double net_price(size_t cnt) const override
	{
		if (cnt > limit_qty)
			return (cnt - limit_qty)*price + limit_qty * (1 - discount) * price;
		else
			return cnt * (1 - discount) * price;
	}

	virtual void debug() const override
	{
		Quote::debug();
		std::cout << "\tlimit_qty: " << limit_qty << "\tdiscount: " << discount << std::endl;
	}


private:
	size_t limit_qty = 0;
	double discount = 0.0;
};
