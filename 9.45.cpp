/*编写函数，接受一个表示名字的string参数和两个分别表示前缀(如Mr.或Ms.)和后缀(如Jr.或III)的字符串
使用迭代器及insert和append函数将前缀和后缀添加到给定的名字中，将生成的新string返回
*/
#include<iostream>
#include<string>	

using namespace std;

string extend_str(const string &s, const string &pre, const string &suff)
{
	string ret = s;
	auto beg = ret.begin();
	ret.insert(beg, pre.begin(), pre.end());
	ret.append(suff);
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