// 15.34 针对图15.3（pp565）构建的表达式：
// (a) 列举出在处理表达式的过程中执行的所有构造函数
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
// (b) 列举出cout<<q所调用的rep
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
// (c) 列举出q.eval()所调用的eval
//
// 15.35 实现Query类和Query_base类，其中需要定义rep无需定义eval
// 
// 15.36 在构造函数和rep成员中添加打印语句，运行代码以检验(a)(b)的回答是否正确
// 需要定义eval
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