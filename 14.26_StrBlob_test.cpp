#include"14.26_StrBlob.h"
#include<iostream>

int main()
{
	StrBlob sb1{ "a", "b", "c" };
	StrBlob sb2 = sb1;

	sb2[2] = "d";

	for (ConstStrBlobPtr iter = sb1.cbegin(); iter != sb1.cend(); iter.incr())
		std::cout << iter.deref() << " ";
	std::cout << std::endl;

	for (ConstStrBlobPtr iter = sb2.cbegin(); iter != sb2.cend(); iter.incr())
		std::cout << iter.deref() << " ";
	std::cout << std::endl;

	std::cout << std::boolalpha << (sb1 == sb2) << std::endl;

	StrBlob sb3 = sb1;
	std::cout << sb3[0] << " " << sb3[1] << " " << sb3[2] << std::endl;

	return 0;
}