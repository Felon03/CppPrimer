#pragma once
/*������������ܣ���дһ���������캯�����������г�Ա��
	��Ĺ��캯��Ӧ�ö�̬����һ���µ�string���������󿽱���
	psָ���λ�ã�������ps�����λ��
*/
#include<string>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}
	// �������캯��
	HasPtr(const HasPtr &rhs) :
		ps(new std::string(*rhs.ps)), i(rhs.i) {}

private:
	std::string *ps;
	int i;
};