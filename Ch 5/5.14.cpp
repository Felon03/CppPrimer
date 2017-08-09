/*编写一段程序，从标准输入中读取若干string对象并查找连续重复出现的单词。*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<string> st;
	string st1, prestr;
	unsigned int wordCnt = 1;
	bool flag = false;
	while (cin >> st1)
	{
		st.push_back(st1);
	}

	auto beg = st.begin();
	while (beg != st.end())
	{
		if (prestr == *beg)
		{
			++wordCnt;
			prestr = *beg;
			++beg;
		}
		else
		{
			if (wordCnt > 1)
			{
				cout << prestr << " occurs " << wordCnt << " times" << endl;
				wordCnt = 1;
				flag = true;
			}
			prestr = *beg;
			++beg;
		}
		if (beg == st.end())	// 统计最后可能连续的单词
			if (wordCnt > 1)
			{
				cout << prestr << " occurs " << wordCnt << " times" << endl;
				flag = true;
				//wordCnt = 1;	// 重置计数器
			}
	}
	/*判断是否有重复的单词 flag 为 true即有重复的单词*/
	if (!flag)
		cout << "No word occurs more than 2 times." << endl;

	return 0;
}