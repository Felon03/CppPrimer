/*编写程序，定义一个作者及其作品的multimap。使用find在multimap中查找一个元素并用erase删除它。
	确保你的程序在元素不在map中也能正常运行。
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
	authors.insert({ "阿来","尘埃落定" });

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