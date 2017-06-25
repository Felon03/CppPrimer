#pragma once
/* ΪHasPtrʵ��һ��������ֵ��������ƶ���ֵ�����*/
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