/*��дһ��������ʹ��ָ���βν�������������ֵ���ڴ����е��øú��������������Ľ��*/
#include<iostream>

using namespace std;

void exchange_value(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;

	return;
}

int main()
{
	int a = 5, b = 10;
	cout << "The value of a and b: " << a << " " << b << endl;
	exchange_value(&a, &b);
	cout << "After exchange the value of a and b: " << a << " " << b << endl;

	return 0;
}