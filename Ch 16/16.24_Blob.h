#pragma once
/* 为Blob模板添加一个构造函数，接受两个迭代器*/

#include<memory>
#include<vector>

template<typename T> class Blob {
public:
	using value_type = T;
	using size_type = typename std::vector<T>::size_type;

	// constructors
	Blob();
	Blob(std::initializer_list<T> il);

	// constructor taking two iterators
	template<typename It>
	Blob(It b, It e);

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();

	T& back();
	T& operator[](size_type i);

	const T& back() const;
	const T& operator[](size_type i) const;

private:
	std::shared_ptr<std::vector<T>> data;
	// through msg if data[i] invalid
	void check(size_type i, const std::string &msg) const;
};

// default constructor
template<typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

// constructor taking initializer_list
template<typename T>
Blob<T>::Blob(std::initializer_list<T> il)
	: data(std::make_shared<std::vector<T>>(il)) {}

// constructor taking two iterators
template<typename T>
template<typename It>
Blob<T>::Blob(It b, It e)
	: data(std::make_shared<std::vector<T>>(b, e)) {}

template<typename T>
inline void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template<typename T>
inline T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
inline const T& Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
inline T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
inline const T& Blob<T>::operator[](size_type i) const
{
	check(i, "subscript out if range");
	return (*data)[i];
}



template<typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	deta->pop_back();
}