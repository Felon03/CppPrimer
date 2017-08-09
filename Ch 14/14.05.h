#pragma once
/* ��7.5.1�ڵ���ϰ7.40�У�������Book�࣬����������Ӧ�ö������ص������*/
#include<string>
#include<iostream>

class Book {
	friend std::istream& operator>>(std::istream&, Book&);                  // not const Book
	friend std::ostream& operator<<(std::ostream&, const Book&);  // const Book
	friend bool operator==(const Book&, const Book&);
	friend bool operator!=(const Book&, const Book&);
public:
	Book() = default;
	Book(unsigned no, std::string name, std::string author, std::string date)
		: book_no(no), book_name(name), book_author(author), publish_date(date) {}
	Book(std::istream &is) {  is >> *this; }
private:
	unsigned book_no;
	std::string book_name;
	std::string book_author;
	std::string publish_date;
};

std::istream& operator >> (std::istream&, Book&);
std::ostream& operator<<(std::ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);