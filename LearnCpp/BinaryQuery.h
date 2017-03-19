#pragma once
#include "Query.h"
#include <iostream>

class BinaryQuery : public QueryBase{
protected:
	BinaryQuery(const Query &_lhs, const Query &_rhs, const std::string& _opSym): 
		lhs(_lhs), rhs(_rhs), opSym(_opSym){}

	std::string rep() {
		return " ( " + lhs.rep() + " " + opSym + " " + rhs.rep() + " ) ";
	}

	Query lhs;
	Query rhs;
	std::string opSym;
};


class AndQuery : public BinaryQuery {
	friend Query operator&(const Query &lhs, const Query &rhs);
	AndQuery(const Query &_lhs, const Query &_rhs) :
		BinaryQuery(_lhs, _rhs, "&") {std::cout << "AndQuery Construct()" << std::endl;}
	QueryResult eval(const TextQuery & text);
};

class OrQuery :public BinaryQuery {
	friend Query operator|(const Query &lhs, const Query &rhs);
	OrQuery(const Query &_lhs, const Query &_rhs) :
		BinaryQuery(_lhs, _rhs, "|") {
		std::cout << "OrQuery Construct()" << std::endl;
	}
	QueryResult eval(const TextQuery & text);
};

