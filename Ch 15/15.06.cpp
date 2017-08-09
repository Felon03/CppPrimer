/* 将Quote和Bulk_quote的对象传给print_total函数，检查函数是否正确*/
#include"15.05_Bulk_quote.h"
#include<iostream>

int main()
{
	Quote quote("0-201-78345-X", 20.00);
	Bulk_quote bulk_qoute("0-201-78345-X", 20.00, 10, 0.5);
	std::cout << "Quote" << std::endl;
	print_total(std::cout, quote, 15);
	std::cout << "Bulk_quote" << std::endl;
	print_total(std::cout, bulk_qoute, 15);
	return 0;
}