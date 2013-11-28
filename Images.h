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
	
	
	Images(void){}
	~Images(void){}
	void load();
	static void init(){ins.load();}
	static Images* getIns(){return &ins;}
	static int get(char name[]){return ins.gs[name];}
};