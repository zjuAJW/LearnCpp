// LearnCpp.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstring>
#include <iterator>
#include <Query>
#include "TextQuery.h"

using namespace std;

int main()
{
	ifstream in("E:\\C++\\Learn\\LearnCpp\\LearnCpp\\test.txt");
	TextQuery tq(in);
	//tq.printFile();
	Query q = Query("Alice") | Query("hari") &Query("more");
	printQueryResult(q.eval(tq));
}