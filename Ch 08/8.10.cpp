/*编写程序，将来自一个文件中的行保存在一个vector<string>中。
然后使用一个istringstream从vector读取数据元素，每次读取一个单词。
*/
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
	string line, word;
	vector<string> words;
	ifstream input(argv[1]);
	if (!input)
	{
		cerr << "No data?!" << endl;
		return -1;
	}
	while (getline(input, line))
	{
		istringstream read(line);
		while (read >> word)
			words.push_back(word);
	}

	for (const auto &x : words)
		cout << x << endl;

	return 0;
}