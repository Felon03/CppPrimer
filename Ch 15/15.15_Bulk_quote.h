#pragma once
/* ¶¨Òå¼Ì³ÐDisc_quoteµÄBulk_quote*/
#include"15.15_Disc_quote.h"
#include<string>

using std::string;

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string &book, double p, size_t qty, double disc)
		: Disc_quote(book, p, qty, disc)
	{
	}
	virtual double net_price(size_t cnt) const override
	{
		if (cnt >= quantity) return cnt * (1 - discount) * price;
		else return cnt * price;
	}
};