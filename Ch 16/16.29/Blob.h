#pragma once
/*
     16.29 修改Blob类，使用你自己的shared_pointer代替标准库中的版本
*/
#include"shared_pointer.h"
#include <vector>
#include <memory>

//
// Blob manage a vector through a shared_pointer
//

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

	// number of elements in the Blob
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	
	// element access
	T& back();
	T& operator[](size_type i);

	const T& back() const;
	const T& operator[](size_type i) const;

private:
	//std::shared_ptr<std::vector<T>> data;
	shared_pointer<std::vector<T>> data;

	// throw msg if daata[i] invalid
	void check(size_type i, const std::string &msg) const;
};

// default constructor
template<typename T>
Blob<T>::Blob()
	: data(std::make_shared<std::vector<T>>())
{

}

// constructor taking initializer_list
template<typename T>
Blob<T>::Blob(std::initializer_list<T> il)
	: data(std::make_shared<std::vector<T>>(il))
{

}

// constructor taking two iterators
template<typename T>
template<typename It>
Blob<T>::Blob(It b, It e)
	: data(std::make_shared<std::vector<T>>(b, e))
{

}

template<typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template<typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
T& Blob<T>::operator[](size_type i)
{
	// if i is too big, check function will throw, preventing access to a nonexistent element
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
const T& Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
const T& Blob<T>::operator[](size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}