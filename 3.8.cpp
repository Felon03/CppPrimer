#include<iostream>
#include<string>	

using namespace std;

int main()
{
	/*whileѭ����д3.6*/
	string s;
	cout << "Please input a srting:" << endl;
	cin >> s;
	decltype(s.size()) index = 0;
	while (index < s.size())
	{
		auto &c = s[index];
		c = 'X';
		index++;
	}
	cout << "Replace character in s using 'X'(with while statement): " << endl;
	cout << s << endl;
	
	/*forѭ����д3.6*/
	for (decltype(s.size()) index = 0; index < s.size(); index++)
	{
		auto &c = s[index];
		c = 'X';
	}
	cout << "Replace character in s using 'X'(with for statement): " << endl;
	cout << s << endl;

	return 0;
}