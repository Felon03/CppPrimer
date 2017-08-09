/*
15.39 ʵ��Query���Query_base�࣬��565ҳ�еı��ʽ��ֵ����ӡ�����Ϣ��
��֤��ĳ����Ƿ���ȷ

15.40 ��OrQuery��eval�����У����rhs��Ա���ؿռ�������ʲô��
���lhs�ǿռ��أ����lhs��rhs���ǿռ��ֽ�����ʲô

ʲô�����ᷢ����ֻ�������ѯ���Ϊ��
ret_lines�Ƕ�̬����ģ����lhs��rhs��Ϊ�յĻ�����ret_linesҲΪ�գ�
��û�н��
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
#include "queryhistory.h"
#include "notquery.h"

int main()
{
	std::ifstream file("data/story.txt");
	TextQuery tQuery(file);
	QueryHistory history;

	Query q = Query("fiery") & Query("bird") | Query("wind");
	Query q1 = Query("fieryzzz") | Query("wind");
	Query q2 = Query("fieryaaa") | Query("windbbb");
	Query q3 = Query("flight.");

	//history.add_query(q);
	//history.add_query(q1);
	//history.add_query(q2);
	//history.add_query(q3);
	//auto size = history.size();
	//for (size_t i = 0; i != size; ++i)
	//	std::cout << history[i].eval(tQuery);

	Query query = ~Query("Alice");
	QueryResult result = query.eval(tQuery);
	print(std::cout, result, 10, 20);
	//std::cout << query.eval(tQuery);
	//std::cout << q << std::endl;
	//std::cout << q.eval(tQuery);
	//std::cout << q1.eval(tQuery);
	//std::cout << q2.eval(tQuery);
	//std::cout << q3.eval(tQuery);
	return 0;
}