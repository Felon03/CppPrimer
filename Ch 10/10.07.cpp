/*判断程序是否有误，如果有 请改正*/
#include<iostream>
#include<iterator>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

template <typename Sequence> void print(Sequence const &seq)
{
	for (const auto &x : seq)
		cout << x << " ";
	cout << endl;
}

int main()
{
	// (a)
	vector<int> vec;
	list<int> lst;
	int i;
	while (cin >> i)
		lst.push_back(i);
	// vec的大小与lst不相等，无法copy
	// resolution 1: 将vec的大小变成与lst相等的大小
	vec.resize(lst.size());
	//copy(lst.cbegin(), lst.cend(), vec.begin());

	// resolution 2: vec.begin() 改为 back_insert(vec)
	// copy(lst.cbegin(), lst.cend(), back_insertr(vec));

	// (b)
	vector<int> v;
	v.reserve(10);
	//fill_n(v.begin(), 10, 0);		// 错误
	// 修改如下
	fill_n(back_inserter(v), 10, 0);

	print(vec);
	print(v);
	return 0;
}