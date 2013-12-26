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
	string _nowBGM;
	static Images ins;
	std::map<std::string, int> gs;
	std::map<std::string, int> ss;
public:	
	int blend;
	


	int g_hohei[ANI_HOHEI];//•à•º
	int g_hohei_atk[ANI_HOHEI_ATK];
	int g_tank[8];
	int g_tank_atk[5];
	int g_balloon[8];
	int g_balloon_atk[10];
	int g_bomb[2];
	int g_exp[12];
	int g_robo[7];
	int g_robo_atk[18];
	int g_shock[7];
	int g_copter[6];
	int g_missile[3];
	int g_kamikaze[6];
	int g_kamikaze_atk[20];
	int g_tepodon[3];
	int g_bazooka[8];
	int g_bazooka_atk[12];
	int g_segway[3];
	int g_segway_wait[2];
	int g_segway_run[3];
	int g_gekko[4];
	int g_gekko_up[3];
	int g_gekko_down[4];
	int g_rail[4];
	int g_beam[9];
	int g_beam_c[5];

	int g_castle[9][3];
	int back[8][5];
	Images(void){}
	~Images(void){}
	void load();
	static void init();
	static Images* getIns();
	static int get(const char name[]);
	static int getSound(const char name[]);
	static void playSE(string name,boolean);
	static void playSE(string name);
	static void stopSE(string name);
	static void playBGM(string name);
	static int getMusumeIcon(int);
	static int getSiroIcon(int);
};