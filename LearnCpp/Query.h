#pragma once
#include "TextQuery.h"
#include <string>
#include <iostream>

class QueryBase {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
private:
	virtual QueryResult eval(const TextQuery &) = 0;
	virtual std::string rep() = 0;
};

class Query{
	friend Query operator&(const Query &lhs, const Query &rhs);
	friend Query operator|(const Query &lhs, const Query &rhs);
	friend Query operator~(const Query &q);
public:
	Query(const std::string& word);
	QueryResult eval(const TextQuery & text) {
		return q->eval(text);
	}
	std::string rep() {
		return q->rep();
	}
private:
	Query(std::shared_ptr<QueryBase> query) :q(query) { std::cout << "Query(ptr)" << std::endl; }
	std::shared_ptr<QueryBase> q;
};