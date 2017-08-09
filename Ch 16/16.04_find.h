#pragma once
/* ��д��Ϊ���Ʊ�׼��find�㷨��ģ�塣������Ҫ����ģ�����Ͳ�����
	һ����ʾ�����ĵ�������������һ����ʾֵ�����͡�ʹ�øú�����
	һ��vector<int>��vector<string>�в��Ҹ�����ֵ
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