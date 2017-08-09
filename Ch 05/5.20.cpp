/*编写一段程序，从标准输入中读取string对象的序列指导连续出现两个相同的单词或者所有单词都读完为止*/
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
			cout << str << " occurs continuously." << endl;
			flag = true;
			break;
		}
		else
			preStr = str;
	}
	// 输入结束时仍未有连续出现的单词
	if (!flag)
		cout << "No word occurs continuously." << endl;

	return 0;
}