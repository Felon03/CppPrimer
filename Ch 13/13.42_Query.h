#pragma once
#include"13.42_StrVec.h"
#include<string>
#include<memory>
#include<iostream>
#include<fstream>
#include<map>
#include<set>

using std::shared_ptr;

class QueryResult;																		// Ϊ�˶��庯��query�ķ������ͣ���������Ǳ����
class TextQuery {
public:
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;

private:
	shared_ptr<StrVec> file;																	// �����ļ�
	// ÿ�����ʵ��������кŵ�ӳ��
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
	std::string word;																				// ��ѯ����
	shared_ptr<std::set<size_t>> lines;		// ���ֵ��к�
	shared_ptr<StrVec> file;													// �����ļ�
};

std::ostream &print(std::ostream &os, const QueryResult &query_result);
