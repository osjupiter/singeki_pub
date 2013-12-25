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

	LoadDivGraph("dat/img/ÉçÉféqw.png", ANI_KAMIKAZE, ANI_KAMIKAZE, 1, WID_KAMIKAZE, HEI_KAMIKAZE, g_kamikaze);
	LoadDivGraph("dat/img/ÉçÉféqa.png", ANI_KAMIKAZE_ATK, 5, 5, WID_KAMIKAZE_ATK, HEI_KAMIKAZE_ATK, g_kamikaze_atk);
	
	LoadDivGraph("dat/img/ÉoÉYÅ[ÉJï∫w.png", ANI_BAZOOKA, ANI_BAZOOKA, 1, WID_BAZOOKA, HEI_BAZOOKA, g_bazooka);
	LoadDivGraph("dat/img/ÉoÉYÅ[ÉJï∫a.png", ANI_BAZOOKA_ATK, 6, 2, WID_BAZOOKA_ATK, HEI_BAZOOKA_ATK, g_bazooka_atk);

	LoadDivGraph("dat/img/îöíe.png", ANI_BOMB, ANI_BOMB, 1, WID_BOMB, HEI_BOMB, g_bomb);
	LoadDivGraph("dat/img/îöî≠E.png", ANI_EXP, 6, 2, WID_EXP, HEI_EXP, g_exp);
	LoadDivGraph("dat/img/è’åÇîg.png", ANI_SHOCK, ANI_SHOCK, 1, WID_SHOCK, HEI_SHOCK, g_shock);
	LoadDivGraph("dat/img/É~ÉTÉCÉã.png", ANI_MISSILE, ANI_MISSILE, 1, WID_MISSILE, HEI_MISSILE, g_missile);

	LoadDivGraph("dat/img/ÉwÉäw.png", ANI_COPTER, ANI_COPTER, 1, WID_COPTER, HEI_COPTER, g_copter);


	back[0][0] = LoadGraph("dat/img/éR/îwåiÇPÅ|ÇP.png");
	back[0][1] = LoadGraph("dat/img/éR/îwåiÇPÅ|ÇT.png");
	back[0][2] = LoadGraph("dat/img/éR/îwåiÇPÅ|ÇS.png");
	back[0][3] = LoadGraph("dat/img/éR/îwåiÇPÅ|ÇQ.png");
	back[0][4] = LoadGraph("dat/img/éR/îwåiÇPÅ|ÇR.png");

	back[1][0] = 0;
	back[1][1] = 0;
	back[1][2] = LoadGraph("dat/img/êX/îwåiÇQÅ|ÇP.png");
	back[1][3] = LoadGraph("dat/img/êX/îwåiÇQÅ|ÇQ.png");
	back[1][4] = LoadGraph("dat/img/êX/îwåiÇQÅ|ÇR.png");

	back[2][0] = 0;
	back[2][1] = 0;
	back[2][2] = LoadGraph("dat/img/ñÈêÌ/îwåiÇRÅ|ÇP.png");
	back[2][3] = LoadGraph("dat/img/ñÈêÌ/îwåiÇRÅ|ÇQ.png");
	back[2][4] = LoadGraph("dat/img/ñÈêÌ/îwåiÇRÅ|ÇR.png");

	back[3][0] = LoadGraph("dat/img/äC/îwåiÇSÅ|ÇP.png");
	back[3][1] = LoadGraph("dat/img/äC/îwåiÇSÅ|ÇR.png");
	back[3][2] = 0;
	back[3][3] = 0;
	back[3][4] = LoadGraph("dat/img/äC/îwåiÇSÅ|ÇQ.png");

	back[4][0] = LoadGraph("dat/img/ëêå¥/îwåiÇTÅ|ÇP.png");
	back[4][1] = LoadGraph("dat/img/ëêå¥/îwåiÇTÅ|ÇS.png");
	back[4][2] = 0;
	back[4][3] = LoadGraph("dat/img/ëêå¥/îwåiÇTÅ|ÇQ.png");
	back[4][4] = LoadGraph("dat/img/ëêå¥/îwåiÇTÅ|ÇR.png");

	back[5][0] = LoadGraph("dat/img/ì¥åA/îwåiÇUÅ|ÇP.png");
	back[5][1] = LoadGraph("dat/img/ì¥åA/îwåiÇUÅ|ÇQ.png");
	back[5][2] = 0;
	back[5][3] = LoadGraph("dat/img/ì¥åA/îwåiÇUÅ|ÇR.png");
	back[5][4] = LoadGraph("dat/img/ì¥åA/îwåiÇUÅ|ÇS.png");

	back[6][0] = LoadGraph("dat/img/ìsés/îwåiÇVÅ|ÇP.png");
	back[6][1] = LoadGraph("dat/img/ìsés/îwåiÇVÅ|ÇQ.png");
	back[6][2] = 0;
	back[6][3] = LoadGraph("dat/img/ìsés/îwåiÇVÅ|ÇS.png");
	back[6][4] = LoadGraph("dat/img/ìsés/îwåiÇVÅ|ÇT.png");
	
	back[7][0] = LoadGraph("dat/img/à≈ÇÃê¢äE/îwåiÇWÅ|ÇP.png");
	back[7][1] = 0;
	back[7][2] = 0;
	back[7][3] = LoadGraph("dat/img/à≈ÇÃê¢äE/îwåiÇWÅ|ÇQ.png");
	back[7][4] = LoadGraph("dat/img/à≈ÇÃê¢äE/îwåiÇWÅ|ÇR.png");

	castle[0] = LoadGraph("dat/img/sirodummy.png");
	


	//sound[0]=LoadSoundMem("sound/kuma.mp3");
	
	filelist.push_back("pic/test.jpg");
	filelist.push_back("pic/black.jpg");
	filelist.push_back("pic/title.png");
	filelist.push_back("pic/game.png");
	filelist.push_back("pic/start.png");
	filelist.push_back("pic/exit.png");
	filelist.push_back("pic/left.png");
	filelist.push_back("pic/right.png");
	filelist.push_back("pic/tou.png");

	filelist.push_back("pic/ba.png");
	filelist.push_back("pic/ha.png");
	filelist.push_back("pic/ka.png");
	filelist.push_back("pic/na.png");
	filelist.push_back("pic/ra.png");

	soundlist.push_back("sound/kuma.mp3");
	soundlist.push_back("sound/se_maoudamashii_system49.wav");
	soundlist.push_back("sound/button03a.mp3");
	soundlist.push_back("sound/taihou03.mp3");
	soundlist.push_back("sound/misairu.mp3");
	soundlist.push_back("sound/shot002.wav");
	soundlist.push_back("sound/gun04.mp3");

	
	for(auto s:filelist){
		gs[s]=LoadGraph(s.c_str());

	}	

	for(auto s:soundlist){
		ss[s]=LoadSoundMem(s.c_str());

	}
	
	blend=LoadBlendGraph("pic/blend.jpg");


}

	void Images::init(){ins.load();}
	Images* Images::getIns(){return &ins;}

	int Images::get(const char name[]){return ins.gs[string(name)];}
	int Images::getSound(const char name[]){return ins.ss[string(name)];}

	
	void Images::playSE(string name,boolean ischeck){
		if(ischeck){
			if(CheckSoundMem(ins.ss[name])==1)
				return;
		}
		PlaySoundMem(ins.ss[name] ,DX_PLAYTYPE_BACK);
	}
	void Images::playSE(string name){Images::playSE(name,false);}

	void Images::stopSE(string name){StopSoundMem(ins.ss[name] );}

	int Images::getMusumeIcon(int id){
		string s;
		switch (id){
			case 0:
				s="pic/null.png";
				break;
			case 1:
				s="pic/na.png";
				break;
			case 2:
				s="pic/ha.png";
				break;
			case 3:
				s="pic/ra.png";
				break;
			case 4:
				s="pic/ka.png";
				break;
			case 5:
				s="pic/ba.png";
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
		}
		return ins.get(s.c_str());
	}
