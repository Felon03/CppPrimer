/*使用unique_copy将一个vector中不重复的元素拷贝到一个初始为空的list中
	unique_copy相比unique接受第三个迭代器，表示拷贝不重复的元素到目的的位置。
*/
#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
#include<list>

using namespace std;

int main()
{
	vector<int> vi{ 1,2,3,4,5,6,7,8,9,0,9,8,7,6,5,4,3,2,1 };
	list<int> li;
	sort(vi.begin(), vi.end());
	unique_copy(vi.cbegin(), vi.cend(), back_inserter(li));

	for (const auto x : li)
		cout << x << " ";
	cout << endl;

	return 0;
}