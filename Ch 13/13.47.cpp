#include "13.47.h"
#include<algorithm>
#include<iostream>

String::String(const char *rhs)
{
	char *lhs = const_cast<char*>(rhs);
	while (*lhs) ++lhs;
	range_initialize(rhs, ++lhs);
}

String::String(const String &rhs)
{
	range_initialize(rhs.elements, rhs.end);
	std::cout << "Copy constructor" << std::endl;
}

String & String::operator=(const String &rhs)
{
	// TODO: 在此处插入 return 语句
	auto str = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = str.first;
	end = str.second;
	std::cout << "copy-assignment" << std::endl;
	return *this;
	
}

String::~String()
{
	free();
}

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
	auto str = alloc.allocate(e - b);
	return { str, std::uninitialized_copy(b,e,str) };
}

void String::range_initialize(const char *b, const char *e)
{
	auto newstr = alloc_n_copy(b, e);
	elements = newstr.first;
	end = newstr.second;
}

void String::free()
{
	std::for_each(elements, end, [this](char &c) {alloc.destroy(&c); });
	alloc.deallocate(elements, size());
}
