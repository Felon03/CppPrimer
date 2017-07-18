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
