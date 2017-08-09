/* 定义一个存放Quote对象的vector，将Bulk_quote对象传入其中。
计算vector中所有元素总的net_price。
*/
#include"15.27_Bulk_quote.h"
#include<iostream>
#include<numeric>
#include<vector>
// http://en.cppreference.com/w/cpp/algorithm/accumulate numeric ref
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<Quote> basket;
	Bulk_quote bulk0("0-201-82470-1", 20, 10, .2);
	Bulk_quote bulk1("0-201-54848-8", 50, 10, .25);

	cout << "Bulk_quote's total: " << bulk0.net_price(10) + bulk1.net_price(10) << endl;

	basket.push_back(bulk0);
	basket.push_back(bulk1);

	double total = std::accumulate(basket.cbegin(), basket.cend(), 0.0, [](double ret, const Quote &rhs) {
		return ret += rhs.net_price(10);
	});

	cout << "Quote's total: " << total << endl;

	// dash-separated string
	//vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	//std::string s = std::accumulate(std::next(v.begin()), v.end(),
	//	std::to_string(v[0]),
	//	[](std::string a, int b) {
	//	return a + '-' + std::to_string(b);
	//});
	//cout << s << endl;
	return 0;
}