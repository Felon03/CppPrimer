/*实现你自己的elimDups。测试你的程序，分别在读取输入后、调用unique后以及erase后打印vector的内容*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//template <typename Sequence> auto println(Sequence const &seq) ->ostream &
//{
//	for (auto const &elem : seq)
//		cout << elem << " ";
//	return cout << endl;
//}

void elimDup(vector<string> &words)
{
	// 按字典排序words，以便查找重复单词
	sort(words.begin(), words.end());
	for (auto const &x : words)
		cout << x << " ";
	cout << endl;
	// unique重排输入范围，是的每个单词只出现一次
	// 排列在范围的前部，返回指向不重复区域之后一个位置的迭代器
	auto end_unique = unique(words.begin(), words.end());
	for(auto const &x : words)
		cout << x << " ";
	cout << endl;
	// 使用向量操作erase删除重复单词
	words.erase(end_unique, words.end());
	for (auto const &x : words)
		cout << x << " ";
	cout << endl;
}

int main()
{
	vector<string> vec{ "a","v","a","s","v","a","a","q","w","e" };
	for (auto const &x : vec)
		cout << x << " ";
	cout << endl;
	elimDup(vec);

	return 0;
}