#pragma once
/* 编写一个constexpr模板，返回给定数组的大小*/

template<typename _Ty, size_t _Size> constexpr
size_t my_size(const _Ty(&_Array)[_Size])
{
	return _Size;
}