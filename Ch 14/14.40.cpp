/* 重写10.3.2节的biggies函数，使用函数对象类替换其中的lambda表达式*/
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::sort;
using std::stable_sort;
using std::for_each;

class ShorterString {
public:
	bool operator()(const string &s1, const string &s2) const
	{
		return s1.size() < s2.size();
	}
};

class SizeComp {
public:
	SizeComp(size_t n) : size(n) {}
	bool operator() (const string &s) const
	{
		return s.size() >= size;
	}

private:
	size_t size;
};

class Print {
public:
	void operator() (const string &s) const
	{
		cout << s << " ";
	}
};

void elimDups(vector<string> &words)
{
	// 按字典序排序words
	sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	// 使用向量操作erase删除重复单词
	words.erase(end_unique, words.end());
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), ShorterString());
	auto wc = std::find_if(words.begin(), words.end(), SizeComp(sz));
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer" << endl;
	for_each(wc, words.end(), Print());
	cout << endl;
}

int main()
{
	vector<string> vec{ "the", "quick", "red", "fox","jumps","over","the","slow","red","turtle" };
	biggies(vec, 3);
	return 0;
}

