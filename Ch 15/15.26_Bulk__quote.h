#pragma once
/* 为Bulk_quote类定义拷贝控制成员，使其与合成版本的行为一致*/
#include"15.26_Quote.h"
#include<string>
#include<iostream>

using std::string;
using std::cout;
using std::endl;

class Bulk_quote : public Quote {
public:
	Bulk_quote()
	{
		cout << "Bulk_quote()" << endl;
	}

	Bulk_quote(const string &s, double p, size_t qty, double disc)
		: Quote(s, p), min_qty(qty), discount(disc)
	{
		cout << "Bulk_quote(const string&, double, size_t, double)" << endl;
	}

	Bulk_quote(const Bulk_quote &rhs)
		: Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount)
	{
		cout << "Bulk_qoute(const Bulk_quote&)" << endl;
	}

	Bulk_quote& operator=(const Bulk_quote &rhs)
	{
		cout << "operator=(const Bulk_quote&)" << endl;
		Quote::operator=(rhs);
		min_qty = rhs.min_qty;
		discount = rhs.discount;
		return *this;
	}

	Bulk_quote(Bulk_quote &&rhs) noexcept
		:Quote(std::move(rhs)), min_qty(std::move(rhs.min_qty)), discount(std::move(rhs.discount))
	{
		cout << "Bulk_quote(Bulk_quote&&) noexcept" << endl;
	}

	Bulk_quote& operator=(Bulk_quote &&rhs) noexcept
	{
		cout << "operator=(Bulk_quote&&) noexcept" << endl;
		Quote::operator=(rhs);
		min_qty = std::move(rhs.min_qty);
		discount = std::move(rhs.discount);
		return *this;
	}

	virtual ~Bulk_quote()
	{
		cout << "~Bulk_quote()" << endl;
	}

	virtual double net_price(size_t cnt) const override
	{
		if (cnt >= min_qty) return cnt*(1 - discount)*price;
		else
			return cnt*price;
	}

protected:
	size_t min_qty = 0;
	double discount = 0.0;
};
