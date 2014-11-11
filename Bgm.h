#pragma once
#include"DxLib.h"

#include "GV.h"
#include<map>
#include<list>
#include<string>
#include<vector>
using namespace std;
class Bgm
{
		string _nowBGM;
		std::map<std::string, int> bgms;
		vector<string> bgmlist;
		int BGMVol;

public:


	int getBGMVol();
	void setBGMVol(int);

	void load();
	void LoadBGM(string,boolean);
	void initBGM();
	void playBGM(string name,boolean defaulttrue=true);
	void changeBGM(int stage_id);
	void assignVol(int MASTERVol);

};

