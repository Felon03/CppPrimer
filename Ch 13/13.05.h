#pragma once
/*给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。
	你的构造函数应该动态分配一个新的string，并将对象拷贝到
	ps指向的位置，而不是ps本身的位置
*/
#include<string>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}
	// 拷贝构造函数
	HasPtr(const HasPtr &rhs) :
		ps(new std::string(*rhs.ps)), i(rhs.i) {}

private:
	std::string *ps;
	int i;
};