/*
    ��16.1.1��(��578ҳ)�е�ԭʼ�汾��compare������ʹ��һ����ʾģ��ʵ��
	ʹ�ÿ����������������ַ������泣��
*/

#include<iostream>

template<typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

int main()
{
	std::cout << compare<std::string>("abc", "def") << std::endl;
	std::cout << compare<std::string>("def", "abc") << std::endl;
	std::cout << compare<std::string>("abc", "abc") << std::endl;
}