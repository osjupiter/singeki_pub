#pragma once
#include  "DxLib.h"

#include<map>
#include<string>
#include<vector>
using namespace std;

class CsvReader{
public:;
	static vector<string> split(const string &str, const string &delim);
	static vector<vector<string>> parseTable(string name, const string &delim);
	static void saveCsv(string filename,map<string,string>);
	static boolean existCsv(string filename);

};