#pragma once
/*为前面的HasPtr函数添加一个析构函数*/
#include<string>
#include<iostream>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr &hp) :
		ps(new std::string(*hp.ps)), i(hp.i) {}

	HasPtr &operator=(const HasPtr &hp)
	{
		ps = new std::string(*hp.ps);
		i = hp.i;
		return *this;
	}

	~HasPtr()
	{ 
		std::cout << "destructor called." << std::endl;
		delete ps;
	}		// 内置指针要手动delete!!

private:
	std::string *ps;
	int i;
};
