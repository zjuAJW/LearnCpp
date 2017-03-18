#pragma once
#include "Query.h"
class WordQuery : public QueryBase {
	WordQuery(const std::string &);
	QueryResult eval(const TextQuery &tq) {
		return tq.query(word);
	}
	void rep();

	std::string word;
};
