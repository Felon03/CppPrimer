#include<iostream>

int main()
{
	int value = 100;
	int &refval = value;
	int &refval1 = refval;
	int i = 100, sum = 0;
	for (int i = 0; i != 10; i++)
	{
		sum += i;
	}
	std::cout << i << " " << sum << std::endl;
	return 0;
}