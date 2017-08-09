/*使用给出的ia，将其拷贝到一个vector和一个list中。
使用但迭代器版本的erase从list中删除奇数元素，从vector中删除偶数元素
*/
#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main()
{
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int> vec;	// vector<int> vec(ia, end(ia));
	list<int> lst;				// list<int> lst(vec.begin(), vec.end());

	// 将ia中的元素存入list和vector中
	for (const auto &x : ia)
	{
		vec.push_back(x);
		lst.push_back(x);
	}

	for (auto beg = lst.begin(); beg != lst.end(); )
	{
		if (*beg % 2 != 0)
			beg = lst.erase(beg);		// 注意erase()返回的是一个迭代器
		else
			++beg;
	}
	for (const auto &x : lst)
		cout << x << " ";
	cout << endl;

	for (auto beg = vec.begin(); beg != vec.end(); )
	{
		if (*beg % 2 == 0)
			beg = vec.erase(beg);
		else
			++beg;
	}
	for (const auto &x : vec)
		cout << x << " ";
	cout << endl;
}