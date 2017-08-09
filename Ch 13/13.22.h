#pragma once
/* 假定我们希望HasPtr的行为像一个值。即，对于对象所指向的string成员，
每个对象都有一份自己的拷贝。为HasPtr编写拷贝构造函数和拷贝赋值运算符
*/
#include<string>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr &p) :
		ps(new std::string(*p.ps)), i(p.i) {}

	HasPtr &operator=(const HasPtr &p)
	{
		auto new_ps = new std::string(*p.ps);
		delete ps;
		ps = new_ps;
		i = p.i;
		return *this;
	}

	// 不要忘了析构函数！
	~HasPtr()
	{
		delete ps;
	}

private:
	std::string *ps;
	int i;

};