#pragma once
#include"Chapter6.h"
#include<iostream>

int func()
{
	int n, ret = 1;
	std::cout << "Enter a number: " << std::endl;
	std::cin >> n;
	while (n > 1) ret *= n--;

	return ret;
}

int fact(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n*fact(n - 1);
}

double cal_abs(double n)
{
	return n >= 0 ? n : -n;
}

