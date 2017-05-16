/*��дͳ�Ƴ���С�ڵ���6�ĵ��������ĳ���ʹ�ú�������lambda*/
#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>

using namespace std;
using namespace std::placeholders;

bool less_or_equal(const string &s, string::size_type sz)
{
	return s.size() <= sz;
}

int main()
{
	vector<string> words{ "hello", "world","from","cppprimer","learning", "hard" };
	auto cnt = count_if(words.begin(), words.end(),
		bind(less_or_equal, _1, 6));
	cout << cnt << endl;

	return 0;
}