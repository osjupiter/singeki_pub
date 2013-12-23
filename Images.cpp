#include"Images.h"
#include<map>
#include <string>
#include <iostream>
Images Images::ins;

void Images::load(){

//	gs[0]=LoadGraph("pic/test.jpg");
	LoadDivGraph("dat/img/ï‡ï∫w.png", ANI_HOHEI, ANI_HOHEI, 1, WID_HOHEI, HEI_HOHEI, g_hohei);
	LoadDivGraph("dat/img/ï‡ï∫a.png", ANI_HOHEI_ATK, ANI_HOHEI_ATK, 1, WID_HOHEI, HEI_HOHEI, g_hohei_atk);

	LoadDivGraph("dat/img/ìGêÌé‘w.png", ANI_TANK, ANI_TANK, 1, WID_TANK, HEI_TANK, g_tank);
	LoadDivGraph("dat/img/ìGêÌé‘a.png", ANI_TANK_ATK, ANI_TANK_ATK, 1, WID_TANK ,HEI_TANK, g_tank_atk);

	LoadDivGraph("dat/img/ïóëDï∫w.png", ANI_BALLOON, ANI_BALLOON, 1, WID_BALLOON, HEI_BALLOON, g_balloon);
	LoadDivGraph("dat/img/ïóëDï∫a.png", ANI_BALLOON_ATK, ANI_BALLOON_ATK, 1, WID_BALLOON, HEI_BALLOON, g_balloon_atk);

	LoadDivGraph("dat/img/ÉçÉ{ï∫w.png", ANI_BIG, ANI_BIG, 1, WID_BIG, HEI_BIG, g_robo);
	LoadDivGraph("dat/img/ÉçÉ{ï∫a.png", ANI_BIG_ATK, 6, 3, WID_BIG_ATK, HEI_BIG, g_robo_atk);

	LoadDivGraph("dat/img/îöíe.png", ANI_BOMB, ANI_BOMB, 1, WID_BOMB, HEI_BOMB, g_bomb);
	LoadDivGraph("dat/img/bomb0.png", 16, 8, 2, 96, 96, g_exp);
	LoadDivGraph("dat/img/è’åÇîg.png", ANI_SHOCK, ANI_SHOCK, 1, WID_SHOCK, HEI_SHOCK, g_shock);
	LoadDivGraph("dat/img/É~ÉTÉCÉã.png", ANI_MISSILE, ANI_MISSILE, 1, WID_MISSILE, HEI_MISSILE, g_missile);

	LoadDivGraph("dat/img/ÉwÉäw.png", ANI_COPTER, ANI_COPTER, 1, WID_COPTER, HEI_COPTER, g_copter);


	back[0][0] = LoadGraph("dat/img/éR/îwåiÇPÅ|ÇP.png");
	back[0][1] = LoadGraph("dat/img/éR/îwåiÇPÅ|ÇQ.png");
	back[0][2] = LoadGraph("dat/img/éR/îwåiÇPÅ|ÇR.png");
	back[1][0] = LoadGraph("dat/img/êX/îwåiÇQÅ|ÇP.png");
	back[1][1] = LoadGraph("dat/img/êX/îwåiÇQÅ|ÇQ.png");
	back[1][2] = LoadGraph("dat/img/êX/îwåiÇQÅ|ÇR.png");
	back[2][0] = LoadGraph("dat/img/ñÈêÌ/îwåiÇRÅ|ÇP.png");
	back[2][1] = LoadGraph("dat/img/ñÈêÌ/îwåiÇRÅ|ÇQ.png");
	back[2][2] = LoadGraph("dat/img/ñÈêÌ/îwåiÇRÅ|ÇR.png");
	back[3][0] = LoadGraph("dat/img/äC/îwåiÇSÅ|ÇP.png");
	back[3][2] = LoadGraph("dat/img/äC/îwåiÇSÅ|ÇQ.png");
	back[4][0] = LoadGraph("dat/img/ëêå¥/îwåiÇTÅ|ÇP.png");
	back[4][1] = LoadGraph("dat/img/ëêå¥/îwåiÇTÅ|ÇQ.png");
	back[4][2] = LoadGraph("dat/img/ëêå¥/îwåiÇTÅ|ÇR.png");
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