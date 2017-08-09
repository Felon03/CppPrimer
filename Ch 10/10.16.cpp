/*ʹ��lambda��д���Լ��汾��biggies*/
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
	elim_Dups(words);		// ��words���ֵ���������򣬲�ɾ���ظ�����
	// ���������򣬳�����ͬ�ĵ���ά���ֵ���
	stable_sort(words.begin(), words.end(),
		[](const string &s1, const string &s2) {return s1.size() < s2.size(); });
	auto wc = find_if(words.begin(), words.end(),
		[sz](const string &s) {return s.size() >= sz; });
	// ��������size >= sz��Ԫ����Ŀ
	auto cnt = words.end() - wc;
	cout << cnt << " " << make_plural(cnt, "word", "s") << " of length "
		<< sz << " or longer" << endl;
	// ��ӡ���ȴ��ڵ��ڸ���ֵ�ĵ��ʣ�ÿ�����ʺ����һ���ո�
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