/*使用unordered_map重写单词计数程序和单词转换程序*/
#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<sstream>

using namespace std;

void wordCounting()
{
	unordered_map<string, size_t> word_count;
	string word;
	while (cin >> word)
		++word_count[word];
	for (const auto &word : word_count)
		cout << word.first << " occurs" << word.second<< (word.second > 1 ? " times" : " time") << endl;
}

const string &transform(const string &s, const unordered_map<string, string> &m)
{
	auto map_it = m.find(s);
	if (map_it != m.end())
		return map_it->second;
	else
		return s;
}

unordered_map<string, string> buildMap(ifstream &map_file)
{
	unordered_map<string, string> trans_map;
	string key, value;
	while (map_file >> key && getline(map_file, value))
	{
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("No rule for " + key);
	}
	return trans_map;
}

void wordTransform(ifstream &map_file, ifstream &input_file)
{
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input_file, text))
	{
		istringstream stream(text);
		string word;
		bool isFirstWord = true;
		while (stream>>word)
		{
			if (isFirstWord)
				isFirstWord = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}

}

int main()
{
	//wordCounting();
	ifstream map_file("data/rules.txt"), todo("data/todo.txt");
	if (map_file&&todo)
		wordTransform(map_file, todo);
	else
		cerr << "Fail to open documents." << endl;

	return 0;
}