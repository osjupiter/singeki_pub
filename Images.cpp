#include"Images.h"
#include<map>
#include <string>
#include <iostream>
Images Images::ins;

void Images::load(){

//	gs[0]=LoadGraph("pic/test.jpg");
	LoadDivGraph("dat/img/•à•ºw.png", ANI_HOHEI, ANI_HOHEI, 1, WID_HOHEI, HEI_HOHEI, g_hohei);
	LoadDivGraph("dat/img/•à•ºa.png", ANI_HOHEI_ATK, ANI_HOHEI_ATK, 1, WID_HOHEI, HEI_HOHEI, g_hohei_atk);

	LoadDivGraph("dat/img/“GíÔw.png", ANI_TANK, ANI_TANK, 1, WID_TANK, HEI_TANK, g_tank);
	LoadDivGraph("dat/img/“GíÔa.png", ANI_TANK_ATK, ANI_TANK_ATK, 1, WID_TANK ,HEI_TANK, g_tank_atk);

	LoadDivGraph("dat/img/•—‘D•ºw.png", ANI_BALLOON, ANI_BALLOON, 1, WID_BALLOON, HEI_BALLOON, g_balloon);
	LoadDivGraph("dat/img/•—‘D•ºa.png", ANI_BALLOON_ATK, ANI_BALLOON_ATK, 1, WID_BALLOON, HEI_BALLOON, g_balloon_atk);

	LoadDivGraph("dat/img/ƒƒ{•ºw.png", ANI_BIG, ANI_BIG, 1, WID_BIG, HEI_BIG, g_robo);

	LoadDivGraph("dat/img/”š’e.png", ANI_BOMB, ANI_BOMB, 1, WID_BOMB, HEI_BOMB, g_bomb);
	LoadDivGraph("dat/img/bomb0.png", 16, 8, 2, 96, 96, g_exp);

	back[0][0] = LoadGraph("dat/img/R/”wŒi‚P|‚P.png");
	back[0][1] = LoadGraph("dat/img/R/”wŒi‚P|‚Q.png");
	back[0][2] = LoadGraph("dat/img/R/”wŒi‚P|‚R.png");
	back[1][0] = LoadGraph("dat/img/X/”wŒi‚Q|‚P.png");
	back[1][1] = LoadGraph("dat/img/X/”wŒi‚Q|‚Q.png");
	back[1][2] = LoadGraph("dat/img/X/”wŒi‚Q|‚R.png");
	back[2][0] = LoadGraph("dat/img/–éí/”wŒi‚R|‚P.png");
	back[2][1] = LoadGraph("dat/img/–éí/”wŒi‚R|‚Q.png");
	back[2][2] = LoadGraph("dat/img/–éí/”wŒi‚R|‚R.png");
	back[3][0] = LoadGraph("dat/img/ŠC/”wŒi‚S|‚P.png");
	back[3][2] = LoadGraph("dat/img/ŠC/”wŒi‚S|‚Q.png");
	back[4][0] = LoadGraph("dat/img/‘Œ´/”wŒi‚T|‚P.png");
	back[4][1] = LoadGraph("dat/img/‘Œ´/”wŒi‚T|‚Q.png");
	back[4][2] = LoadGraph("dat/img/‘Œ´/”wŒi‚T|‚R.png");
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


	
	for(auto s:filelist){
		gs[s]=LoadGraph(s.c_str());

	}
	
	blend=LoadBlendGraph("pic/blend.jpg");


}

	void Images::init(){ins.load();}
	Images* Images::getIns(){return &ins;}
	int Images::get(char name[]){return ins.gs[string(name)];}