/*
    16.41 ��дһ���µ�sum�汾�����ķ������ͱ�֤�㹻���������ɼӷ����
*/
#include<iostream>

template<typename T>
auto sum(T v1, T v2) -> decltype(v1 + v2)
{
	return v1 + v2;
}

int main()
{
	auto s = sum(12346789000000, 1234567890000);
	std::cout << s << std::endl;
	return 0;
}