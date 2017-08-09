#include"14.49_Book.h"

int main()
{
	Book book1(1, "cpp primer 5th", "Lippman", "2013", 76);
	Book book2 = book1;
	Book book3(book1);
	Book book4 = Book(std::cin);
	if (book2)
		book2 = book4;
	std::cout << book2 << std::endl;

	auto flag = static_cast<bool>(book2);
	std::cout << std::boolalpha << flag << std::endl;
	return 0;
}