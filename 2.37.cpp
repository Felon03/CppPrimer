#include<iostream>

using namespace std;

int main()
{
	int a = 3, b = 4;
	decltype(a) c = a;
	decltype(a = b) d = a;		// ����int�ͣ�����ֵ������������
	cout << a << endl
		<< b << endl
		<< c << endl
		<< d << endl;
}