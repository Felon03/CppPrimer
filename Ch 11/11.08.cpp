/*编写一个程序，在一个vector而不是set中保存不重复的单词。*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<string> exclude{ "a","c","e" };
	string word;
	while (cin >> word)
	{
		if (find(exclude.begin(), exclude.end(), word) == exclude.end())
			exclude.push_back(word);
		else
			cout << word << " excluede!" << endl;
	}

	for (const auto &w : exclude)
		cout << w << " ";
	cout << endl;
	return 0;

}