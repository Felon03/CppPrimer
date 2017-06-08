#pragma once
/*为HasPtr类编写赋值运算符。类似拷贝构造函数
	你的赋值运算符应该将对象拷贝到ps指向的位置
*/
#include<string>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr& hp):
		ps(new std::string(*hp.ps)), i(hp.i) {}

	// 拷贝赋值运算符
	HasPtr& operator=(const HasPtr &hp)
	{
		//delete ps;
		ps = new std::string(*hp.ps);
		i = hp.i;
		return *this;
	}


private:
	std::string *ps;
	int i;
};