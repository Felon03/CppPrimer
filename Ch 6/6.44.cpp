/*��6.2.2�ڵ�isShorter������д����������*/
#include<iostream>
#include<string>

using namespace std;

inline bool isShorter(const string &s1, const string &s2) { return s1.size() < s2.size(); }

int main()
{
	cout << boolalpha << isShorter("qwert", "asdfgh") << endl;

	return 0;
}