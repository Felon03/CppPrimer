/*使用check_size和bind重写10.3.2节使用了partition的练习*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;
using namespace std::placeholders;

void elimDups(vector<string> &words)
{
	stable_sort(words.begin(), words.end(),
		[](const string &a, const string &b) {return a.size() < b.size(); });
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

bool check_size(const string &s, string::size_type sz)
{
	return s.size() < sz;
}

void bigges(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	//stable_sort(words.begin(), words.end(),
	//	[](const string &s1, const string &s2) {return s1.size() < s2.size(); });
	auto iter = partition(words.begin(), words.end(),
		bind(check_size, _1, sz));
	for_each(iter,words.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}

int main()
{
	vector<string> v{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	bigges(v, 4);

	return 0;
}