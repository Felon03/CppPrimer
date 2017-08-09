#include"12.27.h"
#include<iostream>

void runQueries(std::ifstream &infile)
{
	// infile是一个ifstream，指向要处理的文件
	TextQuery tq(infile);		// 保存文件并简历查询map
	while (true)
	{
		std::cout << "Enter word to look for, or q to quit: ";
		string s;
		// 若遇到文件尾或者用户输入了q是循环终止
		if (!(std::cin >> s) || s == "q") break;
		// 指向查询并打印结果
		print(std::cout, tq.query(s)) << std::endl;
	}
}

int main()
{
	std::ifstream file("data/story.txt");
	runQueries(file);

	return 0;
}