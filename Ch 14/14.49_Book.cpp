#include "14.49_Book.h"

std::istream & operator >> (std::istream &is, Book &rhs)
{
	// TODO: 在此处插入 return 语句
	is >> rhs.no_ >> rhs.name_ >> rhs.author_ >> rhs.pubdate_ >> rhs.number_;
	if (!is)
		rhs = Book();
	return is;
}

std::ostream & operator<<(std::ostream &os, const Book &rhs)
{
	// TODO: 在此处插入 return 语句
	os << rhs.no_ << " " << rhs.name_ << " "
		<< rhs.author_ << " " << rhs.pubdate_ << " "
		<< rhs.number_;
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

Book & Book::operator+=(const Book &rhs)
{
	// TODO: 在此处插入 return 语句
	if (rhs == *this)
		this->number_ += rhs.number_;
	return  *this;
}

Book::Book(const Book &rhs)
	:no_(rhs.no_), name_(rhs.name_),author_(rhs.author_), pubdate_(rhs.pubdate_),number_(rhs.number_)
{
	std::cout << "copy constructor" << std::endl;
}

Book::Book(Book &&rhs) noexcept
	: no_(rhs.no_), name_(rhs.name_), author_(rhs.author_),pubdate_(rhs.pubdate_),number_(rhs.number_)
{
	std::cout << "move constructor" << std::endl;
}

Book & Book::operator=(const Book &rhs)
{
	// TODO: 在此处插入 return 语句
	no_ = rhs.no_;
	name_ = rhs.name_;
	author_ = rhs.author_;
	pubdate_ = rhs.pubdate_;
	number_ = rhs.number_;
	std::cout << "copy assignment" << std::endl;
	return *this;
}

Book & Book::operator=(Book &&rhs) noexcept
{
	// TODO: 在此处插入 return 语句
	if (this != &rhs)
	{
		no_ = rhs.no_;
		name_ = rhs.name_;
		author_ = rhs.author_;
		pubdate_ = rhs.pubdate_;
		number_ = rhs.number_;
	}
	std::cout << "move assignment" << std::endl;
	return *this;
}
