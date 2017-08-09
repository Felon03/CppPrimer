#include "13.39.h"
#include<utility>

// 类外定义静态数据成员alloc
std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(const StrVec &s)
{
	// 调用alloc_n_copy分配空间以容纳与s中一样多的元素
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec & StrVec::operator=(const StrVec &rhs)
{
	// TODO: 在此处插入 return 语句
	// 调用alloc_n_copy分配内存，大小与rhs中的元素占用空间一样多
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
	chk_n_alloc();          // 确保有空间容纳新元素
	// 在first_free指向的元素中构造s的副本
	alloc.construct(first_free++, s);
}

void StrVec::reverse(size_t newcap)
{
	if (newcap <= capacity()) return;
	alloc_n_move(newcap);
}

void StrVec::resize(size_t count)
{
	resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string &s)
{
	if (count > size())
	{
		if (count > capacity()) reverse(count * 2);
		for (size_t i = size(); i != count * 2; ++i)
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
	// 分配空间保存给定范围中的元素
	auto data = alloc.allocate(e - b);
	// 初始化并返回一个pair，改pair由data和uninitialized_copy的返回值构成
	return{ data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	// 不能传递给deallocate一个空指针，如果elements为0，函数什么也不做
	if (elements)
	{
		// 逆序销毁元素
		for (auto p = first_free; p != elements;/*nothing*/)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	// 我们将分配当前大小两倍的内存空间
	auto newcapacity = size() ? 2 * size() : 1;
	alloc_n_move(newcapacity);
}

void StrVec::alloc_n_move(size_t newcap)
{
	// 分配新内存
	auto newdata = alloc.allocate(newcap);
	// 将数据从旧内存移动到新内存
	auto dest = newdata;                 // 指向新数组中下一个空闲位置
	auto elem = elements;              // 指向旧数组中下一个元素的位置
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();                                               // 一旦移动完就释放旧内存空间
	// 更新数据结构，执行新元素
	elements = newdata;
	first_free = dest;
	cap = elements + newcap;
	
}
