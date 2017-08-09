#include "14.22_Sales_data.h"

Sales_data::Sales_data(std::istream &is) : Sales_data()
{
	is >> *this;
}

std::istream & operator >> (std::istream &is, Sales_data &rhs)
{
	// TODO: 在此处插入 return 语句
	double price = 0.0;
	is >> rhs.bookNo >> rhs.units_sold >> price;
	if (is)
		rhs.revenue = rhs.units_sold * price;
	else
		rhs = Sales_data();
	return is;
}

std::ostream & operator<<(std::ostream &os, const Sales_data &rhs)
{
	// TODO: 在此处插入 return 语句
	os << rhs.isbn() << " " << rhs.units_sold << " " << rhs.revenue << " " << rhs.avg_price();
	return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

Sales_data & Sales_data::operator=(const std::string &isbn)
{
	// TODO: 在此处插入 return 语句
	*this = Sales_data(isbn);
	return *this;
}

Sales_data & Sales_data::operator+=(const Sales_data &rhs)
{
	// TODO: 在此处插入 return 语句
	//Sales_data lhs = *this;
	//lhs.units_sold += rhs.units_sold;
	//lhs.revenue += rhs.revenue;
	//return lhs;
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
