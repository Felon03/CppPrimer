#pragma once
/* ��дһ���û������ĺ������û�����һ�����֣��������ɸ����ֵĽ׳ˣ���main�����е��øú���*/
#include<iostream>
int func()
{
	int n, ret = 1;
	std::cout << "Enter a number: " << std::endl;
	std::cin >> n;
	while (n > 1) ret *= n--;
	return ret;
}