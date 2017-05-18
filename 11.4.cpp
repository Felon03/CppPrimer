#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	map<string, size_t> m;
	string word;
	while (cin>>word)
	{
		// 忽略大小写
		for (auto &ch : word) ch = tolower(ch);
		// 使用erase 和remove_if删掉读入的标点符号，忽略标点
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
		++m[word];
	}
	for (const auto &w : m)
		cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times." : " time.") << endl;

	return 0;
}