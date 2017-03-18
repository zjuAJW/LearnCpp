#pragma once

#include <string>
#include <vector>
#include <memory>
#include "StrBlobPtr.h"


class StrBlob {
	friend class StrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	std::string & front();
	const std::string & front() const;
	std::string & back();
	const std::string & back() const;
	void pop_back();
	size_type size() const;
	void push_back(const std::string &s);
	StrBlobPtr begin();
	StrBlobPtr end();

private:
	std::shared_ptr <std::vector<std::string >> data;
	void check(size_type i, const std::string &msg) const;
};

