/*��д����֤���Լ���reset������ʹ���������������͵Ĳ���*/
#include<iostream>

using namespace std;

void reset(int &n)
{
	n = -1;		// ����������ֵΪ-1
}

int main()
{
	int x;
	cout << "Enter a number: " << endl;
	cin >> x;
	cout << "The value of entered number: " << x << endl;
	reset(x);
	cout << "After reset, the value of entered number: " << x << endl;

	return 0;
}