/*重写上一题，这次使用位置和长度来管理string，并只用insert*/
#include<iostream>
#include<string>

using namespace std;

string extend_str(const string &s, const string &pre, const string &suff)
{
	string ret = s;
	ret.insert(0, pre);
	string::size_type size = ret.size();
	ret.insert(size, suff);

	return ret;
}

int main()
{
	string name;
	cout << "Please enter your name: ";
	cin >> name;
	cout << extend_str(name, "Mr. ", " bonjour!") << endl;

	return 0;
}