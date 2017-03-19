#pragma once
#include "Query.h"

class WordQuery : public QueryBase {
	friend class Query;
	WordQuery(const std::string & w) :word(w) { std::cout << "WrodQuery Construct(" << word << ")" << std::endl; }
	QueryResult eval(const TextQuery &tq) {
		return tq.query(word);
	}
	std:: string rep() { return word; }
	std::string word;
};

class NotQuery : public QueryBase {
	friend Query operator~(const Query &q);
	NotQuery(const Query &query) :q(query) {}
	QueryResult eval(const TextQuery &q);
	std::string rep() { return "~" + q.rep(); }
	Query q;
};