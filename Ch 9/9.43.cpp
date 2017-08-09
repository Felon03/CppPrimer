/*编写一个函数，接受三个string参数s、oldVal和newVal。使用迭代器及insert和erase函数
将s中所有的oldVal替换为newVal。
测试程序，用它替换tongue的简写形式
*/
#include<iostream>
#include<string>

using namespace std;

void replace_str(string &s, const string &oldVal, const string &newVal)
{
	for (auto beg = s.begin(); distance(beg, s.end()) > distance(oldVal.begin(), oldVal.end());)		// 保证beg到最后元素的长度大于等于oldVal的长度
	{
		if (string(beg, beg + oldVal.size()) == oldVal)		// 如果找到了
		{
			beg = s.erase(beg, beg + oldVal.size());		// 先删除原来的oldVal
			beg = s.insert(beg, newVal.cbegin(), newVal.cend());		// 再插入newVal
			advance(beg, newVal.size());		// beg迭代器指向neVal的后一个元素
		}
		else
			++beg;		// 没找到遍历下一个
	}

	return;
}

int main()
{
	string str1{ "Hello, it's worte by C++!!!" };
	replace_str(str1, "C++", "C Plus Plus");
	cout << str1 << endl;

	string str2{ "my world is a big world" };
	replace_str(str2, "big", "biggggggggggggggg");
	cout << str2 << endl;
	return 0;
}