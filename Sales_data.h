#pragma once
/*ͷ�ļ���Ӧ�ð���using����*/
#include<string>
struct Sales_data
{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	// 7.2
	// ����³�Աcombine��isbn
	std::string isbn() { return bookNo; }
	Sales_data& combine(const Sales_data&);
};

// combine���庯��
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;			// ���ص��øĺ����Ķ���
}
