#pragma once
#ifndef QUERYHISTORY_H
#define QUERYHISTORY_H

#include <memory>
#include <vector>
#include "query.h"

class QueryHistory {
public:
	Query& operator[] (size_t n)
	{
		return *query_vec[n];
	}

	void add_query(const Query&);

	size_t size() const { return query_vec.size(); }
	
private:
	std::vector<std::shared_ptr<Query>> query_vec;
};

#endif // !QUERYHISTORY_H
