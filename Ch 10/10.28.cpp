/*一个vector中保存1-9，将其拷贝到三个其他容器中。
	分别使用inserter、back_inserter和front_inserter将元素添加到三个容器中。
*/
#include<iostream>
#include<vector>
#include<list>
#include<iterator>

using namespace std;

void print(const list<int> &l)
{
	for (const auto &x : l)
		cout << x << " ";
	cout << endl;
}

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9 };
	list<int> l1, l2, l3;

	// 使用front_inserter
	copy(v.cbegin(), v.cend(), front_inserter(l1));
	// 使用back_inserter
	copy(v.cbegin(), v.cend(), back_inserter(l2));
	// 使用inserter
	copy(v.cbegin(), v.cend(), inserter(l3, l3.begin()));

	print(l1);
	print(l2);
	print(l3);
	
	return 0;
}