#include"16.58_StrVec.h"
#include<algorithm>

StrVec::StrVec(std::initializer_list<std::string> il)
{
	range_initialize(il.begin(), il.end());
}

StrVec::StrVec(const StrVec &rhs)
{
	range_initialize(rhs.begin(), rhs.end());
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec::StrVec(StrVec &&rhs) noexcept
	: elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
	rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
	if (&rhs != this)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

StrVec::~StrVec()
{
	free();
}

StrVec& StrVec::operator=(std::initializer_list<std::string> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::reserve(size_t new_cap)
{
	if (new_cap < capacity()) return;
	alloc_n_move(new_cap);
}

void StrVec::resize(size_t count)
{
	resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string &s)
{
	if (count > size())
	{
		if (count > capacity()) reserve(count * 2);
		for (size_t i = size(); i != count; ++i)
			alloc.construct(first_free++, s);
	}
	else if (count < size())
	{
		while (first_free != elements + count)
			alloc.destroy(--first_free);
	}
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	// std::uninitialized_copy(first, last, result);
	// reference: http://www.cplusplus.com/reference/memory/uninitialized_copy/?kw=uninitialized_copy
	// Parameters
	// first: Input iterator to the initial position in a sequence to be copied
	// last: Input iterator to the final position in a sequence to be copied
	// result:  Output iterator to the initial position in the uninitialized destination sequence.
	// 
	// Reutrn value
	// An iterator to the last element of the destination sequence where elements have been copied
	auto data = alloc.allocate(e - b);
	return{ data, std::uninitialized_copy(b,e,data) };
}

void StrVec::free()
{
	if (elements)
	{
		std::for_each(elements, first_free,
			[this](std::string &rhs) {return alloc.destroy(&rhs); });
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? size() * 2 : 1;
	alloc_n_move(newcapacity);
}

void StrVec::alloc_n_move(size_t new_cap)
{
	auto newdata = alloc.allocate(new_cap);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + new_cap;
}

void StrVec::range_initialize(const std::string *b, const std::string *e)
{
	auto newdata = alloc_n_copy(b, e);
	elements = newdata.first;
	first_free = cap = newdata.second;
}