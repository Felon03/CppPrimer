#include "14.5.h"

std::istream & operator >> (std::istream &is, Book &rhs)
{
	// TODO: �ڴ˴����� return ���
	is >> rhs.book_no >> rhs.book_name >> rhs.book_author
		>> rhs.publish_date;
	if (!is) rhs = Book();
	return is;
}

std::ostream & operator<<(std::ostream &os, Book &rhs)
{
	// TODO: �ڴ˴����� return ���
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
