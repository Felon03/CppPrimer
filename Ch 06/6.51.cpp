/*编写函数f的四个版本令其个输出一条可以区分的消息。验证上一个练习的答案*/
#include<iostream>

using namespace std;

void f()
{
	cout << "f() called" << endl;
}

void f(int)
{
	cout << "f(int) called" << endl;
}

void f(int, int)
{
	cout << "f(int, int) called" << endl;
}

void f(double, double = 3.14)
{
	cout << "f(double, double = 3.14) called" << endl;
}

int main()
{
	//f(2.56, 42);	// 有二义性，错误
	f(42);
	f(42, 0);
	f(2.56, 3.14);

	return 0;
}