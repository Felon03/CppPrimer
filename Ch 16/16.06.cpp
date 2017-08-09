#include "16.6_begin_end.h"
#include <iostream>

int main()
{
	char arr[]{ 'a','b','c','d','e','f','g','h' };
	std::cout << *begin(arr) << " " << *end(arr) << std::endl;
	return 0;
}