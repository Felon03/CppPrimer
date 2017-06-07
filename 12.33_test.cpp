#include"12.33.h"

void runQueries(std::ifstream &ifs)
{
	TextQuery text_query(ifs);
	do
	{
		std::cout << "Enter word to look for or q to quit: ";
		string word;
		if (!(std::cin >> word) || word == "q") break;
		print(std::cout, text_query.query(word)) << std::endl;
	} while (true);
}

int main()
{
	std::ifstream ifs("data/story.txt");
	runQueries(ifs);

	return 0;
}