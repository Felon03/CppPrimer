/* ��Quote��Bulk_quote�Ķ��󴫸�print_total��������麯���Ƿ���ȷ*/
#include"15.5_Bulk_quote.h"
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