#include"14.15.h"

using namespace std;

int main()
{
	Book book1(123, "C++ Primer 5th", "Lippman", "2013", 2);
	Book book2(123, "C++ Primer 5th", "Lippman", "2013", 5);
	cout << book1 + book2 << endl;
	cout << (book1 == book2) << endl;
	cout << (book1 > book2) << endl;
	return 0;
}