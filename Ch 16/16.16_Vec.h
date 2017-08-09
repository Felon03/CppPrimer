#pragma once
/*
	将StrVec类(参见13.5节，第465页)重写为模板，命名为Vec
*/
#include <memory>
#include <initializer_list>
#include <algorithm>

template<typename> class Vec;

template<typename T> bool operator==(const Vec<T>&, const Vec<T>&);
template<typename T> bool operator!=(const Vec<T>&, const Vec<T>&);
template<typename T> bool operator<(const Vec<T>&, const Vec<T>&);
template<typename T> bool operator>(const Vec<T>&, const Vec<T>&);
template<typename T> bool operator<=(const Vec<T>&, const Vec<T>&);
template<typename T> bool operator>=(const Vec<T>&, const Vec<T>&);

template<typename T> class Vec {
	friend bool operator==<T>(const Vec<T>&, const Vec<T>&);
	friend bool operator!=<T>(const Vec<T>&, const Vec<T>&);
	friend bool operator< <T>(const Vec<T>&, const Vec<T>&);
	friend bool operator> <T>(const Vec<T>&, const Vec<T>&);
	friend bool operator<=<T>(const Vec<T>&, const Vec<T>&);
	friend bool operator>=<T>(const Vec<T>&, const Vec<T>&);

public:
	Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(std::initializer_list<T>);
	Vec(const Vec<T>&);
	Vec& operator=(const Vec<T>&);
	Vec(Vec<T>&&) noexcept;
	Vec& operator=(Vec<T>&&) noexcept;
	~Vec();

	void push_back(const T&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	T* begin() const { return elements; }
	T* end() const { return first_free; }

	T& at(size_t pos) { return *(elements + pos); }
	const T& at(size_t pos) const { return *(elements + pos); }

	T& operator[](size_t n) { return elements[n]; }
	const T& operator[] (size_t n) const { return elements[n]; }

	void reserve(size_t new_cap);
	void resize(size_t count);
	void resize(size_t count, const T&);

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

// 重载运算符
template<typename T> bool operator==(const Vec<T> &lhs, const Vec<T> &rhs)
{
	return (lhs.size() == rhs.size() &&
		std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template<typename T> bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs)
{
	return !(lhs == rhs);
}

template<typename T> bool operator<(const Vec<T> &lhs, const Vec<T> &rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(),
		rhs.begin(), rhs.end());
}

template<typename T> bool operator>(const Vec<T> &lhs, const Vec<T> &rhs)
{
	return rhs < lhs;
}

template<typename T> bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs)
{
	return !(lhs > rhs);
}

template<typename T> bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs)
{
	return !(rhs > lhs);
}

// 成员函数
template<typename T> Vec<T>::Vec(std::initializer_list<T> il)
{
	range_initialize(il.begin(), il.end());
}

template<typename T> Vec<T>::Vec(const Vec<T> &rhs)
{
	range_initialize(rhs.begin(), rhs.end());
}

template<typename T> Vec<T>& Vec<T>::operator=(const Vec<T> &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template<typename T> Vec<T>::Vec(Vec<T> &&rhs) noexcept
	:elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
	rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

template<typename T> Vec<T>& Vec<T>::operator=(Vec<T> &&rhs) noexcept
{
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


template<typename T> Vec<T>::~Vec()
{
	free();
}

template<typename T> void Vec<T>::push_back(const T &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
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

template<typename T> void Vec<T>::resize(size_t count, const T &s)
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
	auto newcapacity = size() ? 2 * size() : 1;
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