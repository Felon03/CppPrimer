#include<iostream>
#include<string>

using namespace std;

/*ʹ�÷�Χfor��佫�ַ����ڵ������ַ���X����*/
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