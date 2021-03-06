#pragma once
/* 15.42(b)*/
#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<set>
#include"textquery.h"

//
// QueryResult
//
class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
	// 15.42(c)
	friend std::ostream& print(std::ostream&, const QueryResult&, size_t, size_t);
	friend std::ostream& operator<<(std::ostream&, const QueryResult&);

public:
	// constructor
	QueryResult(std::string s,
		std::shared_ptr<std::set<TextQuery::line_no>> sp_l,
		StrBlob f)
		: sought(s), sp_lines(sp_l), file(f) {}

	const StrBlob& get_file() const { return file; }

	std::set<TextQuery::line_no>::iterator begin() { return sp_lines->begin(); }
	std::set<TextQuery::line_no>::iterator end() { return sp_lines->end(); }

private:
	// data member
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> sp_lines;
	StrBlob file;
};

std::ostream& print(std::ostream&, const QueryResult&);
std::ostream& print(std::ostream&, const QueryResult&, size_t, size_t);

#endif // !QUERYRESULT_H
