#include "12.33.h"
#include<iterator>
#include<sstream>
#include<algorithm>

//读取输入文件并建立单词到行号的映射
TextQuery::TextQuery(std::ifstream &ifs) : file(new StrBlob)
{
	StrBlob::size_type line_no{ 0 };															// 保存行号
	for (string line; std::getline(ifs, line); ++line_no)							// 对文件中的每一行
	{
		file->push_back(line);																			// 保存此行文本
		std::istringstream stream(line);														// 将文本分解为单词
		for (string text, word; stream >> text; word.clear())				// 对行中每个单词
		{
			std::remove_copy_if(text.begin(), text.end(),						// 去除单词中的标点符号
				std::back_inserter(word), ispunct);
			// 如果单词不在wordmap中，以之为下标在wordmap中添加一项
			auto &lines = wordmap[word];
			// 第一次遇到这个单词时，lines的指针为空
			if (!lines) lines.reset(new std::set<StrBlob::size_type>);	// 分配一个新的set
			lines->insert(line_no);																		// 将此行号插入set中
		}
	}
}

QueryResult TextQuery::query(const string &sought) const
{
	// 如果未找到sought，将返回一个指向此set的指针
	static shared_ptr<std::set<StrBlob::size_type>>
		nodata(new std::set< StrBlob::size_type>);
	// 使用find而不是下标运算符来查找单词，避免将单词添加到wordmap中
	auto found = wordmap.find(sought);
	if (found != wordmap.end())
		return QueryResult(sought, found->second, file);			// 找到单词
	else
		return QueryResult(sought, nodata, file);							// 未找到
}

std::ostream & print(std::ostream &os, QueryResult &query_result)
{
	// TODO: 在此处插入 return 语句
	// 如果找到了单词，打印出现次数和所有出现的位置
	os << query_result.word << " occurs " << query_result.lines->size() << " "
		<< (query_result.lines->size() > 1 ? "times." : "time.") << std::endl;

	// 打印单词出现的每一行
	for (auto it = query_result.begin(); it != query_result.end(); ++it)
	{
		ConstStrBlobPtr p(*query_result.file, *it);
		os << "\t(line " << *it + 1 << ") " << p.deref() << std::endl;
	}
	return os;
}
