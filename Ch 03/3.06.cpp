#include<iostream>
#include<string>

using namespace std;

/*使用范围for语句将字符串内的所有字符用X代替*/
int main()
{
	string s;
	cout << "Please input a sting:" << endl;
	getline(cin, s);

	cout << "Replace the character in s using 'X': " << endl;
	for (auto &c : s)
		c = 'X';
	cout << s << endl;
	
	return 0;
}