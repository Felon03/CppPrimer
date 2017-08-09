/*��д����ʵ���ı���ѯ����Ҫ���������������ݡ���ĳ���Ӧ�ý���һ���ļ���
	�����û���������ѯ���ʡ�ʹ��vector��map��set���������������ļ�������
	�����ɲ�ѯ���
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
	vector<string> input;		// ����ÿһ�е�����
	using size = decltype(input.size());
	map < string, set<size>> dictionary;		// map<string, set<size_t>> stringΪ���ʣ� set����ÿ��string���ֵ�����
	size line_no{ 0 };			// ��ʼ����Ϊ0���������forѭ��ÿ�еĶ�����Ӻ������
	
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
