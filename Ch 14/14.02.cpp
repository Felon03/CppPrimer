#include "14.2.h"

std::istream & operator >> (std::istream &is, Sales_data &rhs)
{
	// TODO: 在此处插入 return 语句
	double price = 0.0;
	is >> rhs.bookNo >> rhs.units_sold >> price;
	if (is)
		rhs.revenue = price*rhs.units_sold;
	else
		rhs = Sales_data();
	return is;
}

std::ostream & operator<<(std::ostream &os, const Sales_data &rhs)
{
	// TODO: 在此处插入 return 语句
	os << rhs.isbn() << " " << rhs.units_sold << " " << rhs.revenue << " "
		<< rhs.avg_price();
	return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

Sales_data::Sales_data(std::istream &is)
{
	is >> *this;
}

Sales_data & Sales_data::operator+=(const Sales_data &rhs)
{
	// TODO: 在此处插入 return 语句
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
