#pragma once
#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string>
#include <memory>
#include "query_base.h"
#include "queryresult.h"
#include "wordquery.h"

//
// interface class to manage the Query_base inheritance hierachy
//
class Query {
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	// build a new word query
	Query(const std::string &s) : q(new WordQuery(s))
	{
		std::cout << "Query::Query(const std::sting &s) where s= " + s + "\n";
	}

	// interface functions: call the corresponding Query_base operators
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	std::string rep() const
	{ 
		std::cout << "Query::rep()\n";
		return q->rep();
	}
private:
	// constructor only for friends
	Query(std::shared_ptr<Query_base> query) : q(query) {}
	std::shared_ptr<Query_base> q;
};

inline std::ostream& operator<<(std::ostream &os, const Query &query)
{
	// make a virual call through its Query_base pointer to rep()
	return os << query.rep();
}

#endif // !QUERY_H
