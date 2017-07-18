// 15.34 ���ͼ15.3��pp565�������ı��ʽ��
// (a) �оٳ��ڴ�����ʽ�Ĺ�����ִ�е����й��캯��
// Query q = Query("fiery") & Query("bird") | Query("wind");
// 1: Query::Query(const std::string &s) where s = "fiery", "bird" and "wind"
// 2: WordQuery::WordQuery(const std::string &s) where s = "fiery", "bird" and "wind"
// 3: AndQuery::AndQuery(const Query &left, const Query &right)
// 4: BinaryQuery::BinayQuery(const Query &l, const Query &r, std::string s) where s = "&"
// 5: Query::Query(std::shared_ptr<Query_base> query) 2 times
// 6: OrQuery::OrQuery(const Query &left, const Query &right)
// 7: BinaryQuery::BinaryQuery(const Query &l, const Query &r, std::string s) where s = "|"
// 8: Quer::Query(std::shared_ptr<Query_base> query) 2 times
//
// (b) �оٳ�cout<<q�����õ�rep
//
// Query::rep()
// BinaryQuery::rep()
// Query::rep()
// WordQuery::rep()
// Query::rep()
// BinaryQuery::rep()
// Query::rep()
// WordQuery::rep()
// Query::rep()
// WordQuery::rep()
// ((fiery & bird) | wind)
//
// (c) �оٳ�q.eval()�����õ�eval
//
// 15.35 ʵ��Query���Query_base�࣬������Ҫ����rep���趨��eval
// 
// 15.36 �ڹ��캯����rep��Ա����Ӵ�ӡ��䣬���д����Լ���(a)(b)�Ļش��Ƿ���ȷ
// ��Ҫ����eval
/*
(a)
WordQuery::WordQuery(wind)
Query::Query(const std::sting &s) where s= wind
WordQuery::WordQuery(bird)
Query::Query(const std::sting &s) where s= bird
WordQuery::WordQuery(fiery)
Query::Query(const std::sting &s) where s= fiery
BinayQuery::BinaryQuery() where s=&
AndQuery::AndQuery()
BinayQuery::BinaryQuery() where s=|
OrQuery::OrQuery()
(b)
Query::rep()
BinaryQuery::rep()
Query::rep()
WordQuery::rep()
Query::rep()
BinaryQuery::rep()
Query::rep()
WordQuery::rep()
Query::rep()
WordQuery::rep()
((fiery & bird) | wind)
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "queryresult.h"
#include "textquery.h"
#include "query_base.h"
#include "query.h"
#include "andquery.h"
#include "orquery.h"

int main()
{
	std::ifstream file("data/story.txt");

	TextQuery tQuery(file);
	Query q = Query("fiery") & Query("bird") | Query("wind");
	std::cout << q << std::endl;
	return 0;
}