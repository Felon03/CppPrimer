#pragma once
/* Ϊ6.2.4�ڵ�print������дģ��汾��������һ����������ã�
	�ܴ��������С������Ԫ�����͵�����
*/
#include<iostream>
template<typename _Ty, unsigned _Sz>
void print(const _Ty(&arr)[_Sz])
{
	for (const auto &elem : arr)
		std::cout << elem << " ";
}