/*编写程序，将含有整数元素的vector对象拷贝给一个整型数组*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> arr{ 1, 2, 3, 4, 5, 6 };
	constexpr size_t size = 6;
	int int_arr[size] = {};
	int * beg = begin(int_arr);		// 指向数组首元素的指针

	for (auto x : int_arr)
		cout << x << " ";
	cout << endl;

	for (auto x : arr)
	{
		*beg++ = x;		// 将vector的值赋给数组
	}

	for (auto x : int_arr)
		cout << x << " ";
	cout << endl;

	return 0;
}
