#include "13.44.h"
#include<algorithm>

//std::allocator<char*> alloc;

String::String(const char *s)
{
	char *str = const_cast<char*>(s);  //const_cast用来移除const限定符 
    // ref: http://www.cnblogs.com/ider/archive/2011/07/22/cpp_cast_operator_part2.html
	while (*str) ++str;
	range_initialize(s, ++str);
}

String::String(const String &rhs)
{
	range_initialize(rhs.elements, rhs.end);
}

String & String::operator=(const String &rhs)
{
	// TODO: 在此处插入 return 语句
	auto new_str = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = new_str.first;
	end = new_str.second;
	return *this;

}

String::~String()
{
	free();
}

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
	auto str = alloc.allocate(e - b);
	return { str, std::uninitialized_copy(b,e, str) };
}

void String::range_initialize(const char *b, const char *e)
{
	auto newstr = alloc_n_copy(b, e);
	elements = newstr.first;
	end = newstr.second;
}

void String::free()
{
	// 捕获列表为什么要加this：封闭函数局部变量不能在lambda体中引用，除非其位于捕获列表中
	// 如果把alloc定义成static的，就可以不用捕获this
	std::for_each(elements, end, [this](char &c) {alloc.destroy(&c); });
	alloc.deallocate(elements, end - elements);
}
