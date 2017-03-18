#include "stdafx.h"
#include "StrBlob.h"


void StrBlob::check(size_type i, const std::string &msg) const {
	if (data->size() <= i)
		throw std::out_of_range(msg);
}

std::string & StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}

const std::string & StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}

void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

std::string & StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string & StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}

StrBlob::StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string >> (il)) {}
StrBlob::StrBlob() :data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::size_type StrBlob::size() const { return data->size(); }
void StrBlob::push_back(const std::string &s) { data->push_back(s); }
StrBlobPtr StrBlob::begin() { return StrBlobPtr{ *this,0 }; }
StrBlobPtr StrBlob::end() { return StrBlobPtr{ *this, data->size() }; }