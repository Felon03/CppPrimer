#include"15.15_Bulk_quote.h"
#include<iostream>
#include<string>

using std::string;

int main()
{
	Bulk_quote bulk("0-201-78345-X", 20.00, 10, 0.5);
	print_total(std::cout, bulk, 20);
	return 0;
}