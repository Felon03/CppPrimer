/*��дһ��������һ��vector������set�б��治�ظ��ĵ��ʡ�*/
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