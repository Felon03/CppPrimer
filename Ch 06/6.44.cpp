/*将6.2.2节的isShorter函数改写成内联函数*/
#include<iostream>
#include<string>

using namespace std;

inline bool isShorter(const string &s1, const string &s2) { return s1.size() < s2.size(); }

int main()
{
	cout << boolalpha << isShorter("qwert", "asdfgh") << endl;

	return 0;
}