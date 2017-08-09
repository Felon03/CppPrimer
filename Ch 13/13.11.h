#pragma once
/*Ϊǰ���HasPtr�������һ����������*/
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
	}		// ����ָ��Ҫ�ֶ�delete!!

private:
	std::string *ps;
	int i;
};
