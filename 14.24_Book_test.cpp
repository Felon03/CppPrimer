#include"14.24_Book.h"
#include<iostream>

int main()
{
	Book book1(1, "Cpp primer 5th", "Lippman", "2013", 10);
	Book book2 = book1;
	Book book3(book2);
	Book book4 = Book(std::cin);
	book2 = book4;
	std::cout << book4 << std::endl;

	return 0;
}
