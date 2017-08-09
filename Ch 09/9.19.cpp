/*重写上题的程序，用list替代deque。列出程序要做出哪些改变*/
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