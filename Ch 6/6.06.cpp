/*编写一个函数，同时用到形参、局部变量和静态局部变量*/
#include<iostream>

using namespace std;

// 定义函数func，同时用到上述三种参数
void func(int n);	

int main()
{
	int x;
	while (cin >> x)
		func(x);
	return 0;
}

void func(int n)		// n为形参
{
	int ret = 1;	// ret为局部变量
	static int cnt = 0;	// cnt为静态局部变量

	ret += n;
	++cnt;

	cout << "Result = " << ret << endl
		<< "Function calling count: " << cnt << endl;

	return;
}
