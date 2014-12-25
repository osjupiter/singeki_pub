#include "Bgm.h"



void Bgm::load(){
	BGMVol=100;
	bgmlist.push_back("sound/�R.mp3");
	bgmlist.push_back("sound/�X.mp3");
	bgmlist.push_back("sound/���.mp3");
	bgmlist.push_back("sound/��.mp3");
	bgmlist.push_back("sound/����.mp3");
	bgmlist.push_back("sound/���A.mp3");
	bgmlist.push_back("sound/�s�s.mp3");
	bgmlist.push_back("�ł̐��E.mp3");
	bgmlist.push_back("sound/�G���f�B���O.mp3");
	bgmlist.push_back("���݁[");


	LoadBGM("sound/�^�C�g��.mp3",false);
	LoadBGM("sound/�R.mp3",true);
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
			SetUseASyncLoadFlag( TRUE ); // �񓯊��ǂݍ��݃t���OON
		}
		if(bgms.count(s)==0){
			bgms[s]=LoadSoundMem(s.c_str());
		}
		SetUseASyncLoadFlag( FALSE ); // �񓯊��ǂݍ��݃t���OOFF
	}

	void Bgm::assignVol(int MASTERVol){

		int resbgm=255*(MASTERVol/(double)100)*(BGMVol/(double)100);
		for(auto part:bgms){
			ChangeVolumeSoundMem( resbgm ,part.second) ;
		}
		
	}