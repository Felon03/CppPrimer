/*编写一个函数，使用指针形参交换两个整数的值，在代码中调用该函数并输出交换后的结果*/
#include<iostream>

using namespace std;

void exchange_value(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;

	return;
}

int main()
{
	int a = 5, b = 10;
	cout << "The value of a and b: " << a << " " << b << endl;
	exchange_value(&a, &b);
	cout << "After exchange the value of a and b: " << a << " " << b << endl;

	return 0;
}