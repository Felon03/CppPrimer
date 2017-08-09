/*修改5.20，使其找到的重复单词必须以大写字母开头*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str, preStr;	// preStr记录前一个单词
	cout << "Please enter some words:	" << endl;
	bool flag = false;
	while (cin >> str && !str.empty())
	{
		if (str == preStr)
		{
			if (str[0] >= 'A' && str[0] <= 'Z')
			{
				cout << str << " occurs continuously." << endl;
				flag = true;
				break;
			}
			else
				continue;
		}
		else
			preStr = str;
	}
	// 输入结束时仍未有连续出现的单词
	if (!flag)
		cout << "No word occurs continuously." << endl;

	return 0;
}