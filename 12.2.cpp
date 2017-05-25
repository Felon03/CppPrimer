/*test of class StrBlob*/
#include<iostream>
#include"12.2.h"


int main()
{
	StrBlob b1, b2 = { "a", "an", "the" };
	b1 = b2;
	std::cout << "b1 = b2" << std::endl;
	std::cout << b1.front() << " " << b1.back() << std::endl;
	b2.push_back("about");
	std::cout << "b2.push_back(\"about\")" << std::endl;
	std::cout << b1.back() << " " << b2.back() << std::endl;
	b1.pop_back();
	std::cout << "b1.pop_back()" << std::endl;
	std::cout << b1.back() << " " << b2.back() << std::endl;
	std::cout << b1.size() << " " << std::endl;

	return 0;
	
}