// LearnCpp.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstring>
#include <iterator>
#include "Query.h"
#include "TextQuery.h"
#include "WordQuery.h"
#include "BinaryQuery.h"

using namespace std;
template <typename T>
int compare(const T& v1, const T& v2) {
	if (less<T>()(v1, v2)) return 1;
	if (less<T>()(v2, v1)) return -1;
}
int main()
{
	//ifstream in("E:\\C++\\Learn\\LearnCpp\\LearnCpp\\test.txt");
	//TextQuery tq(in);
	//Query q = Query("fiery") & Query("bird") | Query("wind");
	////Query q = Query("fiery");
	//QueryResult qr = q.eval(tq);
	//printQueryResult(qr);

}