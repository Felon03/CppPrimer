#include<iostream>

using namespace std;

int main()
{
	int i = 0, &r = i;
	auto a = r;		//����һ������ (r��i�ı�������i��һ������)
	const int ci = i, &cr = ci;
	auto b = ci;		// b��һ������(ci�Ķ���const���Ա����Ե���)
	auto c = cr;		//	c��һ������(cr��ci�ı�����ci������һ������const)
	auto d = &i;		// d��һ������ָ��(������izhi����ָ��������ָ��)
	auto e = &ci;	// e��һ��ָ������������ָ��(�Գ�������ȡ��ַ��һ�ֵײ�const)
	auto &g = ci;	// g��һ�����ͳ������ã��󶨵�ci

	cout << "a = " << a << " b = " << b << " c = " << c << endl;
	cout << "e = " << *e << " g = " << g << endl;

	a = 42;	// ��ȷ
	b = 42;	// ��ȷ
	c = 42;	// ��ȷ
	//d = 42;	// ����d��ָ�룬�޷�ָ��һ������
	//e = 42;	// ����e��ָ��
	//g = 42;	// ����g�ǳ������ã��޷��޸�

	cout << "a = " << a << " b = " << b << " c = " << c << endl;

	return 0;
}