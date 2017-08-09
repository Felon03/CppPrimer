/* 为什么要为Disc_qoute定义一个默认的构造函数？
	如果去掉改构造函数的话会对Bulk_qoute的行为产生什么影响
*/
#include<iostream>
#include<string>

using std::string;

class Quote {
public:
	Quote() = default;
	Quote(const string &book, double p)
		: bookNo(book), price(p) {}

	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n*price; }

	virtual ~Quote() = default;

private:
	string bookNo;
protected:
	double price = 0.0;
};

class Disc_quote : public Quote {
public:
	//Disc_quote() = default;    去掉Disc_quote的默认构造函数
	Disc_quote(const string &book, double p, size_t qty, double disc)
		: Quote(book, p), quantity(qty), discount(disc) {}

	virtual double net_price(size_t) const = 0;    // 纯虚函数

protected:
	size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string &book, double p, size_t qty, double disc)
		: Disc_quote(book, p, qty, disc) {}

	virtual double net_price(size_t cnt) const override
	{
		if (cnt >= quantity) return cnt*(1 - discount)*price;
		else return cnt*price;
	}
};

int main()
{
	Bulk_quote bulk("123", 100.5, 20, 0.5);
	//Bulk_quote bulk1;
	// Error 无法引用"Bulk_quote"的默认构造函数 -- 它是已删除的函数
}