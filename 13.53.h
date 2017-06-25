#pragma once
/* 为HasPtr实现一个拷贝赋值运算符和移动赋值运算符*/
#include<string>
#include<iostream>

class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string &s = std::string());
	HasPtr(const HasPtr &rhs);
	HasPtr(HasPtr &&rhs) noexcept;
	//HasPtr& operator=(HasPtr rhs);
	 HasPtr& operator=(const HasPtr &rhs);
	 HasPtr& operator=(HasPtr &&rhs) noexcept;
	~HasPtr();

private:
	std::string *ps;
	int i;
};