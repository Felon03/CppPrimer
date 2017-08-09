#pragma once
/* 只用已经学到的知识对这两个类编写你自己的版本*/
// ref: https://github.com/pezy/CppPrimer/blob/master/ch12/ex12_27_30.h
#include<vector>
using std::vector;

#include<string>
using std::string;

#include<memory>
using std::shared_ptr;

#include<iostream>
#include<fstream>
#include<map>
#include<set>

class QueryResult;
class TextQuery {
public:
	using LineNo = vector<string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const string&) const;

private:
	shared_ptr<vector<string>> input;
	std::map<string, shared_ptr<std::set<LineNo>>> result;
};

class QueryResult {
public:
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(const string& s, shared_ptr<std::set<TextQuery::LineNo>> set,
		shared_ptr<vector<string>> v)
		: word(s), line_no(set), input(v)
	{

	}


private:
	string word;
	shared_ptr<std::set<TextQuery::LineNo>> line_no;
	shared_ptr<vector<string>> input;
};
