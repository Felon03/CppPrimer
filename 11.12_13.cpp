/*编写程序，读入string和int序列，将每个string和int存入一个pair'中，pair保存在一个vector中*/
#include<utility>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<pair<string, int>> vp;
	string word;
	int num;
	while (cin>>word>>num)
	{
		vp.push_back(make_pair(word, num));
	}

	// 11.13 采用不同的方法创建pair
	vp.push_back(pair<string, int>(word, num));
	vp.push_back(pair<string, int>{word, num});	// 等价于上一个
	vp.push_back({ word, num });

	for (const auto &x : vp)
		cout << x.first << ":" << x.second << endl;

	return 0;
}