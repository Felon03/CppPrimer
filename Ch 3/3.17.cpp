#include<iostream>
#include<string>	
#include<vector>

using namespace std;

int main()
{
	string word;
	vector<string> text;
	while (cin >> word)
	{
		text.push_back(word);
	}
	for (decltype(text.size()) i = 0; i < text.size(); i++)
	{
		for (auto &c : text[i])
			c = toupper(c);
	}
	for (auto w : text)
		cout << w << endl;

	return 0;
}