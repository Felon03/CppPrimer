/*编写你自己的fact函数，上机检查是否正确*/
#include<iostream>

using namespace std;

// fact函数，返回n的阶乘
int fact(int n);
int func();

int main()
{
	cout << "5! = " << fact(5) << endl;
	cout << func() << endl;

	return 0;
}

int fact(int n)
{
	int result = 1;
	if (n == 1 || n == 0)
		return 1;
	else
		return n*fact(n - 1);
}

int func()
{
	int n, ret = 1;
	cout << "Enter a number: " << endl;
	cin >> n;
	while (n > 1) ret *= n--;
	return ret;
}
