#include"14.46_Sales_data.h"
#include<iostream>

int main()
{
	Sales_data book("Cpp Primer 5th", 10, 17.9);
	std::cout << book << std::endl;
	std::string bookNo = static_cast<std::string>(book);
	double revenue = static_cast<double>(book);
	std::cout << bookNo << " " << revenue << std::endl;
	return 0;
}