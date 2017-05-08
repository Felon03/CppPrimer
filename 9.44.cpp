/*重写9.34，这次使用下标和replace*/
#include<iostream>
#include<string>

using namespace std;

void replace_str(string &s, const string &oldVal, const string &newVal)
{
	for (string::size_type i = 0; i != s.size(); ++i)
	{
		if (s.substr(i, oldVal.size()) == oldVal)
		{
			s.replace(i, oldVal.size(), newVal);
			i += newVal.size() - 1;
		}
	}

	return;
}

int main()
{
	string str{ "To drive straight thru is a foolish, tho courageous act." };
	replace_str(str, "tho", "though");
	replace_str(str, "thru", "through");
	cout << str << endl;

	string str1{ "Hello, it's worte by C++!!!" };
	replace_str(str1, "C++", "C Plus Plus");
	cout << str1 << endl;

	string str2{ "my world is a big world" };
	replace_str(str2, "big", "biggggggggggggggg");
	cout << str2 << endl;
}