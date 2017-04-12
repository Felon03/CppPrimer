/* 编写一个函数，当它第一次被调用时返回0，以后每次被调用返回值加1*/
#include<iostream>

using namespace std;

int calling_cnt()
{
	static int cnt = 0;

	return cnt++;
}

int main()
{
	for (int i = 0; i != 10; ++i)
		cout << calling_cnt() << endl;

	return 0;
}