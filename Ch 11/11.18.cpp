/*д����382ҳѭ����map_it�����ͣ���Ҫʹ��auto��decltype*/
#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	map<string, size_t> word_count;
	
	// ԭ���Ĵ���
	//auto map_it = word_count.cbegin();

	// ��ʹ��auto��decltypeд��map_it������
	map<string, size_t>::const_iterator map_it = word_count.cbegin();
	while (map_it != word_count.cend())
	{
		cout << map_it->first << " occurs " << map_it->second << " times."
			<< endl;
		++map_it;
	}
	return 0;
}