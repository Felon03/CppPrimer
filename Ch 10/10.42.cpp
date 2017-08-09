/*使用list代替vector重新实现去除重复单词的程序*/
#include<iostream>
#include<list>
#include<string>

using namespace std;

void elimDups(list<string> &words)
{
	// 给words排序
	words.sort();
	// 删除重复元素
	words.unique();
}

int main()
{
	list<string> ls{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	elimDups(ls);
	for (const auto &x : ls)
		cout << x << " ";
	cout << endl;

	return 0;
}