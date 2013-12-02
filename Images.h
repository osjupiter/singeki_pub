#pragma once
#include"DxLib.h"
#include<map>
#include<string>
#include<vector>
using namespace std;
class Images
{
	vector<string> filelist;

	static Images ins;
	std::map<std::string, int> gs;
public:	
	int blend;
	
	Images(void){}
	~Images(void){}
	void load();
	static void init();
	static Images* getIns();
	static int get(char name[]);
};