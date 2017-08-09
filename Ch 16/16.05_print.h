#pragma once
/* 为6.2.4节的print函数编写模板版本，它接受一个数组的引用，
	能处理任意大小、任意元素类型的数组
*/
#include<iostream>
template<typename _Ty, unsigned _Sz>
void print(const _Ty(&arr)[_Sz])
{
	for (const auto &elem : arr)
		std::cout << elem << " ";
}