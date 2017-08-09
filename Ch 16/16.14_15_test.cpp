#include "16.14_15_Screen.h"
#include<iostream>

int main()
{
	Screen<4, 5> screen('x');
	screen.set(2, 2, '0');
	std::cout << screen << std::endl;

	std::cout << "Please enter some characters: ";
	std::cin >> screen;
	std::cout << screen << std::endl;
	return 0;
}