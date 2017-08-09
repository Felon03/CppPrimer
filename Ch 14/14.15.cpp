#include "14.15.h"

std::istream & operator >> (std::istream &is, Book &rhs)
{
	// TODO: 在此处插入 return 语句
	is >> rhs.no_ >> rhs.name_ >> rhs.author_
		>> rhs.pubdate_ >> rhs.number_;
	if (!is) rhs = Book();
	return is;
}

std::ostream & operator<<(std::ostream &os, const Book &rhs)
{
	// TODO: 在此处插入 return 语句
	os << rhs.no_ << " " << rhs.name_ << " " << rhs.author_ << " "
		<< rhs.pubdate_ << " " << rhs.number_;
	return os;
}

bool operator==(const Book &lhs, const Book &rhs)
{
	return lhs.no_ == rhs.no_;
}

bool operator!=(const Book &lhs, const Book &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const Book &lhs, const Book &rhs)
{
	return lhs.no_ < rhs.no_;
}

bool operator>(const Book &lhs, const Book &rhs)
{
	return rhs < lhs;
}

Book operator+(const Book &lhs, const Book &rhs)
{
	Book sum = lhs;
	sum += rhs;
	return sum;
}

Book Book::operator+=(const Book &rhs)
{
	if (rhs == *this)
		this->number_ += rhs.number_;
	return *this;
}
