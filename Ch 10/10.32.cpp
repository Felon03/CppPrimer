/*重写1.6节中的书店程序，使用一个vector保存交易记录，使用不同算法完成处理。
	使用sort和conpareIsbn函数来排序交易记录，然后使用find和accumulate求和。
*/
#include<iostream>
#include<iterator>
#include<vector>
#include<numeric>
#include<algorithm>
#include"Sales_item.h"

using namespace std;

int main()
{
	istream_iterator<Sales_item> item_iter(cin), eof;
	ostream_iterator<Sales_item> out_iter(cout, "\n");

	vector<Sales_item> items;

	while (item_iter != eof)
		items.push_back(*item_iter++);

	sort(items.begin(), items.end(),
		[](const Sales_item &lhs, const Sales_item &rhs) {return lhs.isbn() < rhs.isbn(); });

	for (auto beg = items.cbegin(), end = beg; beg != items.cend(); beg = end)
	{
		end = find_if(beg, items.cend(), [beg](const Sales_item &item) {return item.isbn() != beg->isbn(); });
		cout << accumulate(beg, end, Sales_item(beg->isbn())) << endl;
	}

	return 0;
}