/* 执行runQueries函数*/
//#include"12.30.h"
#include"12.32.h"

using namespace std;

void runQueries(ifstream &infile)
{
	// infile是一个ifstream,指向将要处理的文件
	TextQuery text_query(infile);									// 保存文件并建立查询map
	// 与用户交互： 提示用户输入要查询的单词，完成查询并打印结果
	do
	{
		cout << "Enter word to look for or q to quit: ";
		string word;
		// 若遇到文件尾或者用户输入了‘q’时循环终止
		if (!(cin >> word) || word == "q") break;
		// 指向查询并打印结果
		print(cout, text_query.query(word)) << endl;
	} while (true);
}

int main()
{
	ifstream ifs("data/story.txt");
	runQueries(ifs);

	return 0;
}