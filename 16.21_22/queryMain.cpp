#include "textquery.h"
#include "queryresult.h"

void runQueries(std::ifstream &infile)
{
	TextQuery text_query(infile);						
	do
	{
		std::cout << "Enter word to look for or q to quit: ";
		std::string word;
		// 若遇到文件尾或者用户输入了‘q’时循环终止
		if (!(std::cin >> word) || word == "q") break;
		// 指向查询并打印结果
		print(std::cout, text_query.query(word));
	} while (true);
}

int main()
{
	std::ifstream ifs("data/story.txt");
	runQueries(ifs);

	return 0;
}