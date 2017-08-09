/*对一个string到int的vector的map，定义并初始化一个变量来保存在其上调用find所返回的结果*/
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main()
{
	map<string, vector<int>> m;
	m = {
		{"Alice", {1,2,3,4,5}},
		{"Bob", {5,4,3,2,1}}
	};

	auto it = m.find("Alice");

	map<string, vector<int>>::iterator iter;
	iter = m.find("Alice");
	if (iter == it)
		cout << "True" << endl;
	else
		cout << "False" << endl;

	return 0;
}