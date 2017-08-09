/*编写程序，使用stable_sort和isShorter将传递给你的elimDups版本的vector排序。
打印vector的内容，验证程序的正确性
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
	// 按字典徐排序words，一边查找重复单词
	sort(words.begin(), words.end());
	// unique重拍输入范围
	auto end_unique = unique(words.begin(), words.end());
	// 使用向量操作erase删除重复单词
	words.erase(end_unique, words.end());
}

int main()
{
	vector<string> svec{ "the", "quick", "red", "fox", "jumps","over","the","slow","red","turtle" };
	elimDups(svec);
	for (const auto &s : svec)
		cout << s << " ";
	cout << endl;
	/*stable_sort 和 sort的区别就在于 前者作排序可以使原来“相同”的值在序列中的相对位置不变*/
	stable_sort(svec.begin(), svec.end(), isShorter);
	for (const auto &x : svec)
		cout << x << " ";
	cout << endl;

	//sort(svec.begin(), svec.end(), isShorter);
	//for (const auto &x : svec)
	//	cout << x << " ";
	//cout << endl;

	return 0;
}