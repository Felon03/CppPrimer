#include "queryresult.h"

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
	// TODO: �ڴ˴����� return ���
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
	// TODO: �ڴ˴����� return ���
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
	// TODO: �ڴ˴����� return ���
	os << qr.sought << " occurs " << qr.sp_lines->size() << " "
		<< "times" << "\n";
	// ��ӡ���е��ʳ��ֵ���
	for (auto &index : *qr.sp_lines)
	{
		os << "\t(line " << index + 1 << ")";
		const StrBlobPtr wp(qr.file, index);
		os << wp.deref() << "\n";
	}
	return os;
}
