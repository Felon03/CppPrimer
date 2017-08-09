#pragma once
/* ���¶���Bulk_quote�࣬����̳й��캯��*/
#include"15.15_Disc_quote.h"
#include<string>

using std::string;

class Bulk_quote : public Disc_quote {
public:
	using Disc_quote::Disc_quote;    // �̳�Disc_quote�Ĺ��캯��

	virtual double net_price(size_t cnt) const override
	{
		if (cnt >= quantity) return cnt*(1 - discount)*price;
		else return cnt*price;
	}
};