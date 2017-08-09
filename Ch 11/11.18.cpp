/*写出第382页循环中map_it的类型，不要使用auto或decltype*/
#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	map<string, size_t> word_count;
	
	// 原来的代码
	//auto map_it = word_count.cbegin();

	// 不使用auto或decltype写出map_it的类型
	map<string, size_t>::const_iterator map_it = word_count.cbegin();
	while (map_it != word_count.cend())
	{
		cout << map_it->first << " occurs " << map_it->second << " times."
			<< endl;
		++map_it;
	}
	return 0;
}