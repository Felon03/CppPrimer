/*��д����ĳ�����list���deque���г�����Ҫ������Щ�ı�*/
#include<iostream>
#include<string>
#include<list>

using namespace std;

int main()
{
	list<string> lstStr;
	string word;

	while (cin >> word)
		lstStr.push_back(word);

	for (auto iter = lstStr.cbegin(); iter != lstStr.cend(); ++iter)
		cout << *iter << " ";
	cout << endl;
}