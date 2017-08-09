/*编写程序，查找并删除forward_list<int>中的奇数元素*/
#include<iostream>
#include<forward_list>

using namespace std;

int main()
{
	forward_list<int> flist{ 0,1,2,3,4,5,6,7,8,9,10 };
	auto prev = flist.before_begin();		// 获取第一个元素之前的迭代器
	auto curr = flist.begin();							// 获取第一个元素的迭代器
	while (curr != flist.end())
	{
		if (*curr % 2 != 0)			// 如果是奇数
			curr = flist.erase_after(prev);
		else
		{
			prev = curr;		// prev指向下一个curr，curr指向下一个元素
			++curr;
		}
	}
	for (const auto &x : flist)
		cout << x << " ";
	cout << endl;
	return 0;
}