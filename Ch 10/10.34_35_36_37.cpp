#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> vi{ 0,1,2,3,4,5,6,7,8,9 };

	// 10.34 使用reverse_iterator逆序打印一个vector
	for (auto r_iter = vi.crbegin(); r_iter != vi.crend(); ++r_iter)
		cout << *r_iter << " ";
	cout << endl;

	// 10.35 使用普通迭代器逆序打印一个vector
	for (auto iter = vi.end(); iter != vi.begin();)
		cout << *--iter << " ";
	cout << endl;

	// 10.36 使用find在一个int的list中查找最后一个值为0的元素
	list<int> lst{ 0,1,2,3,4,5,6,7,8,9,0,9,7,6,4,3,2,1,0,12,3,4 };
	auto iter = find(lst.crbegin(), lst.crend(), 0);
	cout << "Find "<<*iter << " in front of " << *iter.base() << endl;

	// 10.37 给定一个包含10个元素的vector，将位置3到7之间的元素按逆序拷贝到一个list中
	list<int> ls(7 - 3 + 1);
	reverse_copy(vi.cbegin() + 3, vi.cbegin() + 8, ls.begin());
	for (const auto &x : ls)
		cout << x << " ";
	cout << endl;

	return 0;
}