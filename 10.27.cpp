/*ʹ��unique_copy��һ��vector�в��ظ���Ԫ�ؿ�����һ����ʼΪ�յ�list��
	unique_copy���unique���ܵ���������������ʾ�������ظ���Ԫ�ص�Ŀ�ĵ�λ�á�
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