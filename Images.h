#pragma once
#include"DxLib.h"

#include "GV.h"


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

//	int gs[100];
	int sound[100];
	int trans[50];
	int yaji[4][4];
	int font,alphfont;

	int g_hohei[ANI_HOHEI];//•à•º
	int back[4][3];


	
	

	Images(void){}
	~Images(void){}
	void load();
	static void init(){ins.load();}
	static Images* getIns(){return &ins;}
	static int get(char name[]){return ins.gs[name];}
};