/*д��һ�����ʽ����ȷ��һ����������������ż��*/
#include<iostream>

using namespace std;

int main()
{
	cout << "������һ����" << endl;
	int num;
	cin >> num;
	if (num % 2 == 0)
		cout << num << "��ż��" << endl;
	else
		cout << num << "������" << endl;

	return 0;
}