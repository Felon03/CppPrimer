#pragma once
/* �ٶ�����ϣ��HasPtr����Ϊ��һ��ֵ���������ڶ�����ָ���string��Ա��
ÿ��������һ���Լ��Ŀ�����ΪHasPtr��д�������캯���Ϳ�����ֵ�����
*/
#include<string>

class HasPtr {
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr &p):
		ps(new std::string(*p.ps)), i(p.i) {}

	HasPtr &operator=(const HasPtr &p)
	{
		auto new_ps = new std::string(*p.ps);
		delete ps;
		ps = new_ps;
		i = p.i;
		return *this;
	}

	// ��Ҫ��������������
	~HasPtr()
	{
		delete ps;
	}

private:
	std::string *ps;
	int i;

};