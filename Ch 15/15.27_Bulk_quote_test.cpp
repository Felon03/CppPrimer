#include"15.27_Bulk_quote.h"
#include<string>

int main()
{
	Bulk_quote bulk("0-201-78345-X", 16.9, 10, 0.5);
	print_total(std::cout, bulk, 10);
	return 0;
}