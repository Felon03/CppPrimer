#include<iostream>
#include<vector>
#include<string>

using namespace std;

/*��cin����һ���ַ����������Ǵ���һ��vector����*/
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