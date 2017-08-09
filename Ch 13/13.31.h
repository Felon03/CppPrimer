#pragma once
/* Ϊ���HasPtr�ඨ��һ��<�������������һ��HasPtr��vector
	Ϊ���vector���һЩԪ�أ�������ִ��sort��ע���ʱ�����swap
*/
#include<string>
#include<iostream>

class HasPtr {
public:
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);
	HasPtr(const std::string &s = std::string())
		: ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &rhs)
		: ps(new std::string(*rhs.ps)), i(rhs.i) {}
	HasPtr& operator=(HasPtr rhs)
	{
		swap(rhs);
		return *this;
	}

	void show() const
	{
		std::cout << *ps << std::endl;
	}

	void swap(HasPtr &rhs)
	{
		using std::swap;
		swap(ps, rhs.ps);
		swap(i, rhs.i);
		std::cout << "call swap(HasPtr &rhs)" << std::endl;
	}

	~HasPtr()
	{
		delete ps;
	}

private:
	std::string *ps;
	int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	lhs.swap(rhs);
}

inline bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
	std::cout << "call bool operator<(const HasPtr&, const HasPtr&)" << std::endl;
	return *lhs.ps < *rhs.ps;
}