#include<iostream>

using namespace std;

int main()
{
	unsigned u1 = 10, u2 = 42;
	cout << u2 - u1 << endl;
	cout << u1 - u2 << endl;

	int i = 10, i2 = 42;
	cout << i2 - i << endl;
	cout << i - i2 << endl;
	cout << i - u1 << endl;
	cout << u1 - i << endl;
	cout << "A really, really long string literal"
		" that spans two lines" << endl;
	cout << 'A' << endl;
	return 0;
}