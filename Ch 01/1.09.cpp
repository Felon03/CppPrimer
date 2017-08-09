/*
*  使用while循环将50 到 100 的整数相加
*/

#include<iostream>

int main4()
{
	int x = 50;			// 起始数
	int sum = 0;		// 计算和
	while (x <=100)
	{
		sum += x;
		x++;
	}
	std::cout << "The sum from 50 to 100: " << sum << std::endl;
	return 0;
}