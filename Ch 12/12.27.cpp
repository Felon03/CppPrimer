#include "12.27.h"
#include<sstream>
#include<algorithm>
#include<iterator>

TextQuery::TextQuery(std::ifstream &ifs) : input(new vector<string>)
{
	LineNo lineNo{ 0 };
	for (string line; std::getline(ifs, line); ++lineNo)
	{
		input->push_back(line);
		std::istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear())
		{
			// 去掉标点符号
			std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
			auto &lno = result[word];
			if (!lno) lno.reset(new std::set<LineNo>);
			lno->insert(lineNo);
		}
	}
}

QueryResult TextQuery::query(const string &str) const
{
	// 使用static，分配一次内内存
	static shared_ptr<std::set<LineNo>> no_date(new std::set<LineNo>);
	auto found = result.find(str);
	if (found == result.end())
		return QueryResult(str, no_date, input);
	else
		return QueryResult(str, found->second, input);
}


std::ostream & print(std::ostream &out, const QueryResult &query_result)
{
	// TODO: 在此处插入 return 语句
	out << query_result.word << " occurs " << query_result.line_no->size()
		<< (query_result.line_no->size() > 1 ? " times." : " time") << std::endl;
	for (auto &i : *query_result.line_no)
		out << "\t(line " << i + 1 << ")" << query_result.input->at(i) << std::endl;
	return out;
}
