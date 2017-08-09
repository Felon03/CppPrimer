/*用户输入两个整数，打印出这两个整数所指定范围内的所有整数*/
#include<iostream>

int main6()
{
	int from = 0, to = 0;
	std::cout << "Please input the start and end integer:" << std::endl;
	std::cin >> from >> to;
	// 如果from 小于to则交换数值
	if (from > to)
	{
		int temp;
		temp = from;
		from = to;
		to = temp;
	}
	std::cout << "The integers between " << from << " and " << to << ": " << std::endl;

	for (int i = from; i < to + 1; i++)
	{
		std::cout << i <<" ";
	}
	std::cout << std::endl;

	return 0;
	
}