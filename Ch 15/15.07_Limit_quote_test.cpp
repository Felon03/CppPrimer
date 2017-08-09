#include"15.07_Limit_quote.h"
#include<iostream>

int main()
{
	Quote quote("0-201-78345-X", 20.00);
	Limit_quote limit_quote("0-201-78345-X", 20, 10, 0.5);
	std::cout << "Quote" << std::endl;
	print_total(std::cout, quote, 15);
	std::cout << "Limit_quote" << std::endl;
	print_total(std::cout, limit_quote, 15);
	return 0;
}