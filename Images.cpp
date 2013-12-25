#include"Images.h"
#include<map>
#include <string>
#include <iostream>
Images Images::ins;

void Images::load(){
	_nowBGM="";

//	gs[0]=LoadGraph("pic/test.jpg");
	LoadDivGraph("dat/img/����w.png", ANI_HOHEI, ANI_HOHEI, 1, WID_HOHEI, HEI_HOHEI, g_hohei);
	LoadDivGraph("dat/img/����a.png", ANI_HOHEI_ATK, ANI_HOHEI_ATK, 1, WID_HOHEI, HEI_HOHEI, g_hohei_atk);

	LoadDivGraph("dat/img/�G���w.png", ANI_TANK, ANI_TANK, 1, WID_TANK, HEI_TANK, g_tank);
	LoadDivGraph("dat/img/�G���a.png", ANI_TANK_ATK, ANI_TANK_ATK, 1, WID_TANK ,HEI_TANK, g_tank_atk);

	LoadDivGraph("dat/img/���D��w.png", ANI_BALLOON, ANI_BALLOON, 1, WID_BALLOON, HEI_BALLOON, g_balloon);
	LoadDivGraph("dat/img/���D��a.png", ANI_BALLOON_ATK, ANI_BALLOON_ATK, 1, WID_BALLOON, HEI_BALLOON, g_balloon_atk);

	LoadDivGraph("dat/img/���{��w.png", ANI_BIG, ANI_BIG, 1, WID_BIG, HEI_BIG, g_robo);
	LoadDivGraph("dat/img/���{��a.png", ANI_BIG_ATK, 6, 3, WID_BIG_ATK, HEI_BIG, g_robo_atk);

	LoadDivGraph("dat/img/���f�qw.png", ANI_KAMIKAZE, ANI_KAMIKAZE, 1, WID_KAMIKAZE, HEI_KAMIKAZE, g_kamikaze);
	LoadDivGraph("dat/img/���f�qa.png", ANI_KAMIKAZE_ATK, 5, 5, WID_KAMIKAZE_ATK, HEI_KAMIKAZE_ATK, g_kamikaze_atk);
	
	LoadDivGraph("dat/img/�o�Y�[�J��w.png", ANI_BAZOOKA, ANI_BAZOOKA, 1, WID_BAZOOKA, HEI_BAZOOKA, g_bazooka);
	LoadDivGraph("dat/img/�o�Y�[�J��a.png", ANI_BAZOOKA_ATK, 6, 2, WID_BAZOOKA_ATK, HEI_BAZOOKA_ATK, g_bazooka_atk);

	LoadDivGraph("dat/img/���e.png", ANI_BOMB, ANI_BOMB, 1, WID_BOMB, HEI_BOMB, g_bomb);
	LoadDivGraph("dat/img/����E.png", ANI_EXP, 6, 2, WID_EXP, HEI_EXP, g_exp);
	LoadDivGraph("dat/img/�Ռ��g.png", ANI_SHOCK, ANI_SHOCK, 1, WID_SHOCK, HEI_SHOCK, g_shock);
	LoadDivGraph("dat/img/�~�T�C��.png", ANI_MISSILE, ANI_MISSILE, 1, WID_MISSILE, HEI_MISSILE, g_missile);

	LoadDivGraph("dat/img/�w��w.png", ANI_COPTER, ANI_COPTER, 1, WID_COPTER, HEI_COPTER, g_copter);


	back[0][0] = LoadGraph("dat/img/�R/�w�i�P�|�P.png");
	back[0][1] = LoadGraph("dat/img/�R/�w�i�P�|�T.png");
	back[0][2] = LoadGraph("dat/img/�R/�w�i�P�|�S.png");
	back[0][3] = LoadGraph("dat/img/�R/�w�i�P�|�Q.png");
	back[0][4] = LoadGraph("dat/img/�R/�w�i�P�|�R.png");

	back[1][0] = 0;
	back[1][1] = 0;
	back[1][2] = LoadGraph("dat/img/�X/�w�i�Q�|�P.png");
	back[1][3] = LoadGraph("dat/img/�X/�w�i�Q�|�Q.png");
	back[1][4] = LoadGraph("dat/img/�X/�w�i�Q�|�R.png");

	back[2][0] = 0;
	back[2][1] = 0;
	back[2][2] = LoadGraph("dat/img/���/�w�i�R�|�P.png");
	back[2][3] = LoadGraph("dat/img/���/�w�i�R�|�Q.png");
	back[2][4] = LoadGraph("dat/img/���/�w�i�R�|�R.png");

	back[3][0] = LoadGraph("dat/img/�C/�w�i�S�|�P.png");
	back[3][1] = LoadGraph("dat/img/�C/�w�i�S�|�R.png");
	back[3][2] = 0;
	back[3][3] = 0;
	back[3][4] = LoadGraph("dat/img/�C/�w�i�S�|�Q.png");

	back[4][0] = LoadGraph("dat/img/����/�w�i�T�|�P.png");
	back[4][1] = LoadGraph("dat/img/����/�w�i�T�|�S.png");
	back[4][2] = 0;
	back[4][3] = LoadGraph("dat/img/����/�w�i�T�|�Q.png");
	back[4][4] = LoadGraph("dat/img/����/�w�i�T�|�R.png");

	back[5][0] = LoadGraph("dat/img/���A/�w�i�U�|�P.png");
	back[5][1] = LoadGraph("dat/img/���A/�w�i�U�|�Q.png");
	back[5][2] = 0;
	back[5][3] = LoadGraph("dat/img/���A/�w�i�U�|�R.png");
	back[5][4] = LoadGraph("dat/img/���A/�w�i�U�|�S.png");

	back[6][0] = LoadGraph("dat/img/�s�s/�w�i�V�|�P.png");
	back[6][1] = LoadGraph("dat/img/�s�s/�w�i�V�|�Q.png");
	back[6][2] = LoadGraph("dat/img/�s�s/�w�i�V�|�R.png");
	back[6][3] = LoadGraph("dat/img/�s�s/�w�i�V�|�S.png");
	back[6][4] = LoadGraph("dat/img/�s�s/�w�i�V�|�T.png");
	
	back[7][0] = LoadGraph("dat/img/�ł̐��E/�w�i�W�|�P.png");
	back[7][1] = 0;
	back[7][2] = 0;
	back[7][3] = LoadGraph("dat/img/�ł̐��E/�w�i�W�|�Q.png");
	back[7][4] = LoadGraph("dat/img/�ł̐��E/�w�i�W�|�R.png");

	castle[0][0] = LoadGraph("dat/img/sirodummy.png");
	castle[0][1] = LoadGraph("dat/img/sirodummy.png");
	castle[0][2] = LoadGraph("dat/img/sirodummy.png");
	
	castle[1][0] = LoadGraph("dat/img/�R/�R��.png");
	castle[1][1] = LoadGraph("dat/img/�R/�R�锼��.png");
	castle[1][2] = LoadGraph("dat/img/�R/���J�R��.png");
	
	castle[2][0] = LoadGraph("dat/img/�X/�X��.png");
	castle[2][1] = LoadGraph("dat/img/�X/�X�锼��.png");
	castle[2][2] = LoadGraph("dat/img/�X/���J�X��.png");
	
	castle[3][0] = LoadGraph("dat/img/���/����.png");
	castle[3][1] = LoadGraph("dat/img/���/���锼��.png");
	castle[3][2] = LoadGraph("dat/img/���/���J����.png");
	
	castle[4][0] = LoadGraph("dat/img/�C/�C��.png");
	castle[4][1] = LoadGraph("dat/img/�C/�C�锼��.png");
	castle[4][2] = LoadGraph("dat/img/�C/���J�C��.png");
	
	castle[5][0] = LoadGraph("dat/img/����/������.png");
	castle[5][1] = LoadGraph("dat/img/����/�����锼��.png");
	castle[5][2] = LoadGraph("dat/img/����/���J������.png");
	
	castle[6][0] = LoadGraph("dat/img/���A/���A��.png");
	castle[6][1] = LoadGraph("dat/img/���A/���A�锼��.png");
	castle[6][2] = LoadGraph("dat/img/���A/���J���A��.png");
	
	castle[7][0] = LoadGraph("dat/img/�s�s/�s�s��.png");
	castle[7][1] = LoadGraph("dat/img/�s�s/�s�s�锼��.png");
	castle[7][2] = LoadGraph("dat/img/�s�s/���J�s�s��.png");
	
	castle[8][0] = LoadGraph("dat/img/sirodummy.png");
	castle[8][1] = LoadGraph("dat/img/sirodummy.png");
	castle[8][2] = LoadGraph("dat/img/sirodummy.png");


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


	soundlist.push_back("sound/��.mp3");
	soundlist.push_back("sound/�R.mp3");
	soundlist.push_back("sound/�X.mp3");
	soundlist.push_back("sound/����.mp3");
	soundlist.push_back("sound/�s�s.mp3");
	soundlist.push_back("sound/���A.mp3");
	soundlist.push_back("sound/���.mp3");

	
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

	void Images::playBGM(string name){
		printfDx(name.c_str());
		if(ins._nowBGM!="")
			StopSoundMem(getSound(ins._nowBGM.c_str()));
		if(name!="")
			PlaySoundMem(getSound(name.c_str()),DX_PLAYTYPE_LOOP);
		ins._nowBGM=name;
	}
