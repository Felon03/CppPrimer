/*ʹ�ø�����ia�����俽����һ��vector��һ��list�С�
ʹ�õ��������汾��erase��list��ɾ������Ԫ�أ���vector��ɾ��ż��Ԫ��
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

	// ��ia�е�Ԫ�ش���list��vector��
	for (const auto &x : ia)
	{
		vec.push_back(x);
		lst.push_back(x);
	}

	for (auto beg = lst.begin(); beg != lst.end(); )
	{
		if (*beg % 2 != 0)
			beg = lst.erase(beg);		// ע��erase()���ص���һ��������
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