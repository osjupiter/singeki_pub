#include "SoundController.h"
#include"DxLib.h"

	SoundController SoundController::ins;
	void SoundController::load(){
		MASTERVol=100;
		se.load();
		bgm.load();
	}

	void SoundController::setMASTERVol(int v){ins.MASTERVol=v;}
	int SoundController::getMASTERVol(){return ins.MASTERVol;}

	void SoundController::assignVol(){
		bgm.assignVol(MASTERVol);
		se.assignVol(MASTERVol);
	}
	SoundController* SoundController::getIns(){return &ins;}
	Bgm* SoundController::getBgm(){return &ins.bgm;}
	SoundEffect* SoundController::getSE(){return &ins.se;}

