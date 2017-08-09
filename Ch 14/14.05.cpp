#include "14.05.h"

std::istream & operator >> (std::istream &is, Book &rhs)
{
	// TODO: 在此处插入 return 语句
	is >> rhs.book_no >> rhs.book_name >> rhs.book_author
		>> rhs.publish_date;
	if (!is) rhs = Book();
	return is;
}

std::ostream & operator<<(std::ostream &os, const Book &rhs)
{
	// TODO: 在此处插入 return 语句
	os << rhs.book_no << " " << rhs.book_name << " " << rhs.book_author
		<< " " << rhs.publish_date;
	return os;
}

bool operator==(const Book &lhs, const Book &rhs)
{
	return lhs.book_no == rhs.book_no;
}

bool operator!=(const Book &lhs, const Book &rhs)
{
	return !(lhs == rhs);
}
