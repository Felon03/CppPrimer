#include"14.16_StrVec.h"
#include<iostream>

int main()
{
	StrVec svec;
	svec.reserve(6);
	std::cout << "capacity(reserve to 6): " << svec.capacity() << std::endl;

	svec.reserve(4);
	std::cout << "capacity(reserve to 4): " << svec.capacity() << std::endl;

	svec.push_back("Hello");
	svec.push_back("C plus plus");

	svec.resize(4);

	for (auto i = svec.begin(); i != svec.end(); ++i)
		std::cout << *i << std::endl;
	std::cout << "===End of StrVec===" << std::endl;

	svec.resize(1);

	for (auto i = svec.begin(); i != svec.end(); ++i)
		std::cout << *i << std::endl;
	std::cout << "===End of StrVec===" << std::endl;

	StrVec vec1{ "Hello", "World", "C++" };
	for (auto i = vec1.begin(); i != vec1.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	const StrVec csvec{ "Hello", "World", "C++" };
	if (vec1 == csvec)
		for (const auto &str : csvec) std::cout << str << " ";
	std::cout << std::endl;


}