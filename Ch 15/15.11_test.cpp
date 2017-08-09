#include"15.11_Quote.h"
#include"15.11_Bulk_quote.h"
#include"15.11_Limit_quote.h"
#include<iostream>

using std::cout;
using std::endl;

int main()
{
	Quote quote("0-201-78345-X", 20.00);
	Bulk_quote bulk("0-201-78345-X", 20.00, 10, 0.5);
	Limit_quote limit("0-201-78345-X", 20.00, 10, 0.5);
	quote.debug();
	bulk.debug();
	limit.debug();
	return 0;
}