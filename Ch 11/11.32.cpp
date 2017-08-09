/*ʹ����һ�ⶨ���multimap��дһ�����򣬰��Ӵ������ӡ�����б�����ǵ���Ʒ*/
#include<iostream>
#include<string>
#include<map>
#include<set>

using namespace std;

int main()
{
	multimap<string, string> authors{
		{"Alan", "DMA"},
		{"pezy", "LeetCode"},
		{"Alan", "CLRS"},
		{"Wang", "FTP"},
		{"pezy","CP5"},
		{"Wang","CPP-Concurrency"}
	};

	map<string, multiset<string>> order_authors;

	for (const auto & author : authors)
		order_authors[author.first].insert(author.second);
	for (const auto &author : order_authors)
	{
		cout << author.first << ": " << endl;
		for (const auto &book : author.second)
			cout << book << " ";
		cout << endl;
	}
		

	return 0;
}

