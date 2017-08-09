#include "queryresult.h"

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
	// TODO: 在此处插入 return 语句
	os << qr.sought << " occurs " << qr.sp_lines->size() << " "
		<< "times" << "\n";

	// print each line in which word appears
	for (auto &index : *qr.sp_lines)
	{
		os << "\t(line " << index + 1 << ") ";
		const StrBlobPtr wp(qr.file, index);
		os << wp.deref() << "\n";
	}
	return os;
}

std::ostream & print(std::ostream &os, const QueryResult &qr, size_t begin, size_t end)
{
	// TODO: 在此处插入 return 语句
	if (begin > end)
	{
		os << "Illegal query range!";
		return os;
	}
	else
	{
		os << "Query for " << qr.sought << ":\n";
		for (const auto &index : *qr.sp_lines)
		{
			if (index + 1 >= begin && index + 1 <= end)
			{
				os << "\t(line " << index + 1 << ")";
				const StrBlobPtr wp(qr.file, index);
				os << wp.deref() << "\n";
			}
		}
		return os;
	}


}

std::ostream & operator<<(std::ostream &os, const QueryResult &qr)
{
	// TODO: 在此处插入 return 语句
	os << qr.sought << " occurs " << qr.sp_lines->size() << " "
		<< "times" << "\n";
	// 打印所有单词出现的行
	for (auto &index : *qr.sp_lines)
	{
		os << "\t(line " << index + 1 << ")";
		const StrBlobPtr wp(qr.file, index);
		os << wp.deref() << "\n";
	}
	return os;
}
