#include "14.16_StrVec.h"
#include<algorithm>

StrVec::StrVec(std::initializer_list<std::string> il)
{
	range_initialize(il.begin(), il.end());
}

StrVec::StrVec(const StrVec &rhs)
{
	range_initialize(rhs.begin(), rhs.end());
}

StrVec & StrVec::operator=(const StrVec &rhs)
{
	// TODO: 在此处插入 return 语句
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec::StrVec(StrVec &&rhs) noexcept
	:elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
	rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

StrVec & StrVec::operator=(StrVec &&rhs) noexcept
{
	// TODO: 在此处插入 return 语句
	if (this != &rhs)
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

void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::reserve(size_t new_cap)
{
	if (new_cap <= capacity()) return;
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
		while (first_free != elements + count) alloc.destroy(--first_free);
	}
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *begin, const std::string *end)
{
	auto data = alloc.allocate(end - begin);
	return{ data, std::uninitialized_copy(begin, end, data) };
}

void StrVec::free()
{
	if (elements)
	{
		std::for_each(elements, first_free,
			[this](std::string &rhs) {alloc.destroy(&rhs); });
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
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

void StrVec::range_initialize(const std::string *begin, const std::string *end)
{
	auto newdata = alloc_n_copy(begin, end);
	elements = newdata.first;
	first_free = cap = newdata.second;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
	//return lhs.elements == rhs.elements &&
	//	lhs.first_free == rhs.first_free &&
	//	lhs.cap == rhs.cap;
	return (lhs.size() == rhs.size() &&
		std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs == rhs);
}
