/*实现你自己版本的单词转换程序*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>

using namespace std;
map<string, string> buildMap(ifstream &);
const string &transform(const string &, const map<string, string> &);
void word_transform(ifstream &, ifstream &);

// 通过使用转换规则对输入进行转换并输出转换后的结果
void word_transform(ifstream &map_file, ifstream &input)
{
	ofstream output("data/transform_done.txt");
	auto trans_map = buildMap(map_file);			// 保存转换规则
	string text;																// 保存输入中的每一行
	while (getline(input, text))								// 读取一行输入
	{
		istringstream stream(text);							// 读取每个单词
		string word;
		bool firtstword = true;
		while (stream>>word)
		{
			if (firtstword)
				firtstword = false;
			else
			{
				cout << " ";													// 在单词间打印一个空格
				output << " ";
			}

			// transform返回他的第一个参数或其他转换之后的形式
			cout << transform(word, trans_map);	// 打印输出
			output << transform(word, trans_map);
		}
		cout << endl;
		output << endl;
	}
}

// 建立转换规则
map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> trans_map;				// 保存转换规则
	string key, value;											// 要转换的单词和转换后的内容
	// 读取第一个单词存入key中，行中剩余内容存入value
	while (map_file>>key && getline(map_file, value))
	{
		if (value.size() > 1)		// 检查是否有转换规则
			trans_map[key] = value.substr(1);		// 跳过前导空格
		else
			throw runtime_error("no rule for " + key);
	}
	return trans_map;
}

const string &transform(const string &s, const map<string, string> &m)
{
	// 实际的转换工作
	auto map_it = m.find(s);
	// 如果单词在转换规则map中
	if (map_it != m.end())
		return map_it->second;			// 使用替换短语
	else
		return s;										// 否则返回原string
}

int main()
{
	ifstream ifs_map("data/rules.txt"), ifs_content("data/todo.txt");
	if (ifs_map&&ifs_content)
		word_transform(ifs_map, ifs_content);
	else
		cerr << "Can't find the documents." << endl;

	return 0;
}