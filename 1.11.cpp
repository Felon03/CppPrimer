/*�û�����������������ӡ��������������ָ����Χ�ڵ���������*/
#include<iostream>

int main6()
{
	int from = 0, to = 0;
	std::cout << "Please input the start and end integer:" << std::endl;
	std::cin >> from >> to;
	// ���from С��to�򽻻���ֵ
	if (from > to)
	{
		int temp;
		temp = from;
		from = to;
		to = temp;
	}
	std::cout << "The integers between " << from << " and " << to << ": " << std::endl;

	for (int i = from; i < to + 1; i++)
	{
		std::cout << i <<" ";
	}
	std::cout << std::endl;

	return 0;
	
}