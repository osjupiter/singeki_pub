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
	int blend;
	

	int sound[100];


	int g_hohei[ANI_HOHEI];//����
	int back[4][3];
	Images(void){}
	~Images(void){}
	void load();
	static void init();
	static Images* getIns();
	static int get(char name[]);
};