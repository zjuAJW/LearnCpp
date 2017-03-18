#include "StrVec.h"
#include <memory>

StrVec::StrVec() :element(nullptr),first_free(nullptr),cap(nullptr){}

//TODO: ¿½±´¹¹Ôìº¯Êý
StrVec::StrVec(const StrVec & rhs) {
	std::pair<std::string *, std::string *> newdata = alloc_n_copy(rhs.begin(), rhs.end());
	element = newdata.first;
	cap = first_free = newdata.second;
}
//TODO:
StrVec &StrVec::operator=(const StrVec & rhs) {
	std::pair<std::string *, std::string *> newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	element = newdata.first;
	cap = first_free = newdata.second;
	return *this;
}

size_t StrVec::size() { return first_free - element; }

size_t StrVec::capacity() { return cap - element; }

std::string * StrVec::begin() const { return element; }

std::string * StrVec::end() const { return first_free; };

void StrVec::push_back(const std::string &s) {
	check_capacity();
	alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *> 
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
	auto new_element = alloc.allocate(e - b);
	auto new_first_free = uninitialized_copy(b,e,new_element);
	return{ new_element,new_first_free };
}

void StrVec::check_capacity() {
	if (first_free == cap)
		reallocate();
}

void StrVec::free() {
	while (first_free != element) {
		alloc.destroy(--first_free);
	}
	alloc.deallocate(element, cap - element);
}

void StrVec::reallocate() {
	auto new_capacity = size() ? size() * 2 : 1;
	auto newdata = alloc.allocate(new_capacity);
	auto elem = element;
	auto dest = newdata;
	for (int i = 0; i < size(); i++) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	element = newdata;
	cap = element + new_capacity;
	first_free = dest;
}
StrVec::~StrVec() { free(); }