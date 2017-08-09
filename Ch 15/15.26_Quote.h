#pragma once
/* 为Quote定位拷贝控制成员，令其与合成版本一致*/
#include<string>
#include<iostream>

using std::string;
using std::cout;
using std::endl;

class Quote {
public:
	Quote()
	{
		cout << "Quote()" << endl;
	}

	Quote(const string &s, double p)
		: bookNo(s), price(p)
	{
		cout << "Quote(const string&, double)" << endl;
	}

	Quote(const Quote &rhs)
		: bookNo(rhs.bookNo), price(rhs.price)
	{
		cout << "Quote(const Quote&)" << endl;
	}

	Quote& operator=(const Quote &rhs)
	{
		cout << "operator=(const Quote&)" << endl;
		price = rhs.price;
		bookNo = rhs.bookNo;
		return *this;
	}

	Quote(Quote &&rhs) noexcept
		: bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price))
	{
		cout << "Quote(&&) noexcept" << endl;
	}

	Quote& operator=(Quote &&rhs) noexcept
	{
		cout << "operator=(Quote&&) noexcept" << endl;
		price = std::move(rhs.price);
		bookNo = std::move(rhs.bookNo);
		return *this;
	}

	virtual ~Quote()
	{
		cout << "~Quote()" << endl;
	}

	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n*price; }

private:
	string bookNo;
protected:
	double price = 0.0;
};