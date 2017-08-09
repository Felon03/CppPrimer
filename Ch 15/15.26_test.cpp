#include"15.26_Bulk__quote.h"
#include"15.26_Quote.h"
#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::end;

int main()
{
	Quote quote;
	Quote quote1("0-201-78345-X", 16.9);
	Quote quote_cpy(quote1);
	Quote quote_mov(std::move(quote1));
	//Quote quote_equal = quote1;

	cout << "=============ISBN: price=============" << endl;
	cout << quote.isbn() << ": " << quote.net_price(10) << endl;
	cout << quote1.isbn() << ": " << quote1.net_price(10) << endl;
	cout << quote_cpy.isbn() << ": " << quote_cpy.net_price(10) << endl;
	cout << quote_mov.isbn() << ": " << quote_mov.net_price(10) << endl;
	//cout << quote_equal.isbn() << ": " << quote_equal.net_price(10) << endl;
	cout << "===================================" << endl;

	Bulk_quote bulk;
	Bulk_quote bulk1("0-201-78345-X", 16.9, 10, 0.5);
	Bulk_quote bulk_cpy(bulk1);
	Bulk_quote bulk_mov(std::move(bulk1));
	//Bulk_quote bulk_equal = bulk1;

	cout << "=============ISBN: price=============" << endl;
	cout << bulk.isbn() << ": " << bulk.net_price(10) << endl;
	cout << bulk1.isbn() << ": " << bulk1.net_price(10) << endl;
	cout << bulk_cpy.isbn() << ": " << bulk_cpy.net_price(10) << endl;
	cout << bulk_mov.isbn() << ": " << bulk_mov.net_price(10) << endl;
	//cout << bulk_equal.isbn() << ": " << bulk_equal.net_price(10) << endl;
	cout << "===================================" << endl;

	return 0;
}