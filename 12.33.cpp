#include "12.33.h"
#include<iterator>
#include<sstream>
#include<algorithm>

TextQuery::TextQuery(std::ifstream &ifs) : file(new StrBlob)
{
	StrBlob::size_type line_no{ 0 };
	for (string line; std::getline(ifs, line); ++line_no)
	{
		file->push_back(line);
		std::istringstream stream(line);
		for (string text, word; stream >> text; word.clear())
		{
			std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
			auto &lines = wordmap[word];
			if (!lines) lines.reset(new std::set<StrBlob::size_type>);
			lines->insert(line_no);
		}
	}
}

QueryResult TextQuery::query(const string &sought) const
{
	static shared_ptr<std::set<StrBlob::size_type>>
		nodata(new std::set< StrBlob::size_type>);
	auto found = wordmap.find(sought);
	if (found != wordmap.end())
		return QueryResult(sought, found->second, file);
	else
		return QueryResult(sought, nodata, file);
}

std::ostream & print(std::ostream &os, QueryResult &query_result)
{
	// TODO: 在此处插入 return 语句
	os << query_result.word << " occurs " << query_result.lines->size() << " "
		<< (query_result.lines->size() > 1 ? "times." : "time.") << std::endl;

	for (auto it = query_result.begin(); it != query_result.end(); ++it)
	{
		ConstStrBlobPtr p(*query_result.file, *it);
		os << "\t(line " << *it + 1 << ") " << p.deref() << std::endl;
	}
	return os;
}
