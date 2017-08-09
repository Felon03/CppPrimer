#pragma once
/* ��QueryResult���������Ϊbegin��end�ĳ�Ա������һ����������
	ָ��һ��������ѯ���ص��к�set�е�λ�á������һ����Ϊget_file�ĳ�Ա��
	����һ��shared_ptr��ָ��QueryResult�����е��ļ�
*/

#include"12.22.h"
using std::shared_ptr;

#include<iostream>
#include<fstream>
#include<map>
#include<set>

class QueryResult;																		// Ϊ�˶��庯��query�ķ������ͣ���������Ǳ����
class TextQuery {
public:
	TextQuery(std::ifstream&);
	QueryResult query(const string&) const;

private:
	shared_ptr<StrBlob> file;																	// �����ļ�
	// ÿ�����ʵ��������кŵ�ӳ��
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
	string word;																				// ��ѯ����
	shared_ptr<std::set<StrBlob::size_type>> lines;		// ���ֵ��к�
	shared_ptr<StrBlob> file;													// �����ļ�
};

std::ostream &print(std::ostream &os, QueryResult &query_result);

