#pragma once
/* 在QueryResult类中添加名为begin和end的成员，返回一个迭代器，
	指向一个给定查询返回的行号set中的位置。再添加一个名为get_file的成员，
	返回一个shared_ptr，指向QueryResult对象中的文件
*/

#include"12.22.h"
using std::shared_ptr;

#include<iostream>
#include<fstream>
#include<map>
#include<set>

class QueryResult;																		// 为了定义函数query的返回类型，这个定义是必须的
class TextQuery {
public:
	TextQuery(std::ifstream&);
	QueryResult query(const string&) const;

private:
	shared_ptr<StrBlob> file;																	// 输入文件
	// 每个单词到它所在行号的映射
	std::map<std::string, 
		shared_ptr<std::set<StrBlob::size_type>>> wordmap;
};

class QueryResult {
	using qr_iter = std::set<StrBlob::size_type>::iterator;
	friend std::ostream &print(std::ostream&, QueryResult&);

public:
	QueryResult(string s, shared_ptr<std::set<StrBlob::size_type>> l, shared_ptr<StrBlob> f) :
		word(s), lines(l), file(f) {}

	qr_iter begin() const { return lines->begin(); }
	qr_iter end() const { return lines->end(); }

	shared_ptr<StrBlob> get_file() const { return file; }

private:
	string word;																				// 查询单词
	shared_ptr<std::set<StrBlob::size_type>> lines;		// 出现的行号
	shared_ptr<StrBlob> file;													// 输入文件
};

std::ostream &print(std::ostream &os, QueryResult &query_result);

