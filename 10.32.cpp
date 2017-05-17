/*��д1.6���е�������ʹ��һ��vector���潻�׼�¼��ʹ�ò�ͬ�㷨��ɴ���
	ʹ��sort��conpareIsbn�����������׼�¼��Ȼ��ʹ��find��accumulate��͡�
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