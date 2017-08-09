/*编写程序，分别使用at、下标运算符、front和begin提取一个vector中的第一个元素。
在一个空vector上测试程序
*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vec;		// 定义一个空vector

	cout << vec.at(0) << endl
		<< vec[0] << endl
		<< vec.front() << endl
		<< *vec.begin() << endl;

	return 0;
}