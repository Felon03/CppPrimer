#include"14.16_StrBlob.h"
#include<iostream>

int main()
{
	StrBlob sb{ "Hello", "World", "Exec14.16_StrBlob" };
	StrBlob sb1{ "Hello", "World", "Exec" };
	for (ConstStrBlobPtr iter = sb.cbegin(); iter != sb.cend(); iter.incr())
	{
		std::cout << iter.deref() << " ";
	}
	std::cout << std::endl;
	std::cout << std::boolalpha << (sb == sb1) << std::endl;

	return 0;
}