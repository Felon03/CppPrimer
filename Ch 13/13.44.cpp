#include "13.44.h"
#include<algorithm>

//std::allocator<char*> alloc;

String::String(const char *s)
{
	char *str = const_cast<char*>(s);  //const_cast�����Ƴ�const�޶��� 
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
	// TODO: �ڴ˴����� return ���
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
	// �����б�ΪʲôҪ��this����պ����ֲ�����������lambda�������ã�������λ�ڲ����б���
	// �����alloc�����static�ģ��Ϳ��Բ��ò���this
	std::for_each(elements, end, [this](char &c) {alloc.destroy(&c); });
	alloc.deallocate(elements, end - elements);
}
