#include"16.62_Sales_data.h"
#include<iostream>
#include<unordered_set>
#include<memory>

int main()
{
	std::unordered_multiset<Sales_data> mset;
	Sales_data sd("CPP primer", 10, 29.99);

	mset.emplace(sd);
	mset.emplace("Hello World", 5, 10.00);

	for (const auto &book : mset)
		std::cout << "The hash code of " << book.isbn()
		<< ":\n0x" << std::hex << std::hash<Sales_data>()(book)
		<< "\n";

	//for (const auto &book : mset)
	//	std::cout << "The hash code of " << book.isbn()
	//	<< ":\n" << std::hash<Sales_data>()(book)
	//	<< "\n";

	return 0;
}