#include "Query.h"
#include "BinaryQuery.h"
#include "TextQuery.h"
#include "WordQuery.h"
#include <algorithm>
#include <iterator>

QueryResult AndQuery::eval(const TextQuery & text) {
	auto lr = lhs.eval(text);
	auto rr = rhs.eval(text);
	auto lines = std::make_shared<std::set<line_no>>();
	set_intersection(lr.begin(), lr.end(), rr.begin(),rr.end(),inserter(*lines,lines->begin()));
	return QueryResult(rep(), lr.getFiles(), lines);
}

QueryResult OrQuery::eval(const TextQuery & text) {
	auto lr = lhs.eval(text);
	auto rr = rhs.eval(text);
	auto lines = std::make_shared<std::set<line_no>>(lr.begin(),lr.end());
	lines->insert(rr.begin(), rr.end());
	return QueryResult(rep(), lr.getFiles(), lines);
}

QueryResult NotQuery::eval(const TextQuery & text) {
	auto result = q.eval(text);
	auto lines = std::make_shared<std::set<line_no>>();
	auto size = result.getFiles()->size();
	auto beg = result.begin();
	auto end = result.end();
	for (int n = 0; n < size; n++) {
		if (*beg != n)
			lines->insert(n);
		else if(beg!=end)
			++beg;
	}
	return QueryResult(rep(), result.getFiles(), lines);
}

Query::Query(const std::string& word) :q(new WordQuery(word)) {}

Query operator&(const Query &lhs, const Query &rhs) {
	return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

Query operator|(const Query &lhs, const Query &rhs) {
	return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

Query operator~(const Query &q) {
	return std::shared_ptr<QueryBase>(new NotQuery(q));
}