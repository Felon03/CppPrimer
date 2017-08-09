/*重写统计长度小于等于6的单词数量的程序，使用函数代替lambda*/
#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>

using namespace std;
using namespace std::placeholders;

bool less_or_equal(const string &s, string::size_type sz)
{
	return s.size() <= sz;
}

int main()
{
	vector<string> words{ "hello", "world","from","cppprimer","learning", "hard" };
	auto cnt = count_if(words.begin(), words.end(),
		bind(less_or_equal, _1, 6));
	cout << cnt << endl;

	return 0;
}