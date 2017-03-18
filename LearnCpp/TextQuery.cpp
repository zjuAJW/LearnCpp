#include "TextQuery.h"
#include <sstream>
#include <iostream>

using namespace std;

TextQuery::TextQuery(ifstream & in) : file(new vector<string>){
	string text;
	while (getline(in,text)) {
		file->push_back(text);
		line_no n = file->size();
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wordcount[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

void TextQuery::printFile() {
	for (auto line : *file) {
		cout << line << endl;
	}
}

QueryResult TextQuery::query(const std::string& word) const{
	auto lines = wordcount.find(word);
	return QueryResult(word, file, lines->second);
}

void printQueryResult(const QueryResult & result) {
	if (!result.lines) {
		cout << "No such words" << endl;
	}
	else {
		cout << result.word << " occurs " << result.lines->size() << " times" << endl;
		for (auto no : *result.lines) {
			cout << "\t(line " << no << ") " << (*(result.file))[no-1] << endl;
		}
	}
}