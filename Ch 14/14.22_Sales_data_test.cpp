#include"14.22_Sales_data.h"

int main()
{
	std::string isbn("Cpp Primer 5th Edition");
	Sales_data book1 = isbn;
	std::cout << book1 << std::endl;
	return 0;
}