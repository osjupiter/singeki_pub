#include "SoundEffect.h"


	void SoundEffect::load(){
		vector<string> soundlist;
		SetUseASyncLoadFlag( FALSE ); // 非同期読み込みフラグOFF
		SEVol=100;
		soundlist.push_back("sound/button03a.mp3");
		soundlist.push_back("sound/se_maoudamashii_system49.wav");
	
		for(auto s:soundlist){
			ss[s]=LoadSoundMem(s.c_str());

		}
	
		SetUseASyncLoadFlag( TRUE ); // 非同期読み込みフラグON

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

		soundlist.push_back("sound/イカロス銃声（修正）.mp3");
		soundlist.push_back("sound/お花砲台（根っこの音）.mp3");
		soundlist.push_back("sound/お花砲台.mp3");
		soundlist.push_back("sound/スチームパンク（地割れ）.mp3");
		soundlist.push_back("sound/ビーバーブシュー(修正).mp3");
		soundlist.push_back("sound/ビーム（修正1.2）.mp3");
		soundlist.push_back("sound/レイピア.mp3");
		soundlist.push_back("sound/魚雷発射音.mp3");
		soundlist.push_back("sound/玉ねぎミサイル移動.mp3");
		soundlist.push_back("sound/車輪砲台.mp3");
		soundlist.push_back("sound/偶像雷.mp3");
		soundlist.push_back("sound/謎の手キラキラ音.mp3");
		soundlist.push_back("sound/ガジガジメカ音（修正）.mp3");

		soundlist.push_back("sound/sen_ge_bom18_姫騎士大衆宝具ＳＥ.mp3");
		soundlist.push_back("sound/sen_ge_bomsuijou01_スチームパンクロボＳＥ.mp3");
		soundlist.push_back("sound/aura1_姫騎士チャージＳＥ.mp3");
		soundlist.push_back("sound/magic-attack-holy1_魔女攻撃ＳＥ.mp3");

		
		soundlist.push_back("sound/農家（くわ）.mp3");

		soundlist.push_back("sound/魔方陣.mp3");

	
		soundlist.push_back("sound/山.mp3");
		soundlist.push_back("sound/森.mp3");


	
		soundlist.push_back("sound/ゲームオーバー.mp3");

		for(auto s:soundlist){
			if (ss.count(s) == 0){
				ss[s]=LoadSoundMem(s.c_str());
			}

		}
	
		SetUseASyncLoadFlag( FALSE ); // 非同期読み込みフラグOFF

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