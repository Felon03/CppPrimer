#include<iostream>

using namespace std;

int main()
{
	int i = 100;
	int *pi = &i;
	cout << "*pi = " << *pi << " i = " << i << endl;
	*pi = 0;
	cout << "*pi = " << *pi << " i = " << i << endl;
	return 0;
}