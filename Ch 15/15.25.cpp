/* ΪʲôҪΪDisc_qoute����һ��Ĭ�ϵĹ��캯����
	���ȥ���Ĺ��캯���Ļ����Bulk_qoute����Ϊ����ʲôӰ��
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
	//Disc_quote() = default;    ȥ��Disc_quote��Ĭ�Ϲ��캯��
	Disc_quote(const string &book, double p, size_t qty, double disc)
		: Quote(book, p), quantity(qty), discount(disc) {}

	virtual double net_price(size_t) const = 0;    // ���麯��

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
	// Error �޷�����"Bulk_quote"��Ĭ�Ϲ��캯�� -- ������ɾ���ĺ���
}