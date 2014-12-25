#include "Bgm.h"



void Bgm::load(){
	BGMVol=100;
	bgmlist.push_back("sound/山.mp3");
	bgmlist.push_back("sound/森.mp3");
	bgmlist.push_back("sound/夜戦.mp3");
	bgmlist.push_back("sound/橋.mp3");
	bgmlist.push_back("sound/草原.mp3");
	bgmlist.push_back("sound/洞窟.mp3");
	bgmlist.push_back("sound/都市.mp3");
	bgmlist.push_back("闇の世界.mp3");
	bgmlist.push_back("sound/エンディング.mp3");
	bgmlist.push_back("だみー");


	LoadBGM("sound/タイトル.mp3",false);
	LoadBGM("sound/山.mp3",true);
	_nowBGM="";

}
	void Bgm::setBGMVol(int v){BGMVol=v;}
	int Bgm::getBGMVol(){return BGMVol;}
	void Bgm::initBGM(){
		string n=bgmlist[0];
		Bgm::LoadBGM(n,false);
	}

	void Bgm::changeBGM(int stage_id){
		string s,n;
		s=bgmlist[stage_id];
		Bgm::playBGM(s);
		if(bgmlist.max_size()>=stage_id+1){
			n=bgmlist[stage_id+1];
			Bgm::LoadBGM(n,true);
		}
	}
	void Bgm::playBGM(string name,boolean defaulttrue){
		if(_nowBGM!="")
			StopSoundMem(bgms[_nowBGM]);
		if(name!="")
			if(defaulttrue){
				PlaySoundMem(bgms[name],DX_PLAYTYPE_LOOP);
			}else{
				PlaySoundMem(bgms[name],DX_PLAYTYPE_BACK);
			}
			_nowBGM=name;
	}

	void Bgm::LoadBGM(string s,boolean async){
		if(async){
			SetUseASyncLoadFlag( TRUE ); // 非同期読み込みフラグON
		}
		if(bgms.count(s)==0){
			bgms[s]=LoadSoundMem(s.c_str());
		}
		SetUseASyncLoadFlag( FALSE ); // 非同期読み込みフラグOFF
	}

	void Bgm::assignVol(int MASTERVol){

		int resbgm=255*(MASTERVol/(double)100)*(BGMVol/(double)100);
		for(auto part:bgms){
			ChangeVolumeSoundMem( resbgm ,part.second) ;
		}
		
	}