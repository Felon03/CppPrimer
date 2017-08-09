#include<iostream>

using namespace std;

int main()
{
	int i = 0, &r = i;
	auto a = r;		//ａ是一个整数 (r是i的别名，而i是一个整数)
	const int ci = i, &cr = ci;
	auto b = ci;		// b是一个整数(ci的顶层const特性被忽略掉了)
	auto c = cr;		//	c是一个整数(cr是ci的别名，ci本身是一个顶层const)
	auto d = &i;		// d是一个整型指针(整数的izhi就是指向整数的指针)
	auto e = &ci;	// e是一个指向整数常量的指针(对常量对象取地址是一种底层const)
	auto &g = ci;	// g是一个整型常量引用，绑定到ci

	cout << "a = " << a << " b = " << b << " c = " << c << endl;
	cout << "e = " << *e << " g = " << g << endl;

	a = 42;	// 正确
	b = 42;	// 正确
	c = 42;	// 正确
	//d = 42;	// 错误，d是指针，无法指向一个常量
	//e = 42;	// 错误，e是指针
	//g = 42;	// 错误，g是常量引用，无法修改

	cout << "a = " << a << " b = " << b << " c = " << c << endl;

	return 0;
}