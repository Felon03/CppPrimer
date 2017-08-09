/*编写并验证你自己的reset函数，使其作用于引用类型的参数*/
#include<iostream>

using namespace std;

void reset(int &n)
{
	n = -1;		// 重置整数的值为-1
}

int main()
{
	int x;
	cout << "Enter a number: " << endl;
	cin >> x;
	cout << "The value of entered number: " << x << endl;
	reset(x);
	cout << "After reset, the value of entered number: " << x << endl;

	return 0;
}