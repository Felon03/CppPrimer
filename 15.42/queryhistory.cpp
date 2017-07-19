#include "queryhistory.h"

void QueryHistory::add_query(const Query &query)
{
	std::shared_ptr<Query> p = std::make_shared<Query>(query);
	query_vec.push_back(p);
}
