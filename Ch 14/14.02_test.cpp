#include"14.02.h"

int main()
{
	Sales_data item0, item1;
	std::cout << "cin>>item0>>item1" << std::endl;
	std::cin >> item0 >> item1;
	std::cout << "cout<<item0<<item1" << std::endl;
	std::cout << item0 <<" "<< item1 << std::endl;
	std::cout << "cout<<item0+item1" << std::endl;
	std::cout << item0 + item1 << std::endl;
	item0 += item1;
	std::cout << "item0(item0+=item1)" << std::endl;
	std::cout << item0 << std::endl;

	return 0;
}