#pragma once
/*ΪHasPtr���д��ֵ����������ƿ������캯��
	��ĸ�ֵ�����Ӧ�ý����󿽱���psָ���λ��
*/
#include<string>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr& hp):
		ps(new std::string(*hp.ps)), i(hp.i) {}

	// ������ֵ�����
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