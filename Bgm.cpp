#include "Bgm.h"



void Bgm::load(){
	BGMVol=100;
	LoadBGM("sound/�V�X�e��/title.mp3",false);
	
	LoadBGM("sound/�V�X�e��/stageselect.mp3",false);
	_nowBGM="";

}
void Bgm::loadStage(int sid){
	bgmlist.clear();
	switch (sid)
	{
	case 1:
		bgmlist.push_back("sound/�r��/kouya_1.mp3");
		bgmlist.push_back("sound/�r��/kouya_1.5.mp3");
		bgmlist.push_back("sound/�r��/kouya_2.mp3");
		bgmlist.push_back("sound/�r��/kouya_3.mp3");
		bgmlist.push_back("sound/�r��/kouya_5.mp3");
		bgmlist.push_back("sound/�r��/kouya_6.mp3");
		bgmlist.push_back("sound/�r��/kouya_7.mp3");
		bgmlist.push_back("sound/�r��/kouya_8.mp3");
		bgmlist.push_back("���݁[");
		break;
	case 2:
		bgmlist.push_back("sound/�ጴ/setsugen_1.mp3");
		bgmlist.push_back("sound/�ጴ/setsugen_2.mp3");
		bgmlist.push_back("sound/�ጴ/setsugen_3.mp3");
		bgmlist.push_back("sound/�ጴ/setsugen_4.mp3");
		bgmlist.push_back("sound/�ጴ/setsugen_5.mp3");
		bgmlist.push_back("sound/�ጴ/setsugen_6.mp3");
		bgmlist.push_back("sound/�ጴ/setsugen_7.mp3");
		bgmlist.push_back("sound/�ጴ/setsugen_8.mp3");
		bgmlist.push_back("���݁[");
		break;
	case 3:
		bgmlist.push_back("sound/�_�̏�/kumo_1.mp3");
		bgmlist.push_back("sound/�_�̏�/kumo_2.mp3");
		bgmlist.push_back("sound/�_�̏�/kumo_3.mp3");
		bgmlist.push_back("sound/�_�̏�/kumo_4.mp3");
		bgmlist.push_back("sound/�_�̏�/kumo_5.mp3");
		bgmlist.push_back("sound/�_�̏�/kumo_6.mp3");
		bgmlist.push_back("sound/�_�̏�/kumo_7.mp3");
		bgmlist.push_back("sound/�_�̏�/kumo_8.mp3");
		bgmlist.push_back("���݁[");
		break;
	case 4:
		bgmlist.push_back("sound/�X�K�[��/mori_1.mp3");
		bgmlist.push_back("sound/�X�K�[��/mori_2.mp3");
		bgmlist.push_back("sound/�X�K�[��/mori_3.mp3");
		bgmlist.push_back("sound/�X�K�[��/mori_4.mp3");
		bgmlist.push_back("sound/�X�K�[��/mori_5.mp3");
		bgmlist.push_back("sound/�X�K�[��/mori_6.mp3");
		bgmlist.push_back("sound/�X�K�[��/mori_7.mp3");
		bgmlist.push_back("sound/�X�K�[��/mori_8.mp3");
		bgmlist.push_back("���݁[");
		break;
	case 5:
		bgmlist.push_back("sound/���̒�/mizu_1.mp3");
		bgmlist.push_back("sound/���̒�/mizu_2.mp3");
		bgmlist.push_back("sound/���̒�/mizu_3.mp3");
		bgmlist.push_back("sound/���̒�/mizu_4.mp3");
		bgmlist.push_back("sound/���̒�/mizu_5.mp3");
		bgmlist.push_back("sound/���̒�/mizu_6.mp3");
		bgmlist.push_back("sound/���̒�/mizu_7.mp3");
		bgmlist.push_back("sound/���̒�/mizu_8.mp3");
		bgmlist.push_back("���݁[");
		break;
	case 6:
		bgmlist.push_back("sound/���J�V�e�B/meka_1.mp3");
		bgmlist.push_back("sound/���J�V�e�B/meka_2.mp3");
		bgmlist.push_back("sound/���J�V�e�B/meka_3.mp3");
		bgmlist.push_back("sound/���J�V�e�B/meka_4.mp3");
		bgmlist.push_back("sound/���J�V�e�B/meka_5.mp3");
		bgmlist.push_back("sound/���J�V�e�B/meka_6.mp3");
		bgmlist.push_back("sound/���J�V�e�B/meka_7.mp3");
		bgmlist.push_back("sound/���J�V�e�B/meka_8.mp3");
		bgmlist.push_back("sound/���J�V�e�B/meka_9.mp3");
		bgmlist.push_back("���݁[");
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
	void Bgm::releaseStageBGM(){
		for(auto hoge:bgmlist){
			DeleteSoundMem(bgms[hoge.c_str()]);
			bgms.erase(hoge.c_str());
		}
	}