#include"Images.h"
#include<map>
#include <string>
#include <iostream>
Images Images::ins;

void Images::load(){
	_nowBGM="";

//	gs[0]=LoadGraph("pic/test.jpg");
	LoadDivGraph("dat/img/歩兵w.png", ANI_HOHEI, ANI_HOHEI, 1, WID_HOHEI, HEI_HOHEI, g_hohei);
	LoadDivGraph("dat/img/歩兵a.png", ANI_HOHEI_ATK, ANI_HOHEI_ATK, 1, WID_HOHEI, HEI_HOHEI, g_hohei_atk);

	LoadDivGraph("dat/img/敵戦車w.png", ANI_TANK, ANI_TANK, 1, WID_TANK, HEI_TANK, g_tank[0]);
	LoadDivGraph("dat/img/敵戦車a.png", ANI_TANK_ATK, ANI_TANK_ATK, 1, WID_TANK ,HEI_TANK, g_tank_atk[0]);
	LoadDivGraph("dat/img/戦車死亡.png", ANI_TANK_DEL,1, ANI_TANK_DEL, WID_TANK_DEL, HEI_TANK_DEL, g_tank_dei[0]);
	
	LoadDivGraph("dat/img/敵戦車2w.png", ANI_TANK, ANI_TANK, 1, WID_TANK, HEI_TANK, g_tank[1]);
	LoadDivGraph("dat/img/敵戦車2a.png", ANI_TANK_ATK, ANI_TANK_ATK, 1, WID_TANK, HEI_TANK, g_tank_atk[1]);
	LoadDivGraph("dat/img/戦車死亡2.png", ANI_TANK_DEL, 1, ANI_TANK_DEL, WID_TANK_DEL, HEI_TANK_DEL, g_tank_dei[1]);

	LoadDivGraph("dat/img/敵戦車3w.png", ANI_TANK, ANI_TANK, 1, WID_TANK, HEI_TANK, g_tank[2]);
	LoadDivGraph("dat/img/敵戦車3a.png", ANI_TANK_ATK, ANI_TANK_ATK, 1, WID_TANK, HEI_TANK, g_tank_atk[2]);
	LoadDivGraph("dat/img/戦車死亡3.png", ANI_TANK_DEL, 1, ANI_TANK_DEL, WID_TANK_DEL, HEI_TANK_DEL, g_tank_dei[2]);

	LoadDivGraph("dat/img/ヘリw.png", ANI_COPTER, ANI_COPTER, 1, WID_COPTER, HEI_COPTER, g_copter);
	LoadDivGraph("dat/img/ヘリ死亡.png", ANI_COPTER_DIE, ANI_COPTER_DIE, 1, WID_COPTER_DIE, HEI_COPTER_DIE, g_copter_die);

	LoadDivGraph("dat/img/風船兵w.png", ANI_BALLOON, ANI_BALLOON, 1, WID_BALLOON, HEI_BALLOON, g_balloon);
	LoadDivGraph("dat/img/風船兵a.png", ANI_BALLOON_ATK, ANI_BALLOON_ATK, 1, WID_BALLOON, HEI_BALLOON, g_balloon_atk);

	LoadDivGraph("dat/img/ロボ兵w.png", ANI_BIG, ANI_BIG, 1, WID_BIG, HEI_BIG, g_robo);
	LoadDivGraph("dat/img/ロボ兵a.png", ANI_BIG_ATK, 6, 3, WID_BIG_ATK, HEI_BIG, g_robo_atk);

	LoadDivGraph("dat/img/ロデ子w.png", ANI_KAMIKAZE, ANI_KAMIKAZE, 1, WID_KAMIKAZE, HEI_KAMIKAZE, g_kamikaze);
	LoadDivGraph("dat/img/ロデ子a.png", ANI_KAMIKAZE_ATK, 5, 5, WID_KAMIKAZE_ATK, HEI_KAMIKAZE_ATK, g_kamikaze_atk);
	
	LoadDivGraph("dat/img/バズーカ兵w.png", ANI_BAZOOKA, ANI_BAZOOKA, 1, WID_BAZOOKA, HEI_BAZOOKA, g_bazooka);
	LoadDivGraph("dat/img/バズーカ兵a.png", ANI_BAZOOKA_ATK, 6, 2, WID_BAZOOKA_ATK, HEI_BAZOOKA_ATK, g_bazooka_atk);

	LoadDivGraph("dat/img/セグウェイ兵w.png", ANI_SEGWAY, ANI_SEGWAY, 1, WID_SEGWAY, HEI_SEGWAY, g_segway);
	LoadDivGraph("dat/img/セグウェイ兵爆走直前.png", ANI_SEGWAY_WAIT, ANI_SEGWAY_WAIT, 1, WID_SEGWAY_WAIT, HEI_SEGWAY, g_segway_wait);
	LoadDivGraph("dat/img/セグウェイ兵爆走中.png", ANI_SEGWAY, ANI_SEGWAY, 1, WID_SEGWAY_RUN, HEI_SEGWAY, g_segway_run);

	LoadDivGraph("dat/img/ゲッコーw.png", ANI_GEKKO, ANI_GEKKO, 1, WID_GEKKO, HEI_GEKKO, g_gekko);
	LoadDivGraph("dat/img/ゲッコー上a.png", ANI_GEKKO_UP, ANI_GEKKO, 1, WID_GEKKO, HEI_GEKKO, g_gekko_up);
	LoadDivGraph("dat/img/ゲッコー下a.png", ANI_GEKKO_DOWN, ANI_GEKKO_DOWN, 1, WID_GEKKO, HEI_GEKKO, g_gekko_down);

	LoadDivGraph("dat/img/レールガンさんw.png", ANI_RAILGUN, 1, ANI_RAILGUN, WID_RAILGUN, HEI_RAILGUN, g_rail);


	LoadDivGraph("dat/img/爆弾.png", ANI_BOMB, ANI_BOMB, 1, WID_BOMB, HEI_BOMB, g_bomb);
	LoadDivGraph("dat/img/爆発E.png", ANI_EXP, 6, 2, WID_EXP, HEI_EXP, g_exp);
	LoadDivGraph("dat/img/死亡時爆発.png", ANI_NOMALEXP, ANI_NOMALEXP, 1, WID_NOMALEXP, HEI_NOMALEXP, g_nomalExp);

	LoadDivGraph("dat/img/特大爆発エフェクト.png", ANI_BIGEXP, 5, 3, WID_BIGEXP, HEI_BIGEXP, g_bigexp);

	LoadDivGraph("dat/img/衝撃波.png", ANI_SHOCK, ANI_SHOCK, 1, WID_SHOCK, HEI_SHOCK, g_shock);
	LoadDivGraph("dat/img/ミサイル.png", ANI_MISSILE, ANI_MISSILE, 1, WID_MISSILE, HEI_MISSILE, g_missile);
	LoadDivGraph("dat/img/テポドン.png", ANI_TEPODON, ANI_TEPODON, 1, WID_TEPODON, HEI_TEPODON, g_tepodon);
	LoadDivGraph("dat/img/ビーム発射中.png", ANI_BEAM, 1,ANI_BEAM, WID_BEAM, HEI_BEAM, g_beam);
	LoadDivGraph("dat/img/ビームチャージ中.png", ANI_BEAM_C, ANI_BEAM_C, 1, WID_BEAM_C, HEI_BEAM_C, g_beam_c);

	LoadDivGraph("dat/img/銃被弾時e.png", ANI_GUNSHOT, ANI_GUNSHOT, 1, WID_GUNSHOT, HEI_GUNSHOT, g_gunshot);
	LoadDivGraph("dat/img/砲弾被弾時e.png", ANI_CANNONSHOT, ANI_CANNONSHOT, 1, WID_CANNONSHOT, HEI_CANNONSHOT, g_cannonshot);

	LoadDivGraph("dat/img/闇の世界/e2a1.png", 8, 8, 1, 96, 450, g_e_yamidrop[0]);
	LoadDivGraph("dat/img/闇の世界/e2a2.png", 8, 8, 1, 96, 450, g_e_yamidrop[1]);
	LoadDivGraph("dat/img/闇の世界/e2a3.png", 8, 8, 1, 96, 450, g_e_yamidrop[2]);

	LoadDivGraph("dat/img/闇の世界/ea1.png", 7, 7, 1, 155, 168, g_e_wisp[0]);
	LoadDivGraph("dat/img/闇の世界/ea2.png", 7, 7, 1, 155, 168, g_e_wisp[1]);
	LoadDivGraph("dat/img/闇の世界/ea3.png", 7, 7, 1, 155, 168, g_e_wisp[2]);


	back[0][0] = LoadGraph("dat/img/山/背景１−１.png");
	back[0][1] = LoadGraph("dat/img/山/背景１−５.png");
	back[0][2] = LoadGraph("dat/img/山/背景１−４.png");
	back[0][3] = LoadGraph("dat/img/山/背景１−２.png");
	back[0][4] = LoadGraph("dat/img/山/背景１−３.png");
	houdai_yama = LoadGraph("dat/img/山/山城砲台.png");

	back[1][0] = 0;
	back[1][1] = 0;
	back[1][2] = LoadGraph("dat/img/森/背景２−１.png");
	back[1][3] = LoadGraph("dat/img/森/背景２−２.png");
	back[1][4] = LoadGraph("dat/img/森/背景２−３.png");

	back[2][0] = 0;
	back[2][1] = 0;
	back[2][2] = LoadGraph("dat/img/夜戦/背景３−１.png");
	back[2][3] = LoadGraph("dat/img/夜戦/背景３−２.png");
	back[2][4] = LoadGraph("dat/img/夜戦/背景３−３.png");

	back[3][0] = LoadGraph("dat/img/海/背景４−１.png");
	back[3][1] = LoadGraph("dat/img/海/背景４−３.png");
	back[3][2] = 0;
	back[3][3] = 0;
	back[3][4] = LoadGraph("dat/img/海/背景４−２.png");

	back[4][0] = LoadGraph("dat/img/草原/背景５−１.png");
	back[4][1] = LoadGraph("dat/img/草原/背景５−４.png");
	back[4][2] = 0;
	back[4][3] = LoadGraph("dat/img/草原/背景５−２.png");
	back[4][4] = LoadGraph("dat/img/草原/背景５−３.png");

	back[5][0] = LoadGraph("dat/img/洞窟/背景６−１.png");
	back[5][1] = LoadGraph("dat/img/洞窟/背景６−２.png");
	back[5][2] = 0;
	back[5][3] = LoadGraph("dat/img/洞窟/背景６−３.png");
	back[5][4] = LoadGraph("dat/img/洞窟/背景６−４.png");

	back[6][0] = LoadGraph("dat/img/都市/背景７−１.png");
	back[6][1] = LoadGraph("dat/img/都市/背景７−２.png");
	back[6][2] = LoadGraph("dat/img/都市/背景７−３.png");
	back[6][3] = LoadGraph("dat/img/都市/背景７−４.png");
	back[6][4] = LoadGraph("dat/img/都市/背景７−５.png");
	
	back[7][0] = LoadGraph("dat/img/闇の世界/背景８−１.png");
	back[7][1] = 0;
	back[7][2] = 0;
	back[7][3] = LoadGraph("dat/img/闇の世界/背景８−２.png");
	back[7][4] = LoadGraph("dat/img/闇の世界/背景８−３.png");

	g_mekahaikyo=LoadGraph("dat/img/メカ廃墟.png");

	g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
	g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
	g_castle[0][2] = LoadGraph("dat/img/最初の拠点.png");
	
	g_castle[1][0] = LoadGraph("dat/img/山/山城.png");
	g_castle[1][1] = LoadGraph("dat/img/山/山城半壊.png");
	g_castle[1][2] = LoadGraph("dat/img/山/メカ山城.png");
	
	g_castle[2][0] = LoadGraph("dat/img/森/森城.png");
	g_castle[2][1] = LoadGraph("dat/img/森/森城半壊.png");
	g_castle[2][2] = LoadGraph("dat/img/森/メカ森城.png");
	
	g_castle[3][0] = LoadGraph("dat/img/夜戦/夜戦城.png");
	g_castle[3][1] = LoadGraph("dat/img/夜戦/夜戦城半壊.png");
	g_castle[3][2] = LoadGraph("dat/img/夜戦/メカ夜戦城.png");
	
	g_castle[4][0] = LoadGraph("dat/img/海/海城.png");
	g_castle[4][1] = LoadGraph("dat/img/海/海城半壊.png");
	g_castle[4][2] = LoadGraph("dat/img/海/メカ海城.png");
	
	g_castle[5][0] = LoadGraph("dat/img/草原/草原城.png");
	g_castle[5][1] = LoadGraph("dat/img/草原/草原城半壊.png");
	g_castle[5][2] = LoadGraph("dat/img/草原/メカ草原城.png");
	
	g_castle[6][0] = LoadGraph("dat/img/洞窟/洞窟城.png");
	g_castle[6][1] = LoadGraph("dat/img/洞窟/洞窟城半壊.png");
	g_castle[6][2] = LoadGraph("dat/img/洞窟/メカ洞窟城.png");
	
	g_castle[7][0] = LoadGraph("dat/img/都市/都市城.png");
	g_castle[7][1] = LoadGraph("dat/img/都市/都市城半壊.png");
	g_castle[7][2] = LoadGraph("dat/img/都市/メカ都市城.png");
	
	LoadDivGraph("dat/img/メカねむ娘.png", ANI_MEKANEMU, ANI_MEKANEMU, 1, WID_MEKANEMU, HEI_CASTLE, g_castle[8]);
	LoadDivGraph("dat/img/ラスボス雷.png", 3, 3, 1, 324, 364, g_thunder_mekanemu);



	//sound[0]=LoadSoundMem("sound/kuma.mp3");
	
	filelist.push_back("pic/test.jpg");
	filelist.push_back("pic/black.jpg");
	filelist.push_back("pic/title.png");
	filelist.push_back("pic/game.png");
	filelist.push_back("pic/start.png");
	filelist.push_back("pic/exit.png");
	filelist.push_back("pic/left.png");
	filelist.push_back("pic/right.png");
	filelist.push_back("pic/tou.png");

	filelist.push_back("pic/ba.png");
	filelist.push_back("pic/ha.png");
	filelist.push_back("pic/ka.png");
	filelist.push_back("pic/na.png");
	filelist.push_back("pic/ra.png");
	filelist.push_back("pic/sa.png");
	filelist.push_back("pic/資源.png");

	
	filelist.push_back("pic/HP.png");
	filelist.push_back("pic/攻撃速度.png");
	filelist.push_back("pic/資源ダウン.png");
	filelist.push_back("pic/生産速度.png");
	filelist.push_back("pic/速さ.png");
	filelist.push_back("pic/防御.png");
	filelist.push_back("pic/力.png");


	filelist.push_back("pic/メカ海城a.png");
	filelist.push_back("pic/メカ海城a2.png");
	filelist.push_back("pic/メカ山城a.png");
	filelist.push_back("pic/メカ山城a2.png");
	filelist.push_back("pic/メカ森城a.png");
	filelist.push_back("pic/メカ森城a2.png");
	filelist.push_back("pic/メカ都市城a.png");
	filelist.push_back("pic/メカ都市城a2.png");
	filelist.push_back("pic/メカ洞窟城a.png");
	filelist.push_back("pic/メカ洞窟城a2.png");
	filelist.push_back("pic/メカ夜戦城a.png");
	filelist.push_back("pic/メカ夜戦城a2.png");
	filelist.push_back("pic/最初の拠点a.png");
	filelist.push_back("pic/最初の拠点a2.png");
	filelist.push_back("pic/メカ草原城a.png");
	filelist.push_back("pic/メカ草原城a2.png");
	filelist.push_back("pic/生産中止a.png");
	filelist.push_back("pic/MUI.png");
	filelist.push_back("pic/SUI、オプション.png");
	filelist.push_back("pic/ユニット選択ウインドウ.png");
	filelist.push_back("pic/MUIのステージのまる.png");
	filelist.push_back("pic/ユニット選択ウインドウ.png");
	filelist.push_back("pic/ユニット選択ウインドウ２.png");
	filelist.push_back("pic/カスタム用大ウインドウ.png");
	filelist.push_back("pic/カスタム用小さな歯車.png");
	filelist.push_back("pic/カスタム用小ウインドウ.png");
	filelist.push_back("pic/GAMEOVER.png");
	filelist.push_back("pic/歩兵ボタン1.png");
	filelist.push_back("pic/歩兵ボタン2.png");
	filelist.push_back("pic/歩兵ボタン1m.png");
	filelist.push_back("pic/歩兵ボタン3.png");
	filelist.push_back("pic/エンディング.png");
	filelist.push_back("pic/Lv.png");

	soundlist.push_back("sound/kuma.mp3");
	soundlist.push_back("sound/se_maoudamashii_system49.wav");
	soundlist.push_back("sound/button03a.mp3");
	soundlist.push_back("sound/taihou03.mp3");
	soundlist.push_back("sound/misairu.mp3");
	soundlist.push_back("sound/shot002.wav");
	soundlist.push_back("sound/gun04.mp3");


	soundlist.push_back("sound/橋.mp3");
	soundlist.push_back("sound/山.mp3");
	soundlist.push_back("sound/森.mp3");
	soundlist.push_back("sound/草原.mp3");
	soundlist.push_back("sound/都市.mp3");
	soundlist.push_back("sound/洞窟.mp3");
	soundlist.push_back("sound/夜戦.mp3");
	soundlist.push_back("sound/エンディング.mp3");
	soundlist.push_back("sound/ゲームオーバー.mp3");
	soundlist.push_back("sound/タイトル.mp3");
	soundlist.push_back("sound/闇の世界.mp3");

	
	for(auto s:filelist){
		gs[s]=LoadGraph(s.c_str());

	}	

	for(auto s:soundlist){
		ss[s]=LoadSoundMem(s.c_str());

	}
	
	blend=LoadBlendGraph("pic/blend.jpg");

	font=CreateFontToHandle( "メイリオ" , 13 , 3 ,DX_FONTTYPE_ANTIALIASING_EDGE_8X8) ;


}

	void Images::init(){ins.load();}
	Images* Images::getIns(){return &ins;}

	int Images::get(const char name[]){return ins.gs[string(name)];}
	int Images::getSound(const char name[]){return ins.ss[string(name)];}

	
	void Images::playSE(string name,boolean ischeck){
		if(ischeck){
			if(CheckSoundMem(ins.ss[name])==1)
				return;
		}
		PlaySoundMem(ins.ss[name] ,DX_PLAYTYPE_BACK);
	}
	void Images::playSE(string name){Images::playSE(name,false);}

	void Images::stopSE(string name){StopSoundMem(ins.ss[name] );}

	int Images::getMusumeIcon(int id){
		string s;
		switch (id){
			case 0:
				s="pic/生産中止a.png";
				break;
			case 1:
				s="pic/na.png";
				break;
			case 2:
				s="pic/ha.png";
				break;
			case 3:
				s="pic/ra.png";
				break;
			case 4:
				s="pic/ka.png";
				break;
			case 5:
				s="pic/ba.png";
				break;
			case 6:
				s="pic/sa.png";
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
		}
		return ins.get(s.c_str());
	}
	int Images::getSiroIcon(int id,boolean defalt_false){
		string s;
		switch (id){
			case 0:
				s="pic/最初の拠点a";
				break;
			case 1:
				s="pic/メカ山城a";
				break;
			case 2:
				s="pic/メカ森城a";
				break;
			case 3:
				s="pic/メカ夜戦城a";
				break;
			case 4:
				s="pic/メカ海城a";
				break;
			case 5:
				s="pic/メカ草原城a";
				break;
			case 6:
				s="pic/メカ洞窟城a";
				break;
			case 7:
				s="pic/メカ都市城a";
				break;
			case 8:
				break;
			case 9:
				break;
		}
		if(defalt_false)
			s+="2";
		return ins.get((s+".png").c_str());
	}

	int Images::getParamTypeIcon(ParamType i){
		string hoge[]={
			"pic/力.png",
			"pic/HP.png",
			"pic/速さ.png",
			"pic/防御.png",
			"",
			"pic/生産速度.png",
			"pic/資源ダウン.png",
			"pic/攻撃速度.png",
		};
		return ins.get(hoge[i].c_str());

	}

	void Images::playBGM(string name,boolean defaulttrue){
		if(ins._nowBGM!="")
			StopSoundMem(getSound(ins._nowBGM.c_str()));
		if(name!="")
			if(defaulttrue){
				PlaySoundMem(getSound(name.c_str()),DX_PLAYTYPE_LOOP);
			}else{
				PlaySoundMem(getSound(name.c_str()),DX_PLAYTYPE_BACK);
			}
			ins._nowBGM=name;
	}
