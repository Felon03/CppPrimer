/* 编写一个程序，从标准输入读取一个字符串，存入一个动态分配的字符数组中。
	描述你的程序如何处理变长输入。测试你的程序，输入一个超出你分配的数组长度
	的字符串
*/
#include<iostream>

int main()
{
	unsigned size = 0;
	char ch;
	std::cout << "Please enter the length of the string you want enter:" << std::endl;
	std::cin >> size;
	char *input = new char[size + 1]();
	// 如果不用cin.ignore()或cin.get(),缓冲区保留了上次输入的换行符
	// 就无法在输入新的字符串了
	//std::cin.ignore();
	std::cin.get();
	//std::cin.get(ch);
	std::cout << "Please enter the string:" << std::endl;
	//std::cout << static_cast<int>(ch) << std::endl;
	std::cin.get(input, size + 1);
	std::cout << input << std::endl;
	delete[] input;

	return 0;
}