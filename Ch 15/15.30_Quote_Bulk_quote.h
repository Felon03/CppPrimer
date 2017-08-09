#pragma once
/* ∂®“Âbasket¿‡*/
#include<string>
#include<iostream>

class Quote {
public:
	Quote() = default;
	Quote(const std::string & book, double p)
		: bookNo(book), price(p) {}

	Quote(const Quote&) = default;
	Quote(Quote&&) = default;

	Quote& operator=(const Quote&) = default;
	Quote& operator=(Quote&&) = default;

	std::string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n*price; }

	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && {return new Quote(std::move(*this)); }

	virtual ~Quote() = default;

private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double p, size_t qty, double disc)
		: Quote(book, p), min_qty(qty), discount(disc) {}

	Bulk_quote(const Bulk_quote &rhs)
		: Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount) {}
	Bulk_quote(Bulk_quote &&rhs) noexcept
		:Quote(std::move(rhs)), min_qty(std::move(rhs.min_qty)), discount(std::move(rhs.discount)) {}

	Bulk_quote& operator=(const Bulk_quote &rhs)
	{
		Quote::operator=(rhs);
		min_qty = rhs.min_qty;
		discount = rhs.discount;
		return *this;
	}
	Bulk_quote& operator=(Bulk_quote &&rhs) noexcept
	{
		Quote::operator=(std::move(rhs));
		min_qty = std::move(rhs.min_qty);
		discount = std::move(rhs.discount);
		return *this;
	}

	virtual double net_price(size_t cnt) const override
	{
		if (cnt >= min_qty) return cnt*(1 - discount)*price;
		else return cnt*price;
	}
	virtual Bulk_quote* clone() const & override
	{
		return new Bulk_quote(*this);
	}
	virtual Bulk_quote* clone() && override
	{
		return new Bulk_quote(std::move(*this));
	}

protected:
	size_t min_qty = 0;
	double discount = 0.0;
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " total due: " << ret << std::endl;
	return ret;
}