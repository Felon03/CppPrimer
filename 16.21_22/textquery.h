#pragma once
/* 
    修改12.3节中的TextQuery程序，令shared_ptr
    成员使用DebugDelete作为他们的删除器
*/
#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<memory>

class QueryResult;

class TextQuery {
public:
	using sp_file_p = std::shared_ptr<std::vector<std::string>>;
	using sp_map_p = std::shared_ptr<std::map<std::string, std::set<int>>>;

	// constructors
	TextQuery() = default;
	TextQuery(std::istream &fin);

	// query operation
	QueryResult query(const std::string &qWord) const;

private:
	// smart pointer to a vector to store a file
	sp_file_p sp_fileData = nullptr;
	// smart pointer to a map to store results of queries
	sp_map_p sp_queryMap = nullptr;

};

#endif // !TEXTQUERY_H
