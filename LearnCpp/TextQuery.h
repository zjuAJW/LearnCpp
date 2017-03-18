#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <memory>
class QueryResult;

class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream & in);
	QueryResult query(const std::string& word) const;
	void printFile();
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wordcount;
};

void printQueryResult(const QueryResult &);

class QueryResult {
	friend void printQueryResult(const QueryResult &);
	using line_no = TextQuery::line_no;
public:
	QueryResult(std::string _word,
		std::shared_ptr<std::vector<std::string>> _file,
		std::shared_ptr<std::set<line_no>> _lines) :
		word(_word), file(_file), lines(_lines) {}
private:
	std::string word;
	std::shared_ptr<std::vector<std::string>> file;
	std::shared_ptr<std::set<line_no>> lines;
};