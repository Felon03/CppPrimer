#pragma once
/* 定义一个Employee类，它包含雇员的姓名和唯一的雇员证号。
	为这个类定义默认构造函数，以及接受一个表示雇员姓名的string
	的构造函数。每个构造函数应该通过递增一个static数据成员来说
	生成一个唯一的证号。
*/
#include<string>

class Employee {
public:
	Employee();
	Employee(std::string &n);

	const int id() const { return employee_id; }
private:
	std::string name;			// 姓名
	int employee_id;			// 员工编号
	static int  inc_id;			// static数据成员，用来生成唯一编号
};