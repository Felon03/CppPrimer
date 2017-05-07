/*�������һ�������У��������insert�Ľ������begin�����ᷢ��ʲô*/
//  @Answer crash, cause the iterator is invalid after insert. Because
//  Iterators, pointers, and references to a
//          vector or string are invalid if the container was reallocated.

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
	auto begin = v.begin();
	while (begin != v.end())
	{
		++begin;
		begin = v.insert(begin, 42);
		++begin;
	}

	for (auto i : v) cout << i << " ";

	return 0;
}