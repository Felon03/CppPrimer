#pragma once
/* ÁîLimit_quote¼Ì³Ð×ÔDisc_quote*/
#include"15.15_Disc_quote.h"
#include<string>

using std::string;

class Limit_quote : public Disc_quote {
public:
	Limit_quote() = default;
	Limit_quote(const string &book, double p, size_t qty, double disc)
		: Disc_quote(book, p, qty, disc)
	{
	}

	virtual double net_price(size_t cnt) const override
	{
		if (cnt > quantity)
			return (cnt - quantity) * price + quantity * (1 - discount) * price;
		else
			return cnt * (1 - discount) * price;
	}
};