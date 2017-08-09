#pragma once
/* 重新定义Bulk_quote类，令其继承构造函数*/
#include"15.15_Disc_quote.h"
#include<string>

using std::string;

class Bulk_quote : public Disc_quote {
public:
	using Disc_quote::Disc_quote;    // 继承Disc_quote的构造函数

	virtual double net_price(size_t cnt) const override
	{
		if (cnt >= quantity) return cnt*(1 - discount)*price;
		else return cnt*price;
	}
};