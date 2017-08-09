#include"14.18_StrVec.h"
#include<iostream>

int main()
{
	StrVec vec;
	vec.reserve(6);
	std::cout << "capacity(reserve to 6): " << vec.capacity() << std::endl;

	vec.reserve(4);
	std::cout << "capacity(reserve to 4): " << vec.capacity() << std::endl;

	vec.push_back("hello");
	vec.push_back("world");

	vec.resize(4);

	for (auto i = vec.begin(); i != vec.end(); ++i)
		std::cout << *i << std::endl;
	std::cout << "===End of StrVec===" << std::endl;

	vec.resize(1);
	
	for (auto i = vec.begin(); i != vec.end(); ++i)
		std::cout << *i << std::endl;
	std::cout << "===End of StrVec===" << std::endl;

	StrVec svec1{ "Hello", "World", "C Plus Plus" };

	for (auto i = svec1.begin(); i != svec1.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	// operator ==
	const StrVec cvec{ "Hello", "World", "C Plus Plus" };
	if (cvec == svec1)
		for (const auto &str : cvec)
			std::cout << str << " ";
	std::cout << std::endl;

	// operator <
	const StrVec cvec1{ "Hello", "World", "B++" };
	std::cout << std::boolalpha << (cvec < cvec1) << std::endl;

	return 0;
}