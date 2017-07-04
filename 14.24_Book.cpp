#include "14.24_Book.h"

std::istream & operator >> (std::istream &is, Book &book)
{
	// TODO: �ڴ˴����� return ���
	is >> book.no_ >> book.name_ >> book.author_ >> book.pubdate_ >> book.number_;
	if (!is)
		book = Book();
	return is;

}

std::ostream & operator<<(std::ostream &os, const Book &book)
{
	// TODO: �ڴ˴����� return ���
	os << book.no_ << " " << book.name_ << " " << book.author_ << " "
		<< book.pubdate_ << " " << book.number_;
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
	Book book = lhs;
	book += rhs;
	return book;
}

Book & Book::operator+=(const Book &lhs)
{
	// TODO: �ڴ˴����� return ���
	if (lhs == *this)
		this->number_ += lhs.number_;
	return *this;
}

Book::Book(const Book &rhs)
	:no_(rhs.no_), name_(rhs.name_), author_(rhs.author_), pubdate_(rhs.pubdate_), number_(rhs.number_)
{
	std::cout << "copy constructor" << std::endl;
}

Book::Book(Book &&rhs) noexcept
	:no_(rhs.no_), name_(rhs.name_), author_(rhs.author_), pubdate_(rhs.pubdate_), number_(rhs.number_)
{
	std::cout << "move constructor" << std::endl;
}

Book & Book::operator=(const Book &rhs)
{
	// TODO: �ڴ˴����� return ���
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
	// TODO: �ڴ˴����� return ���
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
