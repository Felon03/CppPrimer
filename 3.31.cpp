/*��дһ�γ��򣬶���һ������10��int�����飬��ÿ��Ԫ�ص�ֵ�������±�ֵ*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int a[10] = {};
	for (size_t i = 0; i < 10; i++)
	{
		a[i] = i;
	}
	cout << "initialize array:" << endl;
	for (auto x : a)
		cout << x << " ";
	cout << endl;
	int a1[10] = {};
	// ��������һ������
	for (auto x : a)
		a1[x] = x;
	cout << "copy array:" << endl;
	for (auto x : a1)
		cout << a1[x] << " ";
	cout << endl;

	// ����vector��д����
	vector<int>	 a3;
	for (size_t i = 0; i < 10; i++)
	{
		a3.push_back(i);
	}
	cout << "vector:" << endl;
	for (auto x : a3)
		cout << x << " ";
	cout << endl;
	
	return 0;
}