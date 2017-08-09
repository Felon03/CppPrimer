/*11.2.1节联系中的map以孩子的姓为关键字，保存他们的名的vector，用multimap重写此map*/
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main()
{
	multimap<string, string> family;
	string last_name, first_name;
	while (cin>>last_name>>first_name)
	{
		//family.emplace(last_name, first_name);
		family.insert({ last_name, first_name });
	}

	for (const auto &member : family)
		cout << member.second << " " << member.first << endl;

	return 0;
}