/*编写一段程序，创建含有10个整数的vector对象，然后使用迭代器讲所有元素的值都变成原来的两倍。输出vector对象的内容*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> digits;

	for (int i = 0; i < 10; i++)
	{
		digits.push_back(i);
	}
	for (auto x : digits)
		cout << x << endl;
	for (auto iter = digits.begin(); iter != digits.end(); ++iter)
	{
		*iter *= 2;
		cout << *iter << endl;
	}

	return 0;
}