#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*用cin读入一组字符串并把它们存入一个vector对象*/
int main()
{
	vector<string> text;
	string word;
	while (getline(cin, word))
	{
		text.push_back(word);
	}
	cout << "[";
	for (auto i : text)
		if (i == text.back())
			cout << i;
		else
			cout << i << ",";
	cout << "]";

	return 0;
}