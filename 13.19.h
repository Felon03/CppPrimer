#pragma once
/* Employee����Ҫ�������Լ��Ŀ������Ƴ�Ա��
	�����Ҫ��Ϊʲô���������Ҫ��Ϊʲô��
	ʵ������ΪEmployee��Ҫ�Ŀ������Ƴ�Ա

	����Ҫ����ʵ�������У�employee�����ܿ�����
	����������û�������
*/
#include<string>

class Employee {
public:
	Employee();
	Employee(const std::string &n);
	Employee(const Employee&) = delete;				// ��ֹ����
	Employee &operator=(const Employee&) = delete;		// ��ֹ��ֵ

	const int id() const { return employee_id; }

private:
	std::string name;
	int employee_id;
	static int inc_id;
};
