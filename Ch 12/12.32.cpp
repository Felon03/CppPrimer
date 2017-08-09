#include "12.32.h"
#include<sstream>
#include<iterator>
#include<algorithm>

TextQuery::TextQuery(std::ifstream &ifs) : file(new StrBlob)
{
	StrBlob::size_type lineNo{ 0 };
	for (string line; std::getline(ifs, line); ++lineNo)
	{
		file->push_back(line);
		std::istringstream stream(line);
		for (string text, word; stream >> text; word.clear())
		{
			std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
			auto &lines = wordmap[word];
			if (!lines)
				lines.reset(new std::set<StrBlob::size_type>);
			lines->insert(lineNo);
		}
	}
}

QueryResult TextQuery::query(const string &sought) const
{
	static std::shared_ptr<std::set<StrBlob::size_type>> nodata(new std::set < StrBlob::size_type>);
	auto found = wordmap.find(sought);
	if (found != wordmap.end())
		return QueryResult(sought, found->second, file);
	else
	return QueryResult(sought,nodata, file);
}

std::ostream & print(std::ostream & os, QueryResult & query_result)
{
	// TODO: 在此处插入 return 语句
	os << query_result.word << " occurs " << query_result.lines->size() << " "
		<< (query_result.lines->size() > 1 ? "times." : "time.") << std::endl;
	for (const auto &x : *query_result.lines)
	{
		ConstStrBlobPtr p(*query_result.file, x);
		os << "\t(line " << x + 1 << ") " << p.deref() << std::endl;
	}
	return os;
}
