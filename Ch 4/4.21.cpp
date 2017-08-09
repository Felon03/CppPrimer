/*编写一段程序，使用条件运算符从vector<int>中找到哪些元素的值是奇数，然后将这些奇数值翻倍*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> a = { 0,1,2,3,4,5,6,7,8,9 };
	for (auto &x : a)
		(x % 2) == 0 ? x *= 2 : x = x;
	for (auto x : a)
		cout << x << " ";
	cout << endl;

	return 0;
}