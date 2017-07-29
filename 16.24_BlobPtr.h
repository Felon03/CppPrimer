#pragma once
#include "16.24_Blob.h"
#include <memory>
#include <vector>

template<typename> class BlobPtr;

template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template<typename T>
bool operator<(const BlboPtr<T> &lhs, const BlobPtr<T> &rhs);

template<typename T> class BlobPtr {
	friend bool operator==<T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
	friend bool operator< <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

public:
	BlobPtr() : curr(0) {}
	BlobPtr(Blob<T> &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

	T& operator*() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}

	// prefix
	BlobPtr& operator++();
	BlobPtr& operator--();

	//postfix
	BlobPtr operator++(int);
	BlobPtr operator--(int);


private:
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;

	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

// prefix ++
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of Blob");
	++curr;
	return *this;
}

// prefix --
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	check(curr, "decrement past begin of Blob");
	return *this;
}

// postfix ++
template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}

// postfix --
template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}

template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.curr == rhs.curr;
}

template<typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.curr < rhs.curr;
}