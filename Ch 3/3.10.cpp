#include<iostream>
#include<string>
#include<cctype>

using namespace std;

/*读入一个包含标点符号的字符串，将标点符号去除后输出字符串*/
int main()
{
	string s;
	string result;
	cout << "Please input a string with puncts: " << endl;
	getline(cin, s);
	for (auto &c : s)
		if (!ispunct(c))
			result += c;
		
	cout << "Output string with no puncts: " << endl;
	cout << result << endl;

	return 0;
}