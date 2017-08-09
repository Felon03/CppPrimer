/*
15.39 实现Query类和Query_base类，求565页中的表达式的值并打印相关信息，
验证你的程序是否正确

15.40 在OrQuery的eval函数中，如果rhs成员返回空集将发生什么？
如果lhs是空集呢？如果lhs和rhs都是空集又将发生什么

什么都不会发生，只是输出查询结果为空
ret_lines是动态分配的，如果lhs和rhs都为空的话，则ret_lines也为空，
即没有结果
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
	Query q1 = Query("fieryzzz") | Query("wind");
	Query q2 = Query("fieryaaa") | Query("windbbb");
	Query q3 = Query("flight.");
	//std::cout << q << std::endl;
	std::cout << q.eval(tQuery);
	std::cout << q1.eval(tQuery);
	std::cout << q2.eval(tQuery);
	std::cout << q3.eval(tQuery);
	return 0;
}