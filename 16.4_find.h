#pragma once
/* 编写行为类似标准库find算法的模板。函数需要两个模板类型参数，
	一个表示函数的迭代器参数，另一个表示值的类型。使用该函数在
	一个vector<int>和vector<string>中查找给定的值
*/

template<typename _InIt, typename _Ty>
_InIt my_find(_InIt _First, _InIt _Last, const _Ty &_Val)
{
	for (; _First != _Last; ++_First)
	{
		if (*_First == _Val) return _First;
	}
	return _Last;
}