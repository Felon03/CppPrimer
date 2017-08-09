#include "textquery.h"
#include "queryresult.h"
#include <iostream>
#include <sstream>
#include <iterator>

TextQuery::TextQuery(std::ifstream &fin)
	: file(StrBlob()), wordMap(std::map<std::string, std::shared_ptr<std::set<line_no>>>())
{
	std::string line;

	// each line
	while (std::getline(fin, line))
	{
		file.push_back(line);
		int n = file.size() - 1;    // the current line number

		// each word
		std::stringstream lineStream(line);
		std::string word;
		while (lineStream>>word)
		{
			std::shared_ptr<std::set<line_no>> &sp_lines = wordMap[word];
			// if null
			if (!sp_lines)
				sp_lines.reset(new std::set<line_no>);
			sp_lines->insert(n);
		}
	}
}

QueryResult TextQuery::quey(const std::string &sought) const
{
	// dyanmically allocated set used for the word does not appear
	static std::shared_ptr<std::set<line_no>> noData(new std::set<line_no>);

	// fetch the iterator to the matching element in the map<word, lines>
	// std::map<std::string, std::shared_ptr<std::set<index_Tp>>>::const_iterator
	auto iter = wordMap.find(sought);
	if (iter == wordMap.end())
		return QueryResult(sought, noData, file);
	else
		return QueryResult(sought, iter->second, file);
}
