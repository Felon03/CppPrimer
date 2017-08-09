#pragma once
/* 
    �޸�12.3���е�TextQuery������shared_ptr
    ��Աʹ��DebugDelete��Ϊ���ǵ�ɾ����
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
