#include"14.26_StrVec.h"
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

	StrVec vec_list{ "hello", "world", "Cpp" };
	for (auto i = vec_list.begin(); i != vec_list.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	const StrVec const_vec_list{ "hello", "world", "Cpp" };
	if (vec_list == const_vec_list)
		for (const auto &x : vec_list)
			std::cout << x << " ";
	std::cout << std::endl;

	const StrVec const_vec_list_small{ "hello", "world", "Bpp" };
	std::cout << std::boolalpha << (const_vec_list_small < const_vec_list) << std::endl;

	std::initializer_list<std::string> il{ "Hello", "welcome", "to", "Cpp" };
	StrVec ini_vec = il;
	for (auto const &x : ini_vec)
		std::cout << x << " ";
	std::cout << std::endl;

	std::cout << ini_vec[1] << std::endl;

	return 0;
}