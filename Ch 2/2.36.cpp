#include<iostream>

using namespace std;

int main()
{
	int a = 4, b = 4;
	decltype(a) c = a;
	decltype((b)) d = a;
	++c;
	++d;
	cout << "c = " << c << " d = " << d << endl;
	cout << "a = " << a << " b = " << b << endl;
	return 0;
}