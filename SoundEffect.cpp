#include "SoundEffect.h"


	void SoundEffect::load(){
		vector<string> soundlist;
		SetUseASyncLoadFlag( FALSE ); // �񓯊��ǂݍ��݃t���OOFF
		SEVol=100;
		soundlist.push_back("sound/button03a.mp3");
		soundlist.push_back("sound/se_maoudamashii_system49.wav");
	
		for(auto s:soundlist){
			ss[s]=LoadSoundMem(s.c_str());

		}
	
		SetUseASyncLoadFlag( TRUE ); // �񓯊��ǂݍ��݃t���OON

		soundlist.push_back("sound/kuma.mp3");
	
		soundlist.push_back("sound/taihou03.mp3");
		soundlist.push_back("sound/misairu.mp3");
		soundlist.push_back("sound/shot002.wav");
		soundlist.push_back("sound/gun04.mp3");
		soundlist.push_back("sound/sen_ge_taihou08.mp3");

		soundlist.push_back("sound/sen_mi_lasergun01.mp3");
		soundlist.push_back("sound/sen_ka_heirappa01.mp3");
		soundlist.push_back("sound/sen_ge_bom17.mp3");
		soundlist.push_back("sound/sen_mi_robo_bato01.mp3");
		soundlist.push_back("sound/sen_ge_hasai02.mp3");
		soundlist.push_back("sound/se_maoudamashii_system49.mp3");
		soundlist.push_back("sound/se_maoudamashii_system39.mp3");//
		soundlist.push_back("sound/se_maoudamashii_system42.mp3");
	
		soundlist.push_back("sound/spawn.mp3");

	
		soundlist.push_back("sound/�R.mp3");
		soundlist.push_back("sound/�X.mp3");

	
		soundlist.push_back("sound/�Q�[���I�[�o�[.mp3");

		for(auto s:soundlist){
			if (ss.count(s) == 0){
				ss[s]=LoadSoundMem(s.c_str());
			}

		}
	
		SetUseASyncLoadFlag( FALSE ); // �񓯊��ǂݍ��݃t���OOFF

	}
	int SoundEffect::getSEVol(){return SEVol;}
	void SoundEffect::setSEVol(int v){SEVol=v;}
	void SoundEffect::playSE(string name,boolean ischeck){
		if(ischeck){
			if(CheckSoundMem(ss[name])==1)
				return;
		}
		PlaySoundMem(ss[name] ,DX_PLAYTYPE_BACK);
	}
	void SoundEffect::playSE(string name){SoundEffect::playSE(name,false);}

	void SoundEffect::stopSE(string name){StopSoundMem(ss[name] );}

	void SoundEffect::assignVol(int MASTERVol){
		int resse=255*(MASTERVol/(double)100)*(SEVol/(double)100);
		for(auto part:ss){
			ChangeVolumeSoundMem( resse ,part.second) ;
		}
		
	}