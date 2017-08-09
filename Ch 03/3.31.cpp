/*编写一段程序，定义一个含有10个int的数组，令每个元素的值就是其下标值*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int a[10] = {};
	for (size_t i = 0; i < 10; i++)
	{
		a[i] = i;
	}
	cout << "initialize array:" << endl;
	for (auto x : a)
		cout << x << " ";
	cout << endl;
	int a1[10] = {};
	// 拷贝给另一个数组
	for (auto x : a)
		a1[x] = x;
	cout << "copy array:" << endl;
	for (auto x : a1)
		cout << a1[x] << " ";
	cout << endl;

	// 利用vector重写程序
	vector<int>	 a3;
	for (size_t i = 0; i < 10; i++)
	{
		a3.push_back(i);
	}
	cout << "vector:" << endl;
	for (auto x : a3)
		cout << x << " ";
	cout << endl;
	
	return 0;
}