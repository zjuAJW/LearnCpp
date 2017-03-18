#pragma once

#include <string>
class StrVec {
public:
	StrVec();
	StrVec(const StrVec &);
	StrVec& operator=(const StrVec &);
	~StrVec();

	void push_back(const std::string &);
	size_t size();
	size_t capacity();
	std::string * begin() const;
	std::string * end() const;
private:
	std::allocator<std::string> alloc;
	std::string * element, *first_free, *cap;
	void free();
	void reallocate();
	std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,const std::string *);
	void check_capacity();
};
