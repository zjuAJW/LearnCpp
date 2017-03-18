#pragma once

#include <string>
#include <vector>
#include <memory>

class StrBlob;
class StrBlobPtr {
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob sb, size_type i = 0);
	std::string & deref(); 
	StrBlobPtr & incr();
private:
	size_type curr;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::shared_ptr<std::vector<std::string>> check(const std::string &msg);
};