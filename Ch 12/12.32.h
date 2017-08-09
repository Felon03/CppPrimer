#pragma once
/*重写TextQuery和QueryResult类，用StrBlob代替vector<string>保存输入文件*/
#include"12.22.h"
#include<iostream>
#include<fstream>
#include<map>
#include<set>

class QueryResult;
class TextQuery {
public:
	TextQuery(std::ifstream&);
	QueryResult query(const string&) const;
private:
	std::shared_ptr<StrBlob> file;
	std::map < std::string, std::shared_ptr<std::set<StrBlob::size_type>>> wordmap;
};

class QueryResult {
	friend std::ostream &print(std::ostream&, QueryResult&);
public:
	QueryResult(std::string s,
		std::shared_ptr<std::set<StrBlob::size_type>> l,
		std::shared_ptr<StrBlob> f) :
		word(s), lines(l), file(f) {}

private:
	string word;
	std::shared_ptr<std::set<StrBlob::size_type>> lines;
	std::shared_ptr<StrBlob> file;
};

std::ostream &print(std::ostream &os, QueryResult &query_result);
