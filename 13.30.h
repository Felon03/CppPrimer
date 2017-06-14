#pragma once
/* Ϊ�����ֵ�汾��HasPtr��дswap��������������
	Ϊ���swap�������һ����ӡ��䣬ָ������ʲôʱ��ִ��
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