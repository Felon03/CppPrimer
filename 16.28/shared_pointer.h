#pragma once
/*
    16.28  编写你自己的shared_ptr和unique_ptr
*/
#include "DebugDelete.h"
#include <functional>

//
// shared_pointer customized shared_ptr
//

template<typename> class shared_pointer;
template<typename T> void swap(shared_pointer<T>& lhs, shared_pointer<T>& rhs);

template<typename T>
class shared_pointer {
	friend void swap<T>(shared_pointer<T>& lhs, shared_pointer<T>& rhs);

public:
	shared_pointer() = default;
	// constructor taking raw pointer
	// set the refCount as 1
	explicit shared_pointer(T* up, std::function<void(T*)> d = DebugDelete())
		: ptr(up), refCount(new std::size_t(1)), deleter(d) {}

	// copy constructor
	// increment refCount for each copy
	shared_pointer(const shared_pointer &rhs)
		: ptr(rhs.ptr), refCount(rhs.refCount), deleter(rhs.deleter)
	{
		++*refCount;
	}
	// move constructor
	shared_pointer(shared_pointer &&rhs) noexcept;

	// copy assignment
	shared_pointer& operator=(const shared_pointer &rhs);
	// move assignment
	shared_pointer& operator=(shared_pointer &&rhs) noexcept;

	// conversion opeator
	operator bool() const { return ptr ? true : false; }

	// dereference
	T& operator*() const { return *ptr; }
	
	// arrow
	T* operator->() const { return &this->operator*(); }

	// return uesCount
	std::size_t use_count() const { return *refCount; }

	// get teh underlying pointer
	T* get() const noexcept { return ptr; }

	// check if the unique user
	bool unique() const noexcept { return *refCount == 1; }

	// swap
	void swap(shared_pointer &rhs) { ::swap(*this, rhs); }

	// if unique user, free the object pointed to
	void reset() noexcept { decrement_n_destroy(); }

	// make ptr point where p pointing and create a new count for it
	void reset(T* p)
	{
		if (ptr != p)
		{
			decrement_n_destroy();
			ptr = p;
			refCount = new std::size_t(1);
		}
	}

	// reset to point where p is pointing and change deleter to d
	void reset(T* p, const std::function<void(T*)> &d)
	{
		reset(p);
		deleter = d;
	}

	// destructor
	~shared_pointer()
	{
		decrement_n_destroy();
	}



private:
	T* ptr = nullptr;
	std::size_t* refCount = new std::size_t(0);

	// any functor lambda or function pointer that matched this
	// can replace the default one at run time
	std::function<void(T*)> deleter{ DebugDelete() };

	void decrement_n_destroy();
};

template<typename T>
void swap(shared_pointer<T> &lhs, shared_pointer<T> &rhs)
{
	using std::swap;
	swap(lhs.ptr, rhs.ptr);
	swap(lhs.refCount, rhs.refCount);
	swap(lhs.deleter, rhs.deleter);
}

// move constructor
template<typename T>
shared_pointer<T>::shared_pointer(shared_pointer<T> &&rhs) noexcept
	: ptr(rhs.ptr), refCount(rhs.refCount), deleter(std::move(rhs.deleter))
{
	rhs.ptr = nullptr;
	rhs.refCount = nullptr;
}

// copy assignment
template<typename T>
inline shared_pointer<T>& shared_pointer<T>::operator=(const shared_pointer<T> &rhs)
{
	// incerement rhs.refCount first to ensure safty when self-assignment
	++*rhs.refCount;

	// for lhs
	decrement_n_destroy();

	// copy data structure from rhs to this
	ptr = rhs.ptr;
	refCount = rhs.refCount;
	deleter = rhs.deleter;

	return *this;
}

// move assignment
template<typename T>
inline shared_pointer<T>& shared_pointer<T>::operator=(shared_pointer<T> &&rhs) noexcept
{
	// for lhs
	decrement_n_destroy();

	// swap two sides
	::swap(*this, rhs);
	
	std::cout << "shared_pointer::move=\n";
	return *this;
}

template<typename T>
inline std::ostream& operator<<(std::ostream &os, const shared_pointer<T> &rhs)
{
	os << rhs.get();
	return os;
}

// utilities for decrement and delete using deleter
template<typename T>
inline void shared_pointer<T>::decrement_n_destroy()
{
	if (ptr)
	{
		if (--*refCount == 0)
		{
			delete refCount;
			deleter(ptr);
		}
		refCount = nullptr;
		ptr = nullptr;
	}
}