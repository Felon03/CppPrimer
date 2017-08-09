/*
读入一组整数并把它们存入一个vector对象，将每对相邻整数的和输出出来。
改写程序，要求先输出第一个和最后一个元素的和，接着输出第二个和倒数第二个元素的和，以此类推。
*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> num_array;
	int num;

	while (cin >> num)
		num_array.push_back(num);

	// 将每对相邻整数的和输出
	for (decltype(num_array.size()) i = 0; i < num_array.size() - 1; i++)
		cout << num_array[i] + num_array[i + 1] << endl;

	// 先输出第一个和最后一个元素的和，接着输出第二个和倒数第二个元素的和，以此类推
	decltype(num_array.size()) k = num_array.size() - 1;
	for (decltype(num_array.size()) i = 0; i < num_array.size(); i++)
	{
		if (i <= k)
		{
			cout << num_array[i] + num_array[k] << endl;
			k--;
		}
	}

	return 0;
}