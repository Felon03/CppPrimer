#include "16.2_compare.h"
#include "Sales_data.h"
#include<iostream>

int main()
{
	std::cout << compare(1, 0) << std::endl;
	std::cout << compare(0, 1) << std::endl;
	std::cout << compare(1, 1) << std::endl;
	std::cout << compare_str("hello", "world") << std::endl;
	//Sales_data data1, data2;
	//std::cout << compare(data1, data2) << std::endl;
	//
	// Error
    // �����ơ�<��: û���ҵ����ܡ�const Sales_data�����͵���������������(��û�пɽ��ܵ�ת��)	
	//
	return 0;
}