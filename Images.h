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
	vector<string> soundlist;

	static Images ins;
	std::map<std::string, int> gs;
	std::map<std::string, int> ss;
public:	
	int blend;
	


	int g_hohei[ANI_HOHEI];//����
	int g_hohei_atk[ANI_HOHEI_ATK];
	int g_tank[8];
	int g_tank_atk[5];
	int g_balloon[8];
	int g_balloon_atk[10];
	int g_bomb[2];
	int g_exp[16];
	int g_robo[7];
	int g_robo_atk[18];
	int g_shock[7];
	int g_copter[6];
	int g_missile[3];
	int castle[8];
	int back[5][5];
	Images(void){}
	~Images(void){}
	void load();
	static void init();
	static Images* getIns();
	static int get(char name[]);
	static int getSound(char name[]);
};