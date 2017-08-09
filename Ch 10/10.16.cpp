/*使用lambda编写你自己版本的biggies*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}
void elim_Dups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elim_Dups(words);		// 将words按字典序进行排序，并删除重复单词
	// 按长度排序，长度相同的单词维持字典序
	stable_sort(words.begin(), words.end(),
		[](const string &s1, const string &s2) {return s1.size() < s2.size(); });
	auto wc = find_if(words.begin(), words.end(),
		[sz](const string &s) {return s.size() >= sz; });
	// 计算满足size >= sz的元素数目
	auto cnt = words.end() - wc;
	cout << cnt << " " << make_plural(cnt, "word", "s") << " of length "
		<< sz << " or longer" << endl;
	// 打印长度大于等于给定值的单词，每个单词后面接一个空格
	for_each(wc, words.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}

int main()
{
	vector<string> sv{ "the", "quick","red","fox","jumps","over","the","slow","red","turtle" };
	biggies(sv, 5);

	return 0;
}