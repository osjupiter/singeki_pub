#include"Images.h"
#include<map>
#include <string>
#include <iostream>
Images Images::ins;

void Images::load(){

//	gs[0]=LoadGraph("pic/test.jpg");
	LoadDivGraph("dat/img/����w.png", ANI_HOHEI, ANI_HOHEI, 1, WID_HOHEI, HEI_HOHEI, g_hohei);
	LoadDivGraph("dat/img/����a.png", ANI_HOHEI_ATK, ANI_HOHEI_ATK, 1, WID_HOHEI, HEI_HOHEI, g_hohei_atk);

	LoadDivGraph("dat/img/�G���w.png", ANI_TANK, ANI_TANK, 1, WID_TANK, HEI_TANK, g_tank);
	LoadDivGraph("dat/img/�G���a.png", ANI_TANK_ATK, ANI_TANK_ATK, 1, WID_TANK ,HEI_TANK, g_tank_atk);

	LoadDivGraph("dat/img/���D��w.png", ANI_BALLOON, ANI_BALLOON, 1, WID_BALLOON, HEI_BALLOON, g_balloon);
	LoadDivGraph("dat/img/���D��a.png", ANI_BALLOON_ATK, ANI_BALLOON_ATK, 1, WID_BALLOON, HEI_BALLOON, g_balloon_atk);

	LoadDivGraph("dat/img/���{��w.png", ANI_BIG, ANI_BIG, 1, WID_BIG, HEI_BIG, g_robo);
	LoadDivGraph("dat/img/���{��a.png", ANI_BIG_ATK, 6, 3, WID_BIG_ATK, HEI_BIG, g_robo_atk);

	LoadDivGraph("dat/img/���e.png", ANI_BOMB, ANI_BOMB, 1, WID_BOMB, HEI_BOMB, g_bomb);
	LoadDivGraph("dat/img/bomb0.png", 16, 8, 2, 96, 96, g_exp);
	LoadDivGraph("dat/img/�Ռ��g.png", ANI_SHOCK, ANI_SHOCK, 1, WID_SHOCK, HEI_SHOCK, g_shock);
	LoadDivGraph("dat/img/�~�T�C��.png", ANI_MISSILE, ANI_MISSILE, 1, WID_MISSILE, HEI_MISSILE, g_missile);

	LoadDivGraph("dat/img/�w��w.png", ANI_COPTER, ANI_COPTER, 1, WID_COPTER, HEI_COPTER, g_copter);


	back[0][0] = LoadGraph("dat/img/�R/�w�i�P�|�P.png");
	back[0][1] = LoadGraph("dat/img/�R/�w�i�P�|�Q.png");
	back[0][2] = LoadGraph("dat/img/�R/�w�i�P�|�R.png");
	back[1][0] = LoadGraph("dat/img/�X/�w�i�Q�|�P.png");
	back[1][1] = LoadGraph("dat/img/�X/�w�i�Q�|�Q.png");
	back[1][2] = LoadGraph("dat/img/�X/�w�i�Q�|�R.png");
	back[2][0] = LoadGraph("dat/img/���/�w�i�R�|�P.png");
	back[2][1] = LoadGraph("dat/img/���/�w�i�R�|�Q.png");
	back[2][2] = LoadGraph("dat/img/���/�w�i�R�|�R.png");
	back[3][0] = LoadGraph("dat/img/�C/�w�i�S�|�P.png");
	back[3][2] = LoadGraph("dat/img/�C/�w�i�S�|�Q.png");
	back[4][0] = LoadGraph("dat/img/����/�w�i�T�|�P.png");
	back[4][1] = LoadGraph("dat/img/����/�w�i�T�|�Q.png");
	back[4][2] = LoadGraph("dat/img/����/�w�i�T�|�R.png");
	castle[0] = LoadGraph("dat/img/sirodummy.png");
	


	sound[0]=LoadSoundMem("sound/kuma.mp3");
	
	filelist.push_back("pic/test.jpg");
	filelist.push_back("pic/black.jpg");
	filelist.push_back("pic/title.png");
	filelist.push_back("pic/game.png");
	filelist.push_back("pic/start.png");
	filelist.push_back("pic/exit.png");
	filelist.push_back("pic/left.png");
	filelist.push_back("pic/right.png");
	filelist.push_back("pic/tou.png");


	
	for(auto s:filelist){
		gs[s]=LoadGraph(s.c_str());

	}
	
	blend=LoadBlendGraph("pic/blend.jpg");


}

	void Images::init(){ins.load();}
	Images* Images::getIns(){return &ins;}
	int Images::get(char name[]){return ins.gs[string(name)];}