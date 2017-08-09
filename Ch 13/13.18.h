#pragma once
/* ����һ��Employee�࣬��������Ա��������Ψһ�Ĺ�Ա֤�š�
	Ϊ����ඨ��Ĭ�Ϲ��캯�����Լ�����һ����ʾ��Ա������string
	�Ĺ��캯����ÿ�����캯��Ӧ��ͨ������һ��static���ݳ�Ա��˵
	����һ��Ψһ��֤�š�
*/
#include<string>

class Employee {
public:
	Employee();
	Employee(std::string &n);

	const int id() const { return employee_id; }
private:
	std::string name;			// ����
	int employee_id;			// Ա�����
	static int  inc_id;			// static���ݳ�Ա����������Ψһ���
};