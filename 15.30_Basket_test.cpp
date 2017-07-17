#include"15.30_Basket.h"
#include"15.30_Quote_Bulk_quote.h"
#include<iostream>
//#include<vector>

using std::cout;
using std::endl;
//using std::vector;

int main()
{
	Bulk_quote bulk0("0-201-82470-1", 20, 10, .2);
	Bulk_quote bulk1("0-201-54848-8", 50, 10, .25);
	
	cout << "Bulk's total: " << bulk0.net_price(10) + bulk1.net_price(10) << endl;

	Basket basket;
	for (int i = 0; i != 10; ++i)
	{
		basket.add_item(bulk0);
		basket.add_item(bulk1);
	}
	basket.total_receipt(cout);
	return 0;
}