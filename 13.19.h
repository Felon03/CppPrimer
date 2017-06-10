#pragma once
/* Employee类需要定义它自己的拷贝控制成员吗？
	如果需要，为什么？如果不需要，为什么？
	实现你认为Employee需要的拷贝控制成员

	不需要，在实际生活中，employee并不能拷贝，
	拷贝控制是没有意义的
*/
#include<string>

class Employee {
public:
	Employee();
	Employee(const std::string &n);
	Employee(const Employee&) = delete;				// 阻止拷贝
	Employee &operator=(const Employee&) = delete;		// 阻止赋值

	const int id() const { return employee_id; }

private:
	std::string name;
	int employee_id;
	static int inc_id;
};
