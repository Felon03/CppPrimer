#include "13.49_String.h"
#include<algorithm>

String::String(const char *s)
{
	char *sl = const_cast<char*>(s);
	while (*sl) ++sl;
	range_initialize(s, ++sl);
}

String::String(const String &rhs)
{
	range_initialize(rhs.elements, rhs.end);
}

String & String::operator=(const String &rhs)
{
	// TODO: �ڴ˴����� return ���
	auto newstr = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = newstr.first;
	end = newstr.second;
	return *this;
}

String::String(String &&s) noexcept
	:elements(s.elements), end(s.end)
{
	s.elements = s.end = nullptr;
}

String & String::operator=(String &&rhs) noexcept
{
	// TODO: �ڴ˴����� return ���
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		end = rhs.end;
		rhs.elements = rhs.end = nullptr;
	}
	return *this;
}

String::~String()
{
	free();
}

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
	auto str = alloc.allocate(e - b);
	return{ str, std::uninitialized_copy(b, e, str) };
}

void String::range_initialize(const char *b, const char *e)
{
	auto newstr = alloc_n_copy(b, e);
	elements = newstr.first;
	end = newstr.second;
}

void String::free()
{
	if (elements)
	{
		std::for_each(elements, end, [this](char &rhs) { alloc.destroy(&rhs); });
		alloc.deallocate(elements, end - elements);
	}
}
