/*��дһ�γ��򣬴�������10��������vector����Ȼ��ʹ�õ�����������Ԫ�ص�ֵ�����ԭ�������������vector���������*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> digits;

	for (int i = 0; i < 10; i++)
	{
		digits.push_back(i);
	}
	for (auto x : digits)
		cout << x << endl;
	for (auto iter = digits.begin(); iter != digits.end(); ++iter)
	{
		*iter *= 2;
		cout << *iter << endl;
	}

	return 0;
}