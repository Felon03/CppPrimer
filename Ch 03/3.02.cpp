#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main()
{
	string s1;
	//getline(cin, s1);		// 一次读入一整行
	cin >> s1;		// 一次读入一个单词
	cout << s1 << endl;

	return 0;
}