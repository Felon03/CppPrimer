#include<iostream>

using namespace std;

int main()
{
	const int ic, &r = ic;
	int i = 42;
	int *p = &i;
	*p = *p * *p;
	cout << *p << " " << i << endl;
	return 0;
}