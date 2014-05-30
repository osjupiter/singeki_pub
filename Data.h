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
	void Run();
	static Data* getIns();
	
};