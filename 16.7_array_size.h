#pragma once
/* ��дһ��constexprģ�壬���ظ�������Ĵ�С*/

template<typename _Ty, size_t _Size> constexpr
size_t my_size(const _Ty(&_Array)[_Size])
{
	return _Size;
}