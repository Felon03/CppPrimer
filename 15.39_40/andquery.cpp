#include "andquery.h"
#include <algorithm>
#include <iterator>

QueryResult AndQuery::eval(const TextQuery &text) const
{
	// ͨ��Query��������������ã��Ի���������Ĳ�ѯ���set
	auto left = lhs.eval(text), right = rhs.eval(text);
	// ����left��right������set
	auto ret_lines = std::make_shared<std::set<line_no>>();
	// ���������صĽ���д��һ��Ŀ�ĵ�������
	// ���ε��õ�Ŀ�ĵ�������ret���Ԫ��
	// set_intersection #include <algorithm>
	// inserter #include <iterator>
	std::set_intersection(left.begin(), left.end(),
		right.begin(), right.end(),
		std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}
