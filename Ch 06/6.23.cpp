/*�ο����ڽ��ܵļ���print��������������д�Լ��İ汾*/
#include<iostream>

using namespace std;

// ���������
void print(const int a)
{
	cout << a << endl;
	
	return;
}

// �����������
void print(const int *beg, const int *end)
{
	while (beg != end)	
		cout << *beg++ << endl;	// *beg, ����������ǵ�ַ

	return;
}

int main()
{
	int i = 0, j[2] = { 0,1 };

	print(i);
	print(begin(j), end(j));

	return 0;
}

