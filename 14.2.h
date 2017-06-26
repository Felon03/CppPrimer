#pragma once
/* ΪSales_data��д���ص����롢������ӷ��͸��ϸ�ֵ�����*/
#include<string>
#include<iostream>

class Sales_data {
	// ���������
	friend std::istream& operator >> (std::istream&,Sales_data&);		// >>
	friend std::ostream& operator<<(std::ostream&, Sales_data&);	// <<
	friend Sales_data operator+(const Sales_data&, const Sales_data&);	// +
public:
	Sales_data(const std::string &s, unsigned n, double p)
		:bookNo(s), units_sold(n), revenue(p) {}
	Sales_data() :Sales_data("", 0, 0.0f) {}
	Sales_data(const std::string &s) :Sales_data(s, 0, 0.0f) {}
	Sales_data(std::istream &is);

	// ����+=�����
	Sales_data& operator+=(const Sales_data&);
	std::string isbn() { return bookNo; }
private:
	inline double avg_price() const;

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

std::istream& operator >> (std::istream &is, const Sales_data &rhs);
std::ostream& operator<<(std::ostream &os, const Sales_data &rhs);
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

inline double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}