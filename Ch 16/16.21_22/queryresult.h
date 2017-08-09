#pragma once
#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include "textquery.h"

class QueryResult {
public:
	// default constructor
	QueryResult() = default;

	// copy constructor
	QueryResult(const QueryResult &qr);

	QueryResult(std::size_t c, const std::string &str,
		const TextQuery::sp_file_p &sp_f,
		const TextQuery::sp_map_p &sp_m);

	std::size_t getCounter() const { return counter; }

	std::string getQueryWord() const { return queryWord; }

	TextQuery::sp_file_p getSp_file() const { return sp_file; }

	TextQuery::sp_map_p getSp_map() const { return sp_map; }

private:
	// number of occurrence
	std::size_t counter = 0;
	// the word being searched
	std::string queryWord = "";
	// samrt pointer to a vector to store a file
	TextQuery::sp_file_p sp_file = nullptr;
	// smart pointer to a map to store results of queries
	TextQuery::sp_map_p sp_map = nullptr;
};

void print(std::ostream &os, const QueryResult &qr);

#endif // !QUERYRESULT_H
