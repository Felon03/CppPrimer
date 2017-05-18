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
		family[last_name].push_back(first_name);
	}
	
	for (const auto &member : family)
	{
		cout << "Member is: " << endl;
		for (const auto &it : member.second)
			cout << it << " " << member.first << endl;
	}

	return 0;
}