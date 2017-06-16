#pragma once
#include"13.42_StrVec.h"
#include<string>
#include<memory>
#include<iostream>
#include<fstream>
#include<map>
#include<set>

using std::shared_ptr;

class QueryResult;																		// 为了定义函数query的返回类型，这个定义是必须的
class TextQuery {
public:
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;

private:
	shared_ptr<StrVec> file;																	// 输入文件
	// 每个单词到它所在行号的映射
	std::map<std::string,
		shared_ptr<std::set<size_t>>> wordmap;
};

class QueryResult {
	//using qr_iter = std::set<size_t>::iterator;
	friend std::ostream &print(std::ostream&, const QueryResult&);

public:
	QueryResult(const std::string &s, shared_ptr<std::set<size_t>> l, shared_ptr<StrVec> f) :
		word(s), lines(l), file(f) {}

	//qr_iter begin() const { return lines->begin(); }
	//qr_iter end() const { return lines->end(); }

	shared_ptr<StrVec> get_file() const { return file; }

private:
	std::string word;																				// 查询单词
	shared_ptr<std::set<size_t>> lines;		// 出现的行号
	shared_ptr<StrVec> file;													// 输入文件
};

std::ostream &print(std::ostream &os, const QueryResult &query_result);
