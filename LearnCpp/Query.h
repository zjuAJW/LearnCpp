#pragma once
#include "TextQuery.h"
#include <string>
class QueryBase {
	friend class Query;
private:
	virtual QueryResult eval(const TextQuery &) = 0;
	virtual void rep() = 0;
};

class Query : public QueryBase {
public:
	Query(const std::string&);
	QueryResult eval(const TextQuery & text) {
		return q->eval(text);
	}
	void rep() {
		q->rep();
	}
private:
	Query(std::shared_ptr<QueryBase> query) :q(query) {}
	std::shared_ptr<QueryBase> q;
};