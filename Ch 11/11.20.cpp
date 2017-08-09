/*重写11.1节练习的单词技术程序，使用insert代替下标操作*/
#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	map<string, size_t> word_count;
	string word;
	while (cin>>word)
	{
		auto ret = word_count.insert({word, 1});
		if (!ret.second)
			++((ret.first)->second);
	}

	for (const auto &w : word_count)
		cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times" : " time") << endl;

	return 0;
}