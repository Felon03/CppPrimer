#include"14.27_28_StrBlob.h"
#include<iostream>

int main()
{
	StrBlob sb1{ "a", "b","c" };
	StrBlob sb2 = sb1;
	for (StrBlobPtr iter = sb1.begin(); iter != sb1.end(); ++iter)
		std::cout << iter.deref() << " ";
	std::cout << std::endl;

	sb2[0] = "Z";
	for (ConstStrBlobPtr iter = sb2.cbegin(); iter != sb2.cend(); ++iter)
		std::cout << iter.deref() << " ";
	std::cout << std::endl;

	return 0;
}