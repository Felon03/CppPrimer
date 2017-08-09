#include"14.05.h"

int main()
{
	Book book1, book2;
	std::cin >> book1 >> book2;
	std::cout << book1 << "\n" << book2 << std::endl;
	std::cout << (book1 == book2) << std::endl;
	std::cout << (book1 != book2) << std::endl;

	Book book3(1, "CPP", "X", "2012");
	Book book4(2, "CPP", "X", "2012");
	if (book3 != book4)
		std::cout << book3 << std::endl;

	return 0;
}