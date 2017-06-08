#include "12.33.h"
#include<iterator>
#include<sstream>
#include<algorithm>

//��ȡ�����ļ����������ʵ��кŵ�ӳ��
TextQuery::TextQuery(std::ifstream &ifs) : file(new StrBlob)
{
	StrBlob::size_type line_no{ 0 };															// �����к�
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
			if (!lines) lines.reset(new std::set<StrBlob::size_type>);	// ����һ���µ�set
			lines->insert(line_no);																		// �����кŲ���set��
		}
	}
}

QueryResult TextQuery::query(const string &sought) const
{
	// ���δ�ҵ�sought��������һ��ָ���set��ָ��
	static shared_ptr<std::set<StrBlob::size_type>>
		nodata(new std::set< StrBlob::size_type>);
	// ʹ��find�������±�����������ҵ��ʣ����⽫������ӵ�wordmap��
	auto found = wordmap.find(sought);
	if (found != wordmap.end())
		return QueryResult(sought, found->second, file);			// �ҵ�����
	else
		return QueryResult(sought, nodata, file);							// δ�ҵ�
}

std::ostream & print(std::ostream &os, QueryResult &query_result)
{
	// TODO: �ڴ˴����� return ���
	// ����ҵ��˵��ʣ���ӡ���ִ��������г��ֵ�λ��
	os << query_result.word << " occurs " << query_result.lines->size() << " "
		<< (query_result.lines->size() > 1 ? "times." : "time.") << std::endl;

	// ��ӡ���ʳ��ֵ�ÿһ��
	for (auto it = query_result.begin(); it != query_result.end(); ++it)
	{
		ConstStrBlobPtr p(*query_result.file, *it);
		os << "\t(line " << *it + 1 << ") " << p.deref() << std::endl;
	}
	return os;
}
