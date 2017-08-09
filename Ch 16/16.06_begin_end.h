#pragma once
/* 你认为接受一个数组实参的标准库函数begin和end是如何工作的？
	 定义你自己版本的begin和end
*/
template<typename _Ty, unsigned _Size>
_Ty *begin(_Ty(&_Array)[_Size])
{
	return _Array;
}

template<typename _Ty, unsigned _Size>
_Ty *end(_Ty(&_Array)[_Size])
{
	return _Array + _Size;
}