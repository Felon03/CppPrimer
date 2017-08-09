#pragma once
#ifndef WORDQUERY_H
#define WRODQUERY_H

#include "query_base.h"

//
// WordQuery class
// The only class tha actually performs a query on the given TextQuery object
// No public members defined in this class. All operation are through the friend
// class Query
//
class WordQuery : public Query_base {
	// class Query uses the WordQuery constructor
	friend class Query;
	WordQuery(const std::string &s) : query_word(s)
	{
		std::cout << "WordQuery::WordQuery(" + s + ")\n";
	}

	// virtuals 
	QueryResult eval(const TextQuery &t) const override
	{
		return t.quey(query_word);
	}
	std::string rep() const override
	{
		std::cout << "WordQuery::rep()\n";
		return query_word;
	}


	std::string query_word;

};


#endif // !WORDQUERY_H
