#include<iostream>

using namespace std;

struct Foo {/*�˴�Ϊ��*/ };
/*
���û���ڻ����ź������';',��������´���:
����(�)		Ӧ���롰;��
����	C2628	��Foo������ӡ�int���ǷǷ���(�Ƿ������ˡ�;��?)
����	C3874	��main���ķ�������ӦΪ��int�����ǡ�Foo��	CppPrimer
����	C2440	��return��: �޷��ӡ�int��ת��Ϊ��Foo��	CppPrimer
*/
int main()
{
	return 0;
}