/*һ��vector�б���1-9�����俽�����������������С�
	�ֱ�ʹ��inserter��back_inserter��front_inserter��Ԫ����ӵ����������С�
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

	// ʹ��front_inserter
	copy(v.cbegin(), v.cend(), front_inserter(l1));
	// ʹ��back_inserter
	copy(v.cbegin(), v.cend(), back_inserter(l2));
	// ʹ��inserter
	copy(v.cbegin(), v.cend(), inserter(l3, l3.begin()));

	print(l1);
	print(l2);
	print(l3);
	
	return 0;
}