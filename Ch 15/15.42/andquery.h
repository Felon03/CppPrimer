#pragma once
#ifndef ANDQUERY_H
#define ANDQUERY_H

#include "binaryquery.h"
//#include <algorithm>
//#include <iterator>

class AndQuery : public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right)
		: BinaryQuery(left, right, "&")
	{
		std::cout << "AndQuery::AndQuery()\n";
	}

	// inherits rep and define eval
	QueryResult eval(const TextQuery&) const override;

};

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

#endif // !ANDQUERY_H
