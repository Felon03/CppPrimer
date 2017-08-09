/*编写一个递归函数，输出vector对象的内容*/
#include<iostream>
#include<vector>

using namespace std;

void print(vector<int>::iterator beg, vector<int>::iterator end)
{
	if (beg != end)
	{
		cout << *beg << " ";
		print(next(beg), end);
	}
}

// 在掉用factorial函数时，为什么我们传入的值是val-1而非val--
// 如果传入val--，函数调用的参数永远都是val，是一个死循环
int factorial(int val)
{
	if (val > 1)
		return factorial(val-1)*val;
	return 1;
}

int main()
{
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	print(vec.begin(), vec.end());
	cout << endl;
	cout << factorial(10) << endl;

	return 0;
}