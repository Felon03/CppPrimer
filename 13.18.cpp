#include "13.18.h"

// 定义类静态数据成员的方式和在类的外部定义成员函数差不多
// 需要指定对象的类型名，然后是类名、左右与运算符以及成员自己的名字
int Employee::inc_id = 1000;		// 设置递增编号初始值为1000


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


