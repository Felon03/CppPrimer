/*定义一个map，关键字是家庭的姓，只是一个vector，保存家中孩子（们）的名。
	编写代码，实现添加新的家庭以及想已有家庭中添加新的孩子。
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main()
{
	map<string, vector<string>> family;
	string first_name, last_name;
	vector<string> name;
	while (cin>>last_name>>first_name)
	{
		family[last_name].push_back(first_name);		// 怎么来的？？
																								// family[]就表示值，这时family[]是一个vector，可以用push_back
	}
	
	for (const auto &member : family)
	{
		cout << "Member is: " << endl;
		for (const auto &it : member.second)
			cout << it << " " << member.first << endl;
	}

	return 0;
}