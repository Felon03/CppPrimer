#include<iostream>

int main7()
{
	int currVal = 0, result = 0;
	std::cout << "Please input some integers(at least one): " << std::endl;
	while (std::cin>>currVal)
	{
		result += currVal;
	}
	std::cout <<"The sum of these integers: " << result << std::endl;
	return 0;
}