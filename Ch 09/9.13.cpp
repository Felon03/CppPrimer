/*如何从一个list<int>初始化一个vector<double>?
从一个vector<int>又该如何创建?编写代码验证答案
*/
#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main()
{
	// list<int> 初始化vector<double>
	list<int> ilst{ 1,2,3,4,5,6,7,8 };
	for (auto x : ilst)
		cout << x << " ";
	cout << endl;
	vector<double> dv(ilst.begin(), ilst.end());

	for (auto x : dv)
		cout << x << " ";
	cout << endl;

	// vector<int> 初始化vector<double>
	vector<int> ivc{ 1,2,3,4,5 };
	for (auto x : ivc)
		cout << x << " ";
	cout << endl;
	vector<double> dvc(ivc.begin(), ivc.end());
	for (auto x : dvc)
		cout << x << " ";
	cout << endl;

	return 0;
}