#pragma once
/* 为你的类值版本的HasPtr编写swap函数，并测试它
	为你的swap函数添加一个打印语句，指出函数什么时候执行
*/
#include<string>
#include<iostream>

class HasPtr {
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const std::string &s = std::string())
		: ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr &rhs)
		:ps(new std::string(*rhs.ps)), i(rhs.i) {}

	HasPtr& operator=(const HasPtr &rhs)
	{
		auto new_ps = new std::string(*rhs.ps);
		delete ps;
		ps = new_ps;
		i = rhs.i;
		return *this;
	}

	void show() { std::cout << *ps << std::endl; }

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
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "call swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
}