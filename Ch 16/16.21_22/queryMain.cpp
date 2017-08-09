#include "textquery.h"
#include "queryresult.h"

void runQueries(std::ifstream &infile)
{
	TextQuery text_query(infile);						
	do
	{
		std::cout << "Enter word to look for or q to quit: ";
		std::string word;
		// �������ļ�β�����û������ˡ�q��ʱѭ����ֹ
		if (!(std::cin >> word) || word == "q") break;
		// ָ���ѯ����ӡ���
		print(std::cout, text_query.query(word));
	} while (true);
}

int main()
{
	std::ifstream ifs("data/story.txt");
	runQueries(ifs);

	return 0;
}