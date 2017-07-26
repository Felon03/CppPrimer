#include "16.16_Vec.h"
#include<iostream>
#include<string>

int main()
{
	Vec<std::string> vec;
	vec.reserve(6);
	std::cout << "capacity(reserve to 6): " << vec.capacity() << std::endl;

	vec.reserve(4);
	std::cout << "capacity(reserve to 4): " << vec.capacity() << std::endl;

	vec.push_back("hello");
	vec.push_back("world");

	vec.resize(4);

	for (auto i = vec.begin(); i != vec.end(); ++i)
		std::cout << *i << std::endl;
	std::cout << "----------EOF-----------" << std::endl;

	vec.resize(1);
	std::cout << vec.size() << std::endl;
	vec.push_back("test");
	vec.push_back("test");
	vec.push_back("test");
	vec.push_back("test");
	vec.push_back("test");
	vec.push_back("test");
	std::cout << vec.size() << std::endl;

	for (auto i = vec.begin(); i != vec.end(); ++i)
		std::cout << *i << std::endl;
	std::cout << "-----------EOF-----------" << std::endl;
	

	Vec<std::string> vec_list{ "hello", "world", "cpp" };
	for (const auto &x : vec_list)
		std::cout << x << " ";
	std::cout << std::endl;

	const Vec<std::string> const_vec_list{ "hello", "world", "cpp" };
	if (vec_list == const_vec_list)
		for (const auto &str : const_vec_list) std::cout << str << " ";
	std::cout << std::endl;

	const Vec<std::string> const_vec_list_small{ "hello","world","dpp" };
	std::cout << std::boolalpha << (const_vec_list < const_vec_list_small) << std::endl;

	std::cout << const_vec_list_small[2] << std::endl;

	Vec<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	Vec<int> ivec1{ 1,2,3,4,5,6,7,8,1 };
	std::cout << std::boolalpha << (ivec < ivec1) << std::endl;

	return 0;
}