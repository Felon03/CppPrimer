/*11.2.1����ϵ�е�map�Ժ��ӵ���Ϊ�ؼ��֣��������ǵ�����vector����multimap��д��map*/
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