#include "queryresult.h"

// copy constructor
// inline member function should be defined in *.h files
// c++ primer 5th edition(ch) pp 245 
// "inline成员函数也应该与相应的类定义在同一个头文件中"
//inline QueryResult::QueryResult(const QueryResult &qr)
//	: counter(qr.getCounter()), queryWord(qr.getQueryWord()),
//	sp_file(qr.getSp_file()), sp_map(qr.getSp_map())
//{
//}

QueryResult::QueryResult(const QueryResult & qr)
	: counter(qr.getCounter()), queryWord(qr.getQueryWord()),
	sp_file(qr.getSp_file()), sp_map(qr.getSp_map())
{
}

QueryResult::QueryResult(std::size_t c, const std::string & str,
	const TextQuery::sp_file_p & sp_f, 
	const TextQuery::sp_map_p & sp_m)
	: counter(c), queryWord(str), sp_file(sp_f), sp_map(sp_m)
{
}

// a non-member function prints the result of a query
void print(std::ostream & os, const QueryResult & qr)
{
	// get word being queried
	const std::string queryWord = qr.getQueryWord();

	// print the word and occurrence times
	os << "The word[" << queryWord << "] occurs "
		<< qr.getCounter() << " times:\n";

	// get smart pointers to the map and the file
	auto sp_m = qr.getSp_map();
	auto sp_f = qr.getSp_file();

	// print each line in which it appears and the corresponding index
	for (const auto &index : (*sp_m)[queryWord])
		std::cout << "\n(Line " << index << ") " << (*sp_f)[index] << "\n\n";
}
