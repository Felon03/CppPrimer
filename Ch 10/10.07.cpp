/*�жϳ����Ƿ���������� �����*/
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
	// vec�Ĵ�С��lst����ȣ��޷�copy
	// resolution 1: ��vec�Ĵ�С�����lst��ȵĴ�С
	vec.resize(lst.size());
	//copy(lst.cbegin(), lst.cend(), vec.begin());

	// resolution 2: vec.begin() ��Ϊ back_insert(vec)
	// copy(lst.cbegin(), lst.cend(), back_insertr(vec));

	// (b)
	vector<int> v;
	v.reserve(10);
	//fill_n(v.begin(), 10, 0);		// ����
	// �޸�����
	fill_n(back_inserter(v), 10, 0);

	print(vec);
	print(v);
	return 0;
}