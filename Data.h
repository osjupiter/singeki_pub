#pragma once
#include  "DxLib.h"
#include <vector>
#include <string>

#include <map>

class Data {
	static Data ins;
	std::map<std::string, std::string> dataTable;
public:
	void Run();
	static Data* getIns();
	
};