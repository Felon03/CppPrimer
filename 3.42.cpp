/*��д���򣬽���������Ԫ�ص�vector���󿽱���һ����������*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> arr{ 1, 2, 3, 4, 5, 6 };
	constexpr size_t size = 6;
	int int_arr[size] = {};
	int * beg = begin(int_arr);		// ָ��������Ԫ�ص�ָ��

	for (auto x : int_arr)
		cout << x << " ";
	cout << endl;

	for (auto x : arr)
	{
		*beg++ = x;		// ��vector��ֵ��������
	}

	for (auto x : int_arr)
		cout << x << " ";
	cout << endl;

	return 0;
}
