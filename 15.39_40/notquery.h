#pragma once
#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "query_base.h"
#include "query.h"

//
// The NoyQuery class
// 
// The ~ operator generates a NotQuery, which holds a Query
// which it negates
//
class NotQuery : public Query_base {
	friend Query operator~(const Query&);
	NotQuery(const Query &q) : query(q) {}

	// virtuals
	std::string rep() const override
	{
		std::cout << "NotQuery::rep()\n";
		return "~(" + query.rep() + ")";
	}
	QueryResult eval(const TextQuery&) const override;

	Query query;
};

inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
	// There is an implicit conversion here.
	// The Query constructor that take shared_ptr is not
	// "explicit", thus the complier allows this conversion
	// same as
	// shared_ptr<Query_base> tmp(new NotQuery(expr));
	// return Query(tmp);
}

#endif // !NOTQUERY_H
