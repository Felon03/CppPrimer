#include "andquery.h"
#include <algorithm>
#include <iterator>

QueryResult AndQuery::eval(const TextQuery &text) const
{
	// 通过Query运算对象进行虚调用，以获得运算对象的查询结果set
	auto left = lhs.eval(text), right = rhs.eval(text);
	// 保存left和right交集的set
	auto ret_lines = std::make_shared<std::set<line_no>>();
	// 将两个返回的交集写入一个目的迭代器中
	// 本次调用的目的迭代器想ret添加元素
	// set_intersection #include <algorithm>
	// inserter #include <iterator>
	std::set_intersection(left.begin(), left.end(),
		right.begin(), right.end(),
		std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}
