#pragma once
/* 定义一个类，使其实现一种数量受限的折扣策略，其策略是：当购买书籍的数量
	不超过一个给定的限量时享受折扣，如果购买量一旦超过了限量，则超出部分将
	以原价销售
*/
#include"15.3_Quote.h"

class Limit_quote : public Quote {
public:
	Limit_quote() = default;
	Limit_quote(const std::string &book, double p, std::size_t qty, double disc)
		: Quote(book, p), limit_qty(qty), discount(disc)
	{
	}

	virtual double net_price(std::size_t cnt) const override
	{
		if (cnt > limit_qty)
			return (cnt - limit_qty) * price + limit_qty * (1 - discount) * price;
		else
			return cnt * (1 - discount)*price;
	}


private:
	std::size_t limit_qty = 0;    // 购买限量
	double discount = 0.0;    // 折扣
};