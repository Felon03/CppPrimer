#include "notquery.h"

QueryResult NotQuery::eval(const TextQuery &text) const
{
	// 通过Query运算对象对eval进行虚调用
	auto result = query.eval(text);
	// 开始时set为空
	auto ret_lines = std::make_shared<std::set<line_no>>();
	// 在运算对象出现的所有行中进行迭代
	auto beg = result.begin(), end = result.end();
	// 对于输入文件的每一行，如果改行不在result中，则将其添加到ret_lines
	auto sz = result.get_file().size();
	for (size_t n = 0; n != sz; ++n)
	{
		// 如果还没有处理完result的所有行
		// 检查当前行是否存在
		if (beg == end || *beg != n)
			ret_lines->insert(n);    // 如果不存在result当中，添加这一行
		else if (beg != end)
			++beg;    // 否则继续获取result的下一行(如果有的话)
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}
