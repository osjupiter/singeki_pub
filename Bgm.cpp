#include "Bgm.h"



void Bgm::load(){
	BGMVol=100;
	LoadBGM("sound/システム/title.mp3",false);
	
	LoadBGM("sound/システム/stageselect.mp3",false);
	_nowBGM="";

}
void Bgm::loadStage(int sid){
	bgmlist.clear();
	switch (sid)
	{
	case 1:
		bgmlist.push_back("sound/荒野/kouya_1.mp3");
		bgmlist.push_back("sound/荒野/kouya_1.5.mp3");
		bgmlist.push_back("sound/荒野/kouya_2.mp3");
		bgmlist.push_back("sound/荒野/kouya_3.mp3");
		bgmlist.push_back("sound/荒野/kouya_5.mp3");
		bgmlist.push_back("sound/荒野/kouya_6.mp3");
		bgmlist.push_back("sound/荒野/kouya_7.mp3");
		bgmlist.push_back("sound/荒野/kouya_8.mp3");
		bgmlist.push_back("だみー");
		break;
	case 2:
		bgmlist.push_back("sound/雪原/setsugen_1.mp3");
		bgmlist.push_back("sound/雪原/setsugen_2.mp3");
		bgmlist.push_back("sound/雪原/setsugen_3.mp3");
		bgmlist.push_back("sound/雪原/setsugen_4.mp3");
		bgmlist.push_back("sound/雪原/setsugen_5.mp3");
		bgmlist.push_back("sound/雪原/setsugen_6.mp3");
		bgmlist.push_back("sound/雪原/setsugen_7.mp3");
		bgmlist.push_back("sound/雪原/setsugen_8.mp3");
		bgmlist.push_back("だみー");
		break;
	case 3:
		bgmlist.push_back("sound/雲の上/kumo_1.mp3");
		bgmlist.push_back("sound/雲の上/kumo_2.mp3");
		bgmlist.push_back("sound/雲の上/kumo_3.mp3");
		bgmlist.push_back("sound/雲の上/kumo_4.mp3");
		bgmlist.push_back("sound/雲の上/kumo_5.mp3");
		bgmlist.push_back("sound/雲の上/kumo_6.mp3");
		bgmlist.push_back("sound/雲の上/kumo_7.mp3");
		bgmlist.push_back("sound/雲の上/kumo_8.mp3");
		bgmlist.push_back("だみー");
		break;
	case 4:
		bgmlist.push_back("sound/森ガール/mori_1.mp3");
		bgmlist.push_back("sound/森ガール/mori_2.mp3");
		bgmlist.push_back("sound/森ガール/mori_3.mp3");
		bgmlist.push_back("sound/森ガール/mori_4.mp3");
		bgmlist.push_back("sound/森ガール/mori_5.mp3");
		bgmlist.push_back("sound/森ガール/mori_6.mp3");
		bgmlist.push_back("sound/森ガール/mori_7.mp3");
		bgmlist.push_back("sound/森ガール/mori_8.mp3");
		bgmlist.push_back("だみー");
		break;
	case 5:
		bgmlist.push_back("sound/水の中/mizu_1.mp3");
		bgmlist.push_back("sound/水の中/mizu_2.mp3");
		bgmlist.push_back("sound/水の中/mizu_3.mp3");
		bgmlist.push_back("sound/水の中/mizu_4.mp3");
		bgmlist.push_back("sound/水の中/mizu_5.mp3");
		bgmlist.push_back("sound/水の中/mizu_6.mp3");
		bgmlist.push_back("sound/水の中/mizu_7.mp3");
		bgmlist.push_back("sound/水の中/mizu_8.mp3");
		bgmlist.push_back("だみー");
		break;
	case 6:
		bgmlist.push_back("sound/メカシティ/meka_1.mp3");
		bgmlist.push_back("sound/メカシティ/meka_2.mp3");
		bgmlist.push_back("sound/メカシティ/meka_3.mp3");
		bgmlist.push_back("sound/メカシティ/meka_4.mp3");
		bgmlist.push_back("sound/メカシティ/meka_5.mp3");
		bgmlist.push_back("sound/メカシティ/meka_6.mp3");
		bgmlist.push_back("sound/メカシティ/meka_7.mp3");
		bgmlist.push_back("sound/メカシティ/meka_8.mp3");
		bgmlist.push_back("sound/メカシティ/meka_9.mp3");
		bgmlist.push_back("だみー");
		break;
	default:
		printfDx("loadStageerror!!");
		break;
	}
	Bgm::initBGM();
}
	
	void Bgm::setBGMVol(int v){BGMVol=v;}
	int Bgm::getBGMVol(){return BGMVol;}
	void Bgm::initBGM(){
		string n=bgmlist[0];
		Bgm::LoadBGM(n,true);
	}

	void Bgm::changeBGM(int stage_id){
		string s,n;
		if(bgmlist.max_size()>=stage_id){
			s=bgmlist[stage_id];
			DeleteSoundMem(bgms[_nowBGM]);
			Bgm::playBGM(s);
		}
		if(bgmlist.max_size()>=stage_id+1){
			n=bgmlist[stage_id+1];
			Bgm::LoadBGM(n,true);
		}
	}
	void Bgm::playBGM(string name,boolean defaulttrue){
		if(_nowBGM!=""){
			StopSoundMem(bgms[_nowBGM]);
		}
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
	void Bgm::releaseStageBGM(){
		for(auto hoge:bgmlist){
			DeleteSoundMem(bgms[hoge.c_str()]);
			bgms.erase(hoge.c_str());
		}
	}