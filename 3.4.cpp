/*
	读入两个字符串，比较其是否相等，并输出结果。
	如果不相等，输出较大的字符串。
	改写程序，比较两个字符串是否等长，如果不等，输出较长的字符串。
*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	/*比较两个字符串是否相等，*/
	cout << "Compare if s1 equals s2, output the bigger one." << endl;
	if (s1 == s2)
		cout << "string1 equals to string2!" << endl << endl;
	else
		if (s1 > s2)
			cout << s1 << endl;
		else
			cout << s2 << endl;

	cout << "Compare the length of s1 and s2, output the larger one." << endl;
	if (s1.size() == s2.size())
		cout << "the size of s1 equals s2." << endl;
	else if (s1.size() > s2.size())
		cout << s1 << endl;
	else
		cout << s2 << endl;

	return 0;
}