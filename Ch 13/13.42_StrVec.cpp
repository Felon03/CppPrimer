#include"13.42_StrVec.h"
#include<utility>
#include<algorithm>

// 静态成员变量需进行初始化，在类中声明静态成员，但没有定义
// 因此需要在类外进行定义操作（没有定义就会出现LINK 200的错误 [VS2015]）
// 错误信息： 无法解析的外部符号
std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(std::initializer_list<std::string> il)
{
	range_initialize(il.begin(), il.end());
}

StrVec::StrVec(const StrVec &s)
{
	range_initialize(s.begin(), s.end());
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
		if (count > capacity())
			reserve(count * 2);
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
	auto data = alloc.allocate(e - b);
	return{ data, std::uninitialized_copy(b,e,data) };
}

//void StrVec::free()
//{
//	if (elements)
//	{
//		for (auto p = first_free; p != elements;)
//			alloc.destroy(--p);
//		alloc.deallocate(elements, cap - elements);
//	}
//}

// 使用for_each 和 lambda表达式重写free函数(13.43)
void StrVec::free()
{
	// for_each包含在algorithm头文件中，要使用for_each需要把改头文件include进去
	// 使用for_each和lambda表达式更好，因为他不涉及到递减的问题，也不会有超出边界的问题了
	std::for_each(elements, first_free, [](std::string &rhs) {alloc.destroy(&rhs); });
	alloc.deallocate(elements, cap - elements);
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

void StrVec::range_initialize(const std::string *b, const std::string *e)
{
	auto newdata = alloc_n_copy(b, e);
	elements = newdata.first;
	first_free = cap = newdata.second;
}