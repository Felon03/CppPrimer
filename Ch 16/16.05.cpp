#include "16.05_print.h"
#include<iostream>
#include<string>

int main()
{
	char arr[10]{ 'a','b','c','d','e','f','g' };
	int arr1[10]{ 1,2,3,4,5,6,7,8,9,0 };
	std::string arr2[10]{ "asv","hello","cpp","freedomly","world" };
	print(arr);
	std::cout<<std::endl;
	print(arr1);
	std::cout<<std::endl;
	print(arr2);
	std::cout<<std::endl;
	return 0;
}