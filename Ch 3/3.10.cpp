#include<iostream>
#include<string>
#include<cctype>

using namespace std;

/*����һ�����������ŵ��ַ�������������ȥ��������ַ���*/
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