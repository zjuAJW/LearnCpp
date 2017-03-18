#pragma once
#include "Query.h"

class BinaryQuery {
	BinaryQuery(const Query &_lhs, const Query &_rhs, const std::string& _opSym): 
		lhs(_lhs), rhs(_rhs), opSym(_opSym){}

	void rep() {
		cout << " ( " << lhs.rep() << opSym << rhs.rep() << " ) ";
	}

	Query lhs;
	Query rhs;
	std::string opSym;
};

class AndQuery : public BinaryQuery {
	AndQuery(const Query &_lhs, const Query &_rhs) :
		BinaryQuery(_lhs, _rhs, "&") {}
};