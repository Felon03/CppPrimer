#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> vi{ 0,1,2,3,4,5,6,7,8,9 };

	// 10.34 ʹ��reverse_iterator�����ӡһ��vector
	for (auto r_iter = vi.crbegin(); r_iter != vi.crend(); ++r_iter)
		cout << *r_iter << " ";
	cout << endl;

	// 10.35 ʹ����ͨ�����������ӡһ��vector
	for (auto iter = vi.end(); iter != vi.begin();)
		cout << *--iter << " ";
	cout << endl;

	// 10.36 ʹ��find��һ��int��list�в������һ��ֵΪ0��Ԫ��
	list<int> lst{ 0,1,2,3,4,5,6,7,8,9,0,9,7,6,4,3,2,1,0,12,3,4 };
	auto iter = find(lst.crbegin(), lst.crend(), 0);
	cout << "Find "<<*iter << " in front of " << *iter.base() << endl;

	// 10.37 ����һ������10��Ԫ�ص�vector����λ��3��7֮���Ԫ�ذ����򿽱���һ��list��
	list<int> ls(7 - 3 + 1);
	reverse_copy(vi.cbegin() + 3, vi.cbegin() + 8, ls.begin());
	for (const auto &x : ls)
		cout << x << " ";
	cout << endl;

	return 0;
}