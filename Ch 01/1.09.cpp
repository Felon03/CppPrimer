/*
*  ʹ��whileѭ����50 �� 100 ���������
*/

#include<iostream>

int main4()
{
	int x = 50;			// ��ʼ��
	int sum = 0;		// �����
	while (x <=100)
	{
		sum += x;
		x++;
	}
	std::cout << "The sum from 50 to 100: " << sum << std::endl;
	return 0;
}