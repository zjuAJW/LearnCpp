#pragma once
#include "Query.h"
#include "BinaryQuery.h"

class AndQuery : public BinaryQuery{






	Query lhs;
	Query rhs;
};