#pragma once
/* ����Ϊ����һ������ʵ�εı�׼�⺯��begin��end����ι����ģ�
	 �������Լ��汾��begin��end
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