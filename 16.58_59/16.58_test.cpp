#include "16.58_StrVec.h"
#include "16.58_Vec.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
	StrVec svec;
	svec.reserve(6);

	std::cout << "capacity(reserve to 6): " << svec.capacity() << std::endl;

	svec.emplace_back(10, 'c');
	std::string s1 = "hello", s2 = "World";
	svec.emplace_back(s1 + s2);
	svec.emplace_back(s1);
	for (auto i = svec.begin(); i != svec.end(); ++i)
		std::cout << *i << " ";
	std::cout << "\n";
	std::cout << "size: " << svec.size() << std::endl;
	std::cout << "capacity: " << svec.capacity() << std::endl;

	Vec<int> ivec{ 1,2,3,4,5,6,7,8,9,10 };
	//Vec<std::string> ivec;
	ivec.reserve(10);
	
	//std::vector<int> vec;
	//vec.emplace_back(10);
	//for (const auto &x : vec)
	//	std::cout << x << "\n";
	
	std::cout << "capacity(reserve to 10): " << ivec.capacity() << std::endl;
	int a = 42, b = 42;
	std::initializer_list<int> il{ 1,2,3,4,5,6,7,8,9 };
	ivec.emplace_back(a + b);
	for (auto i = ivec.begin(); i != ivec.end(); ++i)
		std::cout << *i << " ";
	std::cout << "\n";
	std::cout << "capacity: " << ivec.capacity() << std::endl;

	return 0;
}