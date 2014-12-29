#pragma once
#include  "DxLib.h"
#include <vector>
#include <string>

#include <map>

class Data {
	static Data ins;
	std::map<std::string, int> dataTable;
public:
	std::map<std::string, std::string> paramTable;
	void Read();
	static Data* getIns();
	void Write();
	int get(std::string);
	void set(std::string,int);
	
};