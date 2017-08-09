/*用stable_partiton重写10.18，与stable_sort类似，在划分后的序列中维持原有元素的顺序*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

// use stable_patition instead of partition
void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(),
		[](const string &s1, const string &s2) {return s1.size() < s2.size(); });
	auto iter = stable_partition(words.begin(), words.end(),
		[sz](const string &s) {return s.size() < sz; });
	auto cnt = words.end() - iter;
	cout << cnt << make_plural(cnt, " word", "s")
		<< " of length " << sz << " or longer" << endl;
	for_each(iter, words.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}

int main()
{
	vector<string> sv{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	biggies(sv, 4);

	return 0;
}