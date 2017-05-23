/*��д���򣬶���һ�����߼�����Ʒ��multimap��ʹ��find��multimap�в���һ��Ԫ�ز���eraseɾ������
	ȷ����ĳ�����Ԫ�ز���map��Ҳ���������С�
*/
#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	multimap<string, string> authors;
	authors.insert({ "Barth, John", "Sot-Weed Factor" });
	authors.insert({ "Barth, John", "Lost in the Funhouse" });
	authors.insert({ "����","�����䶨" });

	string search_item("Barth, John");
	auto it = authors.find(search_item);
	if (it!=authors.end())
	{
		//auto cnt = authors.erase(search_item);
		//cout << authors.erase(search_item) << endl;
		//cout <<"Remove "<< cnt << (cnt > 1? " items":" item")<<endl;
		cout << "Remove " << authors.erase(search_item) << " item(s)." << endl;

	}
	else
		cout << "No such author!" << endl;


	for (const auto &a : authors)
		cout << a.first << " " << a.second << endl;
	return 0;
}