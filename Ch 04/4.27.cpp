/*求表达式结果*/
#include<iostream>

using namespace std;

int main()
{
	unsigned long ul1 = 3, ul2 = 7;
	auto x = ul1 &ul2;
	cout << x << endl;
	auto y = ul1 | ul2;
	cout << y << endl;
	auto z = ul1&&ul2;
	cout << z << endl;
	auto m = ul1 || ul2;
	cout << m << endl;

	return 0;
}