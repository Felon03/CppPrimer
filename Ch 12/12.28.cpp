/*编写程序实现文本查询，不要定义类来管理数据。你的程序应该接受一个文件，
	并与用户交互来查询单词。使用vector、map和set容器来保存来自文件的数据
	并生成查询结果
*/
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<memory>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<iterator>

using namespace std;

int main()
{
	ifstream infile("data/story.txt");
	vector<string> input;		// 保存每一行的输入
	using size = decltype(input.size());
	map < string, set<size>> dictionary;		// map<string, set<size_t>> string为单词， set保存每个string出现的行数
	size line_no{ 0 };			// 初始行数为0，后面跟着for循环每行的读入句子后会自增
	
	for (string line; getline(infile, line); ++line_no)
	{
		input.push_back(line);
		istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear())
		{
			remove_copy_if(text.begin(), text.end(), back_inserter(word), ispunct);
			dictionary[word].insert(line_no);
		}
	}

	while (true)
	{
		cout << "Enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		auto found = dictionary.find(s);
		if (found != dictionary.end())
		{
			cout << s << " occurs " << found->second.size()
				<< (found->second.size() > 1 ? " times." : " time.")
				<< endl;
			for (const auto &x : found->second)
				cout << "\t(line " << x + 1 << ") " << input.at(x) << endl;
		}
		else
			cout << s << " occurs 0 time." << endl;
	}

	return 0;
}
