/*��дһ�γ���ʹ�������������vector<int>���ҵ���ЩԪ�ص�ֵ��������Ȼ����Щ����ֵ����*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> a = { 0,1,2,3,4,5,6,7,8,9 };
	for (auto &x : a)
		(x % 2) == 0 ? x *= 2 : x = x;
	for (auto x : a)
		cout << x << " ";
	cout << endl;

	return 0;
}