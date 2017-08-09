/*编写一个函数，令其接受两个参数：一个是int型整数，另一个是int指针。
函数比较int的值和指针所指的值，返回较大的那个
*/
#include<iostream>

using namespace std;

// 比较函数
int compare_int(const int &a, const int *b)
{
	return a > *b ? a : *b;
}

int main()
{
	int x = 100;
	int y = 200;
	int *z = &y;
	
	cout << compare_int(x, z) << endl;

	return 0;
}