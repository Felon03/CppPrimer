#include "12.30.h"
#include<algorithm>
#include<sstream>
#include<iterator>

using	 std::string;
using std::vector;

TextQuery::TextQuery(std::ifstream &ifs) : file(new vector<string>)
{
	line_no lineNo{ 0 };
	//int lineNo = 0;
	for (string line; std::getline(ifs, line); ++lineNo)			// 对文件中每一行
	{
		file->push_back(line);														// 保存此行文本
		std::stringstream stream(line);									// 将文本分解为单词
		for (string text, word; stream >> text; word.clear())		// 对行中的每一个单词
		{
			// 去掉标点符号
			std::remove_copy_if(text.begin(), text.end(),
				std::back_inserter(word), ispunct);
			auto &lines = wordmap[word];									// lines是一个shared_ptr
			if (!lines)																			// 第一次遇到这个单词时，此指针为空
				lines.reset(new std::set<line_no>);					// 分配一个新的set
			lines->insert(lineNo);													// 将此行号插入set中
		}
	}
}
/*
if (!lines)																			// 第一次遇到这个单词时，此指针为空
lines.reset(new std::set<line_no>);					// 分配一个新的set
lines->insert(lineNo);													// 将此行号插入set中

每个单词都会对应一个set，当输入新单词时，lines指向的set为空
因此动态申请一个set用来保存新单词的行号
*/



QueryResult TextQuery::query(const std::string &sought) const
{
	// 如果未找到sought，返回一个指向此set的指针
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	// 使用find而不是下标运算符查找单词，避免将单词添加到wordmap中
	auto found = wordmap.find(sought);
	if (found != wordmap.end())
		return QueryResult(sought, found->second, file);		// 找到了
	else
		return QueryResult(sought, nodata, file);
}

std::ostream & print(std::ostream &os, const QueryResult &qr)
{
	// TODO: 在此处插入 return 语句
	// 如果找到了单词，打印出现次数和所有出现的位置
	os << qr.word << " occurs " << qr.lines->size() << " "
		<< (qr.lines->size() > 1 ? "times." : "time") << std::endl;
	// 打印单词出现的每一行
	for (const auto &x : *qr.lines)		// 对set中每个单词
		os << "\t(line " << x + 1 << ")" << qr.file->at(x) << std::endl;
	return os;

}
