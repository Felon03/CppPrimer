/*参考本节介绍的几个print函数，根据离间编写自己的版本*/
#include<iostream>

using namespace std;

// 输出整型数
void print(const int a)
{
	cout << a << endl;
	
	return;
}

// 输出整型数组
void print(const int *beg, const int *end)
{
	while (beg != end)	
		cout << *beg++ << endl;	// *beg, 否则输出的是地址

	return;
}

int main()
{
	int i = 0, j[2] = { 0,1 };

	print(i);
	print(begin(j), end(j));

	return 0;
}

