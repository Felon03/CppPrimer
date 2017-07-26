#include"16.12_Blob.h"
#include<iostream>
#include<string>

int main()
{
	Blob<std::string> sb1{ "a", "b", "c" };
	Blob<std::string> sb2 = sb1;

	sb2[2] = "d";

	for (ConstBlobPtr<std::string> iter = sb1.cbegin(); iter != sb1.cend(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;

	for (ConstBlobPtr<std::string> iter = sb2.cbegin(); iter != sb2.cend(); ++iter)
		std::cout <<*iter << " ";
	std::cout << std::endl;

	std::cout << std::boolalpha << (sb1 == sb2) << std::endl;

	Blob<std::string> sb3 = sb1;
	std::cout << sb3[0] << " " << sb3[1] << " " << sb3[2] << std::endl;
	//for (ConstBlobPtr<std::string> iter = sb3.cbegin(); iter != sb3.cend(); ++iter)
	//	std::cout << *iter << " ";
	//std::cout << std::endl;

	return 0;
}