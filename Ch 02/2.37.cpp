#include<iostream>

using namespace std;

int main()
{
	int a = 3, b = 4;
	decltype(a) c = a;
	decltype(a = b) d = a;		// 返回int型，而赋值操作并不进行
	cout << a << endl
		<< b << endl
		<< c << endl
		<< d << endl;
}