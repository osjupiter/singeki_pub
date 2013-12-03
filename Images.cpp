#include"Images.h"
#include<map>
#include <string>
#include <iostream>
Images Images::ins;

void Images::load(){

//	gs[0]=LoadGraph("pic/test.jpg");
	LoadDivGraph("dat/img/����w.png", ANI_HOHEI, ANI_HOHEI, 1, WID_HOHEI, HEI_HOHEI, g_hohei);
	back[0][0] = LoadGraph("dat/img/�w�i�P�|�P.png");
	back[0][1] = LoadGraph("dat/img/�w�i�P�|�Q.png");
	back[0][2] = LoadGraph("dat/img/�w�i�P�|�R.png");
	back[1][0] = LoadGraph("dat/img/�X/�w�i�Q�|�P.png");
	back[1][1] = LoadGraph("dat/img/�X/�w�i�Q�|�Q.png");
	back[1][2] = LoadGraph("dat/img/�X/�w�i�Q�|�R.png");
	back[2][0] = LoadGraph("dat/img/���/�w�i�R�|�P.png");
	back[2][1] = LoadGraph("dat/img/���/�w�i�R�|�Q.png");
	back[2][2] = LoadGraph("dat/img/���/�w�i�R�|�R.png");
	back[3][0] = LoadGraph("dat/img/�C/�w�i�S�|�P.png");
	back[3][2] = LoadGraph("dat/img/�C/�w�i�S�|�Q.png");
	sound[0]=LoadSoundMem("sound/kuma.mp3");


	filelist.push_back("pic/test.jpg");
	filelist.push_back("pic/black.jpg");
	filelist.push_back("pic/title.png");
	filelist.push_back("pic/game.png");
	filelist.push_back("pic/start.png");
	filelist.push_back("pic/exit.png");


	
	for(auto s:filelist){
		gs[s]=LoadGraph(s.c_str());

	}
	
	blend=LoadBlendGraph("pic/blend.jpg");


}

	void Images::init(){ins.load();}
	Images* Images::getIns(){return &ins;}
	int Images::get(char name[]){return ins.gs[string(name)];}