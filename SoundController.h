#pragma once
#include "SoundEffect.h"
#include"Bgm.h"
class SoundController
{
	static SoundController ins;

	Bgm bgm;
	SoundEffect se;
	int MASTERVol;
public:
	static SoundController* getIns();
	static Bgm* getBgm();
	static SoundEffect* getSE();	

	void setMASTERVol(int);
	int getMASTERVol();
	void assignVol();

	void load();
	

};

