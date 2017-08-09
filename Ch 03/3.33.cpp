#include<iostream>


using namespace std;

int main()
{
	unsigned scores[11];	// 不初始化数组将导致分段计数出错
	unsigned grade;
	// 获取首尾指针 C++11
	unsigned *beg = begin(scores);
	unsigned *last = end(scores);	// 尾指针指向的是最后一个元素的后一位，并不能执行解引和递增操作
	while (cin >> grade)
	{
		if (grade <= 100)
		{
			++scores[grade / 10];
		}
	}
	for (auto x : scores)
		cout << x << " ";
	cout << endl;

	return 0;
}