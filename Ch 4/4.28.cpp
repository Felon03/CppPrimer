/*编写一段程序，输出每一种内置类型所占空间的大小*/
#include<iostream>

using namespace std;

int main()
{
	int x[10]; int *p = x;
	cout << sizeof(x) / sizeof(*x) << endl
		<< sizeof(p) / sizeof(*p) << endl << endl;
	cout << sizeof(bool) << endl
		<< sizeof(char) << endl
		<< sizeof(wchar_t) << endl
		<< sizeof(char16_t) << endl
		<< sizeof(char32_t) << endl
		<< sizeof(short) << endl
		<< sizeof(int) << endl
		<< sizeof(long) << endl
		<< sizeof(long long) << endl
		<< sizeof(float) << endl
		<< sizeof(double) << endl
		<< sizeof(long double) << endl;

	return 0;
	
}