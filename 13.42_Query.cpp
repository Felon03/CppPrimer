#include "13.42_Query.h"
#include<iterator>
#include<sstream>
#include<algorithm>

using std::string;

//��ȡ�����ļ����������ʵ��кŵ�ӳ��
TextQuery::TextQuery(std::ifstream &ifs) : file(new StrVec)
{
	size_t line_no{ 0 };															// �����к�
	for (string line; std::getline(ifs, line); ++line_no)							// ���ļ��е�ÿһ��
	{
		file->push_back(line);																			// ��������ı�
		std::istringstream stream(line);														// ���ı��ֽ�Ϊ����
		for (string text, word; stream >> text; word.clear())				// ������ÿ������
		{
			std::remove_copy_if(text.begin(), text.end(),						// ȥ�������еı�����
				std::back_inserter(word), ispunct);
			// ������ʲ���wordmap�У���֮Ϊ�±���wordmap�����һ��
			auto &lines = wordmap[word];
			// ��һ�������������ʱ��lines��ָ��Ϊ��
			if (!lines) lines.reset(new std::set<size_t>);	// ����һ���µ�set
			lines->insert(line_no);																		// �����кŲ���set��
		}
	}
}

QueryResult TextQuery::query(const string &sought) const
{
	// ���δ�ҵ�sought��������һ��ָ���set��ָ��
	static shared_ptr<std::set<size_t>>
		nodata(new std::set< size_t>);
	// ʹ��find�������±�����������ҵ��ʣ����⽫������ӵ�wordmap��
	auto found = wordmap.find(sought);
	if (found != wordmap.end())
		return QueryResult(sought, found->second, file);			// �ҵ�����
	else
		return QueryResult(sought, nodata, file);							// δ�ҵ�
}

std::ostream & print(std::ostream &os, const QueryResult &query_result)
{
	// TODO: �ڴ˴����� return ���
	// ����ҵ��˵��ʣ���ӡ���ִ��������г��ֵ�λ��
	os << query_result.word << " occurs " << query_result.lines->size() << " "
		<< (query_result.lines->size() > 1 ? "times." : "time.") << std::endl;

	// ��ӡ���ʳ��ֵ�ÿһ��
	for (auto i : *query_result.lines)
		os << "\t(line " << i + 1 << ")" << query_result.file->at(i) << std::endl;
	return os;
}
