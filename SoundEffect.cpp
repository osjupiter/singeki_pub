#include "SoundEffect.h"


	void SoundEffect::load(){
		vector<string> soundlist;
		SetUseASyncLoadFlag( FALSE ); // ñ¯úÇÝÝtOOFF
		SEVol=100;
		soundlist.push_back("sound/button03a.mp3");
		soundlist.push_back("sound/se_maoudamashii_system49.wav");
	
		for(auto s:soundlist){
			ss[s]=LoadSoundMem(s.c_str());

		}
	
		SetUseASyncLoadFlag( TRUE ); // ñ¯úÇÝÝtOON

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

		soundlist.push_back("sound/CJXeºiC³j.mp3");
		soundlist.push_back("sound/¨ÔCäiªÁ±Ì¹j.mp3");
		soundlist.push_back("sound/¨ÔCä.mp3");
		soundlist.push_back("sound/X`[pNinêj.mp3");
		soundlist.push_back("sound/r[o[uV[(C³).mp3");
		soundlist.push_back("sound/r[iC³1.2j.mp3");
		soundlist.push_back("sound/CsA.mp3");
		soundlist.push_back("sound/­Ë¹.mp3");
		soundlist.push_back("sound/ÊË¬~TCÚ®.mp3");
		soundlist.push_back("sound/ÔÖCä.mp3");
		soundlist.push_back("sound/ô.mp3");
		soundlist.push_back("sound/äÌèLL¹.mp3");
		soundlist.push_back("sound/KWKWJ¹iC³j.mp3");

		soundlist.push_back("sound/sen_ge_bom18_PRmåOóïrd.mp3");
		soundlist.push_back("sound/sen_ge_bomsuijou01_X`[pN{rd.mp3");
		soundlist.push_back("sound/aura1_PRm`[Wrd.mp3");
		soundlist.push_back("sound/magic-attack-holy1_Urd.mp3");

		
		soundlist.push_back("sound/_Æi­íj.mp3");

		soundlist.push_back("sound/ûw.mp3");

	
		soundlist.push_back("sound/R.mp3");
		soundlist.push_back("sound/X.mp3");


	
		soundlist.push_back("sound/Q[I[o[.mp3");

		for(auto s:soundlist){
			if (ss.count(s) == 0){
				ss[s]=LoadSoundMem(s.c_str());
			}

		}
	
		SetUseASyncLoadFlag( FALSE ); // ñ¯úÇÝÝtOOFF

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