
#include<iostream>
#include<string>

using namespace std;

// 6.36 ��дһ��������������ʹ�䷵����������ò��Ҹ��������10��string���󡣲�Ҫʹ��β�÷������͡�decltype�������ͱ���
string (&func(string (&arr)[10]))[10];

// 6.37
// ʹ�����ͱ���
using arrT = string[10];
arrT& func1(arrT& arr);
// ʹ��β�÷�������
auto func2(arrT& arr)->string(&)[10];
// ʹ��decltype�ؼ���
string arrS[10];
decltype(arrS) &func3(arrT& arr);

// 6.38
// �޸�arrPtr��������ʹ�䷵�����������
int odd[] = { 1,3,4,7,9 };
int even[] = { 0, 2, 4, 6, 8 };
decltype(odd) &arrPtr(int i)
{
	return (i % 2) ? odd : even;
}