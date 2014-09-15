#pragma once
#include"DxLib.h"

#include "GV.h"


#include<map>
#include<list>
#include<string>
#include<vector>
using namespace std;

class Images
{

	string _nowBGM;
	static Images ins;
	std::map<std::string, int> gs;
	std::map<std::string, int> ss;
	std::map<std::string, int> bgms;
	vector<string> bgmlist;
	int SEVol,BGMVol,MASTERVol;
public:	
	int blend;
	


	int g_hohei[ANI_HOHEI];//•à•º
	int g_hohei_atk[ANI_HOHEI_ATK];
	int g_tank[3][8];
	int g_tank_atk[3][5];
	int g_tank_dei[3][6];
	int g_balloon[8];
	int g_balloon_atk[10];
	int g_bomb[2];
	int g_exp[12];
	int g_robo[7];
	int g_robo_atk[18];
	int g_shock[7];
	int g_copter[6];
	int g_copter_die[9];
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
	int g_mekanemu[3];
	int g_castle[9][3];
	int g_mekahaikyo;
	int g_bigexp[15];
	int g_thunder_mekanemu[3];
	int g_nomalExp[7];
	int g_gunshot[3];
	int g_cannonshot[4];
	int g_e_yamidrop[3][8];
	int g_e_wisp[3][7];

	int houdai_yama;

	int font;
	
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
	
	static int getMusumeIcon(int,boolean=false);
	static int getSiroIcon(int,boolean=false);
	static int getParamTypeIcon(ParamType,boolean=false);
	static void LoadBGM(string,boolean);
	static void initBGM();
	static void playBGM(string name,boolean defaulttrue=true);
	static void setting(){
	

	ChangeVolumeSoundMem(255*50/100, ins.ss["sound/shot002.wav"]);
	ChangeVolumeSoundMem(255 * 70 / 100, ins.ss["sound/sen_mi_robo_bato01.mp3"]);
	}
	static void setSEVol(int);
	static void setBGMVol(int);
	static void setMASTERVol(int);
	void assignVol();
	
	static int getSEVol();
	static int getBGMVol();
	static int getMASTERVol();

	static void changeBGM(int stage_id);


};