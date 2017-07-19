#include "notquery.h"

QueryResult NotQuery::eval(const TextQuery &text) const
{
	// ͨ��Query��������eval���������
	auto result = query.eval(text);
	// ��ʼʱsetΪ��
	auto ret_lines = std::make_shared<std::set<line_no>>();
	// �����������ֵ��������н��е���
	auto beg = result.begin(), end = result.end();
	// ���������ļ���ÿһ�У�������в���result�У�������ӵ�ret_lines
	auto sz = result.get_file().size();
	for (size_t n = 0; n != sz; ++n)
	{
		// �����û�д�����result��������
		// ��鵱ǰ���Ƿ����
		if (beg == end || *beg != n)
			ret_lines->insert(n);    // ���������result���У������һ��
		else if (beg != end)
			++beg;    // ���������ȡresult����һ��(����еĻ�)
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}
