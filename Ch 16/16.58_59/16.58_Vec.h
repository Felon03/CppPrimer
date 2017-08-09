#pragma once
/*
	16.58 为Vec类添加emplace_back函数
*/
#include<memory>
#include<initializer_list>
#include<algorithm>

template<typename T>
class Vec {
public:
	Vec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(std::initializer_list<T> il);
	Vec(const Vec &v);

	Vec& operator=(const Vec &rhs);

	~Vec();

	// members
	void push_back(const T &t);

	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }

	T* begin() const { return elements; }
	T* end() const { return first_free; }

	void reserve(size_t new_cap);

	void resize(size_t count);
	void resize(size_t count, const T &t);

	template<typename... Args> void emplace_back(Args&&...);


private:
	std::pair<T*, T*> alloc_n_copy(const T*, const T*);
	void chk_n_alloc()
	{
		if (size() == capacity()) reallocate();
	}
	void free();
	void reallocate();
	void alloc_n_move(size_t new_cap);
	void range_initialize(const T*, const T*);

	T* elements;
	T* first_free;
	T* cap;
	std::allocator<T> alloc;
};

template<typename T> Vec<T>::Vec(std::initializer_list<T> il)
{
	range_initialize(il.begin(), il.end());
}

template<typename T> Vec<T>::Vec(const Vec &v)
{
	range_initialize(v.begin(), v.end());
}

template<typename T> Vec<T>& Vec<T>::operator=(const Vec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template<typename T> Vec<T>::~Vec()
{
	free();
}

template<typename T> void Vec<T>::push_back(const T &t)
{
	chk_n_alloc();
	alloc.construct(first_free++, t);
}

template<typename T> void Vec<T>::reserve(size_t new_cap)
{
	if (new_cap < capacity()) return;
	alloc_n_move(new_cap);
}

template<typename T> void Vec<T>::resize(size_t count)
{
	resize(count, T());
}

template<typename T> void Vec<T>::resize(size_t count, const T &t)
{
	if (count > size())
	{
		if (count > capacity()) reserve(count * 2);
		for (size_t i = size(); i != count; ++i)
			alloc.construct(first_free++, t);
	}
	else if (count < size())
	{
		while (first_free != elements + count)
			alloc.destroy(--first_free);
	}
}

template<typename T> std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
	auto data = alloc.allocate(e - b);
	return{ data, std::uninitialized_copy(b,e,data) };
}

template<typename T> void Vec<T>::free()
{
	if (elements)
	{
		std::for_each(elements, first_free,
			[this](T &rhs) {return alloc.destroy(&rhs); });
	}
}

template<typename T> void Vec<T>::reallocate()
{
	auto newcapacity = size() ? size() * 2 : 1;
	alloc_n_move(newcapacity);
}

template<typename T> void Vec<T>::alloc_n_move(size_t new_cap)
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

template<typename T> void Vec<T>::range_initialize(const T *b, const T *e)
{
	auto newdata = alloc_n_copy(b, e);	
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template<typename T>
template<typename ...Args>
inline void Vec<T>::emplace_back(Args&&... args)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}
