#pragma once
/* 定义Bulk_quote类*/
#include"15.3_Quote.h"


class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double p, std::size_t qty, double disc)
		: Quote(book, p), min_qty(qty), discount(disc)
	{
	}
	
	// 覆盖基类的函数版本以实现基于大量购买的折扣政策
	virtual double net_price(std::size_t cnt) const override
	{
		if (cnt >= min_qty) return cnt*(1 - discount)*price;
		else return cnt*price;
	}
private:
	std::size_t min_qty = 0;    // 适用折扣政策的最低购买量
	double discount = 0.0;    // 以小数表示的折扣额
};