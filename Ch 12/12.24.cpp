/* ��дһ�����򣬴ӱ�׼�����ȡһ���ַ���������һ����̬������ַ������С�
	������ĳ�����δ���䳤���롣������ĳ�������һ���������������鳤��
	���ַ���
*/
#include<iostream>

int main()
{
	unsigned size = 0;
	char ch;
	std::cout << "Please enter the length of the string you want enter:" << std::endl;
	std::cin >> size;
	char *input = new char[size + 1]();
	// �������cin.ignore()��cin.get(),�������������ϴ�����Ļ��з�
	// ���޷��������µ��ַ�����
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