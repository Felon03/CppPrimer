/*����һ��map���ؼ����Ǽ�ͥ���գ�ֻ��һ��vector��������к��ӣ��ǣ�������
	��д���룬ʵ������µļ�ͥ�Լ������м�ͥ������µĺ��ӡ�
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
		family[last_name].push_back(first_name);		// ��ô���ģ���
																								// family[]�ͱ�ʾֵ����ʱfamily[]��һ��vector��������push_back
	}
	
	for (const auto &member : family)
	{
		cout << "Member is: " << endl;
		for (const auto &it : member.second)
			cout << it << " " << member.first << endl;
	}

	return 0;
}