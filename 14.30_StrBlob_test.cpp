#include"14.30_StrBlob.h"
#include<iostream>

int main()
{
	StrBlob sb1{ "a", "b","c" };
	StrBlob sb2 = sb1;
	for (StrBlobPtr iter = sb1.begin(); iter != sb1.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;

	sb2[0] = "Zxy";
	sb2.push_back("cpp");
	for (ConstStrBlobPtr iter = sb2.cbegin(); iter != sb2.cend(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;

	ConstStrBlobPtr iter(sb2);
	std::cout << *iter << std::endl;
	std::cout << iter->size() << std::endl;

	return 0;
}