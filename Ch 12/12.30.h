#pragma once
/*�������Լ��汾��TextQuery��QueryResult�࣬��ִ��runQueries����*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<memory>
#include<set>
#include<map>

class QueryResult;
class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string &) const;

private:
	std::shared_ptr<std::vector<std::string>> file;		// �����ļ�
	std::map < std::string,
		std::shared_ptr<std::set<line_no>>>  wordmap;
};

class QueryResult {
	friend std::ostream &print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s,
		std::shared_ptr<std::set<TextQuery::line_no>> l,
		std::shared_ptr<std::vector<std::string>> f) :
		word(s), lines(l), file(f) {}

private:
	std::string word;																				// ��ѯ�ĵ���
	std::shared_ptr<std::set<TextQuery::line_no>> lines;		// ����к�
	std::shared_ptr<std::vector<std::string>> file;						// �����ļ�
};

std::ostream &print(std::ostream&, QueryResult&);