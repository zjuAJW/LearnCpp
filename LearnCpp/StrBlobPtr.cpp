#include "stdafx.h"
#include "StrBlobPtr.h"
#include "StrBlob.h"

StrBlobPtr::StrBlobPtr(StrBlob sb, size_type i) :wptr(sb.data), curr(i) {}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(const std::string &msg) {
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (curr >= ret->size())
		throw std::out_of_range(msg);
	else
		return ret;
}
std::string & StrBlobPtr::deref() {
	auto ret = check("dereference past end");
	return (*ret)[curr];
}

StrBlobPtr &StrBlobPtr::incr() {
	check("increment past end of StrBlobPtr");
	++curr;
	return *this;
}


