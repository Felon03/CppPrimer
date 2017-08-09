/* 在运行程序，这次传入Quote对象的shared_ptr。*/
#include"15.27_Bulk_quote.h"
#include<vector>
#include<memory>
#include<numeric>
#include<iostream>

using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;

int main()
{
	vector<shared_ptr<Quote>> basket;

	Bulk_quote bulk0("0-201-82470-1", 20, 10, .2);
	Bulk_quote bulk1("0-201-54848-8", 50, 10, .25);

	cout << "Bulk's total: " << bulk0.net_price(10) + bulk1.net_price(10) << endl;

	basket.push_back(make_shared<Bulk_quote>(bulk0));
	basket.push_back(make_shared<Bulk_quote>(bulk1));

	auto total = std::accumulate(basket.cbegin(), basket.cend(), 0.0,
		[](double ret, const shared_ptr<Quote>&rhs) {
		return ret += (*rhs).net_price(10);
		// return ret += rhs->net_price(10);
	});
	cout << "Quote's Total: " << total << endl;
}