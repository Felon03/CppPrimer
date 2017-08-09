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
	for (string line; std::getline(ifs, line); ++lineNo)			// ���ļ���ÿһ��
	{
		file->push_back(line);														// ��������ı�
		std::stringstream stream(line);									// ���ı��ֽ�Ϊ����
		for (string text, word; stream >> text; word.clear())		// �����е�ÿһ������
		{
			// ȥ��������
			std::remove_copy_if(text.begin(), text.end(),
				std::back_inserter(word), ispunct);
			auto &lines = wordmap[word];									// lines��һ��shared_ptr
			if (!lines)																			// ��һ�������������ʱ����ָ��Ϊ��
				lines.reset(new std::set<line_no>);					// ����һ���µ�set
			lines->insert(lineNo);													// �����кŲ���set��
		}
	}
}
/*
if (!lines)																			// ��һ�������������ʱ����ָ��Ϊ��
lines.reset(new std::set<line_no>);					// ����һ���µ�set
lines->insert(lineNo);													// �����кŲ���set��

ÿ�����ʶ����Ӧһ��set���������µ���ʱ��linesָ���setΪ��
��˶�̬����һ��set���������µ��ʵ��к�
*/



QueryResult TextQuery::query(const std::string &sought) const
{
	// ���δ�ҵ�sought������һ��ָ���set��ָ��
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	// ʹ��find�������±���������ҵ��ʣ����⽫������ӵ�wordmap��
	auto found = wordmap.find(sought);
	if (found != wordmap.end())
		return QueryResult(sought, found->second, file);		// �ҵ���
	else
		return QueryResult(sought, nodata, file);
}

std::ostream & print(std::ostream &os, const QueryResult &qr)
{
	// TODO: �ڴ˴����� return ���
	// ����ҵ��˵��ʣ���ӡ���ִ��������г��ֵ�λ��
	os << qr.word << " occurs " << qr.lines->size() << " "
		<< (qr.lines->size() > 1 ? "times." : "time") << std::endl;
	// ��ӡ���ʳ��ֵ�ÿһ��
	for (const auto &x : *qr.lines)		// ��set��ÿ������
		os << "\t(line " << x + 1 << ")" << qr.file->at(x) << std::endl;
	return os;

}
