/*��д���򣬽�һ��list�е�char *ָ��(ָ��C����ַ���)Ԫ�ظ�ֵ��һ��vector�е�string*/
#include<iostream>
#include<string>
#include<list>
#include<vector>

using namespace std;

int main()
{
	list<const char *> oldStyle{ "hello world", "The Elder Scroll V: Skyrim", "Grand Theft Auto V" };
	vector<string> newStr;
	newStr.assign(oldStyle.cbegin(), oldStyle.cend());

	for (const auto &x : newStr)
		cout << x << endl;
	return 0;
}