/*��д�������������佻������intָ��*/
#include<iostream>

using namespace std;

void swap(int *&a, int *&b)
{
	auto tmp = a;
	a = b;
	b = tmp;
	return;
}

int main()
{
	int i = 100, j = 200;
	auto a = &i;
	auto b = &j;
	swap(a, b);
	cout << *a << " " << *b << endl;

	return 0;
}