#include "textquery.h"
#include "queryresult.h"
#include "DebugDelete.h"
#include <sstream>
#include <algorithm>

TextQuery::TextQuery(std::istream &fin)
	: sp_fileData(new std::vector<std::string>(), DebugDelete()),
	sp_queryMap(new std::map<std::string, std::set<int>>(), DebugDelete())
{
	std::string line;
	while (std::getline(fin, line))
		sp_fileData->push_back(line);
}

QueryResult TextQuery::query(const std::string &qWord) const
{
	// storing the amount of occurrence
	std::size_t counter = 0;
	// loop each line
	for (std::size_t i = 0; i != sp_fileData->size(); ++i)
	{
		// each word
		std::istringstream lineSteam((*sp_fileData)[i]);
		std::string word;
		while (lineSteam >> word)
		{
			if (!word.compare(qWord))
			{
				++counter;
				// add the index of the line into the result map
				(*sp_queryMap)[qWord].insert(i);
			}
		}
	}

	// create a object holding the result
	QueryResult qResult(counter, qWord, sp_fileData, sp_queryMap);
	return qResult;
}
