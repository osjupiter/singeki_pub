#pragma once
#include"DxLib.h"

#include "GV.h"
#include<map>
#include<list>
#include<string>
#include<vector>
using namespace std;
class SoundEffect
{
		int SEVol;
		std::map<std::string, int> ss;
public:

	void load();
	int getSEVol();
	void setSEVol(int);
	void playSE(string name,boolean);
	void playSE(string name);
	void stopSE(string name);
	void setting(){
		ChangeVolumeSoundMem(255*50/100, ss["sound/shot002.wav"]);
		ChangeVolumeSoundMem(255 * 70 / 100, ss["sound/sen_mi_robo_bato01.mp3"]);
	}
	void assignVol(int MASTERVol);
};

