#include "13.39.h"
#include<utility>

// ���ⶨ�徲̬���ݳ�Աalloc
std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(const StrVec &s)
{
	// ����alloc_n_copy����ռ���������s��һ�����Ԫ��
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec & StrVec::operator=(const StrVec &rhs)
{
	// TODO: �ڴ˴����� return ���
	// ����alloc_n_copy�����ڴ棬��С��rhs�е�Ԫ��ռ�ÿռ�һ����
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
	chk_n_alloc();          // ȷ���пռ�������Ԫ��
	// ��first_freeָ���Ԫ���й���s�ĸ���
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
	// ����ռ䱣�������Χ�е�Ԫ��
	auto data = alloc.allocate(e - b);
	// ��ʼ��������һ��pair����pair��data��uninitialized_copy�ķ���ֵ����
	return{ data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	// ���ܴ��ݸ�deallocateһ����ָ�룬���elementsΪ0������ʲôҲ����
	if (elements)
	{
		// ��������Ԫ��
		for (auto p = first_free; p != elements;/*nothing*/)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	// ���ǽ����䵱ǰ��С�������ڴ�ռ�
	auto newcapacity = size() ? 2 * size() : 1;
	alloc_n_move(newcapacity);
}

void StrVec::alloc_n_move(size_t newcap)
{
	// �������ڴ�
	auto newdata = alloc.allocate(newcap);
	// �����ݴӾ��ڴ��ƶ������ڴ�
	auto dest = newdata;                 // ָ������������һ������λ��
	auto elem = elements;              // ָ�����������һ��Ԫ�ص�λ��
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();                                               // һ���ƶ�����ͷž��ڴ�ռ�
	// �������ݽṹ��ִ����Ԫ��
	elements = newdata;
	first_free = dest;
	cap = elements + newcap;
	
}
