#include "13.18.h"

// �����ྲ̬���ݳ�Ա�ķ�ʽ��������ⲿ�����Ա�������
// ��Ҫָ���������������Ȼ����������������������Լ���Ա�Լ�������
int Employee::inc_id = 1000;		// ���õ�����ų�ʼֵΪ1000


Employee::Employee()
{
	Employee::inc_id = 0;
	employee_id = ++inc_id;
}

Employee::Employee(std::string & n)
{
	name = n;
	employee_id = ++inc_id;
}


