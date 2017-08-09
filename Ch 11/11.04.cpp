#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	map<string, size_t> m;
	string word;
	while (cin>>word)
	{
		// ���Դ�Сд
		for (auto &ch : word) ch = tolower(ch);
		// ʹ��erase ��remove_ifɾ������ı����ţ����Ա��
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
		++m[word];
	}
	for (const auto &w : m)
		cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times." : " time.") << endl;

	return 0;
}