#pragma once
/* 编写一个用户交互的函数，用户输入一个数字，计算生成该数字的阶乘，在main函数中调用该函数*/
#include<iostream>
int func()
{
	int n, ret = 1;
	std::cout << "Enter a number: " << std::endl;
	std::cin >> n;
	while (n > 1) ret *= n--;
	return ret;
}