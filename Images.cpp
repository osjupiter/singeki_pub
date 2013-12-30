#include"Images.h"
#include "DxLib.h"
#include<map>
#include <string>
#include <iostream>
Images Images::ins;

void Images::load(){
	SetUseASyncLoadFlag( FALSE ); // ”ñ“¯Šú“Ç‚İ‚İƒtƒ‰ƒOOFF
	//ƒ^ƒCƒgƒ‹‚Ég‚¤‚à‚Ì‚½‚¿‚æ
	filelist.push_back("pic/title.png");
	filelist.push_back("pic/’è‚Ú‚é‚¯[‚Ì.png");
	soundlist.push_back("sound/button03a.mp3");
	soundlist.push_back("sound/se_maoudamashii_system49.wav");
		
	filelist.push_back("pic/test.jpg");
	filelist.push_back("pic/black.jpg");
	blend=LoadBlendGraph("pic/blend.jpg");
	soundlist.push_back("sound/ƒ^ƒCƒgƒ‹.mp3");

		
	for(auto s:filelist){
		gs[s]=LoadGraph(s.c_str());

	}	

	for(auto s:soundlist){
		ss[s]=LoadSoundMem(s.c_str());

	}




	SetUseASyncLoadFlag( TRUE ); // ”ñ“¯Šú“Ç‚İ‚İƒtƒ‰ƒOON
	

	_nowBGM="";

//	gs[0]=LoadGraph("pic/test.jpg");
	LoadDivGraph("dat/img/•à•ºw.png", ANI_HOHEI, ANI_HOHEI, 1, WID_HOHEI, HEI_HOHEI, g_hohei);
	LoadDivGraph("dat/img/•à•ºa.png", ANI_HOHEI_ATK, ANI_HOHEI_ATK, 1, WID_HOHEI, HEI_HOHEI, g_hohei_atk);

	LoadDivGraph("dat/img/“GíÔw.png", ANI_TANK, ANI_TANK, 1, WID_TANK, HEI_TANK, g_tank[0]);
	LoadDivGraph("dat/img/“GíÔa.png", ANI_TANK_ATK, ANI_TANK_ATK, 1, WID_TANK ,HEI_TANK, g_tank_atk[0]);
	LoadDivGraph("dat/img/íÔ€–S.png", ANI_TANK_DEL,1, ANI_TANK_DEL, WID_TANK_DEL, HEI_TANK_DEL, g_tank_dei[0]);
	
	LoadDivGraph("dat/img/“GíÔ2w.png", ANI_TANK, ANI_TANK, 1, WID_TANK, HEI_TANK, g_tank[1]);
	LoadDivGraph("dat/img/“GíÔ2a.png", ANI_TANK_ATK, ANI_TANK_ATK, 1, WID_TANK, HEI_TANK, g_tank_atk[1]);
	LoadDivGraph("dat/img/íÔ€–S2.png", ANI_TANK_DEL, 1, ANI_TANK_DEL, WID_TANK_DEL, HEI_TANK_DEL, g_tank_dei[1]);

	LoadDivGraph("dat/img/“GíÔ3w.png", ANI_TANK, ANI_TANK, 1, WID_TANK, HEI_TANK, g_tank[2]);
	LoadDivGraph("dat/img/“GíÔ3a.png", ANI_TANK_ATK, ANI_TANK_ATK, 1, WID_TANK, HEI_TANK, g_tank_atk[2]);
	LoadDivGraph("dat/img/íÔ€–S3.png", ANI_TANK_DEL, 1, ANI_TANK_DEL, WID_TANK_DEL, HEI_TANK_DEL, g_tank_dei[2]);

	LoadDivGraph("dat/img/ƒwƒŠw.png", ANI_COPTER, ANI_COPTER, 1, WID_COPTER, HEI_COPTER, g_copter);
	LoadDivGraph("dat/img/ƒwƒŠ€–S.png", ANI_COPTER_DIE, ANI_COPTER_DIE, 1, WID_COPTER_DIE, HEI_COPTER_DIE, g_copter_die);

	LoadDivGraph("dat/img/•—‘D•ºw.png", ANI_BALLOON, ANI_BALLOON, 1, WID_BALLOON, HEI_BALLOON, g_balloon);
	LoadDivGraph("dat/img/•—‘D•ºa.png", ANI_BALLOON_ATK, ANI_BALLOON_ATK, 1, WID_BALLOON, HEI_BALLOON, g_balloon_atk);

	LoadDivGraph("dat/img/ƒƒ{•ºw.png", ANI_BIG, ANI_BIG, 1, WID_BIG, HEI_BIG, g_robo);
	LoadDivGraph("dat/img/ƒƒ{•ºa.png", ANI_BIG_ATK, 6, 3, WID_BIG_ATK, HEI_BIG, g_robo_atk);

	LoadDivGraph("dat/img/ƒƒfqw.png", ANI_KAMIKAZE, ANI_KAMIKAZE, 1, WID_KAMIKAZE, HEI_KAMIKAZE, g_kamikaze);
	LoadDivGraph("dat/img/ƒƒfqa.png", ANI_KAMIKAZE_ATK, 5, 5, WID_KAMIKAZE_ATK, HEI_KAMIKAZE_ATK, g_kamikaze_atk);
	
	LoadDivGraph("dat/img/ƒoƒY[ƒJ•ºw.png", ANI_BAZOOKA, ANI_BAZOOKA, 1, WID_BAZOOKA, HEI_BAZOOKA, g_bazooka);
	LoadDivGraph("dat/img/ƒoƒY[ƒJ•ºa.png", ANI_BAZOOKA_ATK, 6, 2, WID_BAZOOKA_ATK, HEI_BAZOOKA_ATK, g_bazooka_atk);

	LoadDivGraph("dat/img/ƒZƒOƒEƒFƒC•ºw.png", ANI_SEGWAY, ANI_SEGWAY, 1, WID_SEGWAY, HEI_SEGWAY, g_segway);
	LoadDivGraph("dat/img/ƒZƒOƒEƒFƒC•º”š‘–’¼‘O.png", ANI_SEGWAY_WAIT, ANI_SEGWAY_WAIT, 1, WID_SEGWAY_WAIT, HEI_SEGWAY, g_segway_wait);
	LoadDivGraph("dat/img/ƒZƒOƒEƒFƒC•º”š‘–’†.png", ANI_SEGWAY, ANI_SEGWAY, 1, WID_SEGWAY_RUN, HEI_SEGWAY, g_segway_run);

	LoadDivGraph("dat/img/ƒQƒbƒR[w.png", ANI_GEKKO, ANI_GEKKO, 1, WID_GEKKO, HEI_GEKKO, g_gekko);
	LoadDivGraph("dat/img/ƒQƒbƒR[ãa.png", ANI_GEKKO_UP, ANI_GEKKO, 1, WID_GEKKO, HEI_GEKKO, g_gekko_up);
	LoadDivGraph("dat/img/ƒQƒbƒR[‰ºa.png", ANI_GEKKO_DOWN, ANI_GEKKO_DOWN, 1, WID_GEKKO, HEI_GEKKO, g_gekko_down);

	LoadDivGraph("dat/img/ƒŒ[ƒ‹ƒKƒ“‚³‚ñw.png", ANI_RAILGUN, 1, ANI_RAILGUN, WID_RAILGUN, HEI_RAILGUN, g_rail);


	LoadDivGraph("dat/img/”š’e.png", ANI_BOMB, ANI_BOMB, 1, WID_BOMB, HEI_BOMB, g_bomb);
	LoadDivGraph("dat/img/”š”­E.png", ANI_EXP, 6, 2, WID_EXP, HEI_EXP, g_exp);
	LoadDivGraph("dat/img/€–S”š”­.png", ANI_NOMALEXP, ANI_NOMALEXP, 1, WID_NOMALEXP, HEI_NOMALEXP, g_nomalExp);

	LoadDivGraph("dat/img/“Á‘å”š”­ƒGƒtƒFƒNƒg.png", ANI_BIGEXP, 5, 3, WID_BIGEXP, HEI_BIGEXP, g_bigexp);

	LoadDivGraph("dat/img/ÕŒ‚”g.png", ANI_SHOCK, ANI_SHOCK, 1, WID_SHOCK, HEI_SHOCK, g_shock);
	LoadDivGraph("dat/img/ƒ~ƒTƒCƒ‹.png", ANI_MISSILE, ANI_MISSILE, 1, WID_MISSILE, HEI_MISSILE, g_missile);
	LoadDivGraph("dat/img/ƒeƒ|ƒhƒ“.png", ANI_TEPODON, ANI_TEPODON, 1, WID_TEPODON, HEI_TEPODON, g_tepodon);
	LoadDivGraph("dat/img/ƒr[ƒ€”­Ë’†.png", ANI_BEAM, 1,ANI_BEAM, WID_BEAM, HEI_BEAM, g_beam);
	LoadDivGraph("dat/img/ƒr[ƒ€ƒ`ƒƒ[ƒW’†.png", ANI_BEAM_C, ANI_BEAM_C, 1, WID_BEAM_C, HEI_BEAM_C, g_beam_c);

	LoadDivGraph("dat/img/e”í’ee.png", ANI_GUNSHOT, ANI_GUNSHOT, 1, WID_GUNSHOT, HEI_GUNSHOT, g_gunshot);
	LoadDivGraph("dat/img/–C’e”í’ee.png", ANI_CANNONSHOT, ANI_CANNONSHOT, 1, WID_CANNONSHOT, HEI_CANNONSHOT, g_cannonshot);

	LoadDivGraph("dat/img/ˆÅ‚Ì¢ŠE/e2a1.png", 8, 8, 1, 96, 450, g_e_yamidrop[0]);
	LoadDivGraph("dat/img/ˆÅ‚Ì¢ŠE/e2a2.png", 8, 8, 1, 96, 450, g_e_yamidrop[1]);
	LoadDivGraph("dat/img/ˆÅ‚Ì¢ŠE/e2a3.png", 8, 8, 1, 96, 450, g_e_yamidrop[2]);

	LoadDivGraph("dat/img/ˆÅ‚Ì¢ŠE/ea1.png", 7, 7, 1, 155, 168, g_e_wisp[0]);
	LoadDivGraph("dat/img/ˆÅ‚Ì¢ŠE/ea2.png", 7, 7, 1, 155, 168, g_e_wisp[1]);
	LoadDivGraph("dat/img/ˆÅ‚Ì¢ŠE/ea3.png", 7, 7, 1, 155, 168, g_e_wisp[2]);


	back[0][0] = LoadGraph("dat/img/R/”wŒi‚P|‚P.png");
	back[0][1] = LoadGraph("dat/img/R/”wŒi‚P|‚T.png");
	back[0][2] = LoadGraph("dat/img/R/”wŒi‚P|‚S.png");
	back[0][3] = LoadGraph("dat/img/R/”wŒi‚P|‚Q.png");
	back[0][4] = LoadGraph("dat/img/R/”wŒi‚P|‚R.png");
	houdai_yama = LoadGraph("dat/img/R/Ré–C‘ä.png");

	back[1][0] = 0;
	back[1][1] = 0;
	back[1][2] = LoadGraph("dat/img/X/”wŒi‚Q|‚P.png");
	back[1][3] = LoadGraph("dat/img/X/”wŒi‚Q|‚Q.png");
	back[1][4] = LoadGraph("dat/img/X/”wŒi‚Q|‚R.png");

	back[2][0] = 0;
	back[2][1] = 0;
	back[2][2] = LoadGraph("dat/img/–éí/”wŒi‚R|‚P.png");
	back[2][3] = LoadGraph("dat/img/–éí/”wŒi‚R|‚Q.png");
	back[2][4] = LoadGraph("dat/img/–éí/”wŒi‚R|‚R.png");

	back[3][0] = LoadGraph("dat/img/ŠC/”wŒi‚S|‚P.png");
	back[3][1] = LoadGraph("dat/img/ŠC/”wŒi‚S|‚R.png");
	back[3][2] = 0;
	back[3][3] = 0;
	back[3][4] = LoadGraph("dat/img/ŠC/”wŒi‚S|‚Q.png");

	back[4][0] = LoadGraph("dat/img/‘Œ´/”wŒi‚T|‚P.png");
	back[4][1] = LoadGraph("dat/img/‘Œ´/”wŒi‚T|‚S.png");
	back[4][2] = 0;
	back[4][3] = LoadGraph("dat/img/‘Œ´/”wŒi‚T|‚Q.png");
	back[4][4] = LoadGraph("dat/img/‘Œ´/”wŒi‚T|‚R.png");

	back[5][0] = LoadGraph("dat/img/“´ŒA/”wŒi‚U|‚P.png");
	back[5][1] = 0;
	back[5][2] = LoadGraph("dat/img/“´ŒA/”wŒi‚U|‚Q.png");
	back[5][3] = LoadGraph("dat/img/“´ŒA/”wŒi‚U|‚R.png");
	back[5][4] = LoadGraph("dat/img/“´ŒA/”wŒi‚U|‚S.png");

	back[6][0] = LoadGraph("dat/img/“ss/”wŒi‚V|‚P.png");
	back[6][1] = LoadGraph("dat/img/“ss/”wŒi‚V|‚Q.png");
	back[6][2] = LoadGraph("dat/img/“ss/”wŒi‚V|‚R.png");
	back[6][3] = LoadGraph("dat/img/“ss/”wŒi‚V|‚S.png");
	back[6][4] = LoadGraph("dat/img/“ss/”wŒi‚V|‚T.png");
	
	back[7][0] = LoadGraph("dat/img/ˆÅ‚Ì¢ŠE/”wŒi‚W|‚P.png");
	back[7][1] = 0;
	back[7][2] = 0;
	back[7][3] = LoadGraph("dat/img/ˆÅ‚Ì¢ŠE/”wŒi‚W|‚Q.png");
	back[7][4] = LoadGraph("dat/img/ˆÅ‚Ì¢ŠE/”wŒi‚W|‚R.png");

	g_mekahaikyo=LoadGraph("dat/img/ƒƒJ”pšĞ.png");

	g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
	g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
	g_castle[0][2] = LoadGraph("dat/img/Å‰‚Ì‹’“_.png");
	
	g_castle[1][0] = LoadGraph("dat/img/R/Ré.png");
	g_castle[1][1] = LoadGraph("dat/img/R/Ré”¼‰ó.png");
	g_castle[1][2] = LoadGraph("dat/img/R/ƒƒJRé.png");
	
	g_castle[2][0] = LoadGraph("dat/img/X/Xé.png");
	g_castle[2][1] = LoadGraph("dat/img/X/Xé”¼‰ó.png");
	g_castle[2][2] = LoadGraph("dat/img/X/ƒƒJXé.png");
	
	g_castle[3][0] = LoadGraph("dat/img/–éí/–éíé.png");
	g_castle[3][1] = LoadGraph("dat/img/–éí/–éíé”¼‰ó.png");
	g_castle[3][2] = LoadGraph("dat/img/–éí/ƒƒJ–éíé.png");
	
	g_castle[4][0] = LoadGraph("dat/img/ŠC/ŠCé.png");
	g_castle[4][1] = LoadGraph("dat/img/ŠC/ŠCé”¼‰ó.png");
	g_castle[4][2] = LoadGraph("dat/img/ŠC/ƒƒJŠCé.png");
	
	g_castle[5][0] = LoadGraph("dat/img/‘Œ´/‘Œ´é.png");
	g_castle[5][1] = LoadGraph("dat/img/‘Œ´/‘Œ´é”¼‰ó.png");
	g_castle[5][2] = LoadGraph("dat/img/‘Œ´/ƒƒJ‘Œ´é.png");
	
	g_castle[6][0] = LoadGraph("dat/img/“´ŒA/“´ŒAé.png");
	g_castle[6][1] = LoadGraph("dat/img/“´ŒA/“´ŒAé”¼‰ó.png");
	g_castle[6][2] = LoadGraph("dat/img/“´ŒA/ƒƒJ“´ŒAé.png");
	
	g_castle[7][0] = LoadGraph("dat/img/“ss/“ssé.png");
	g_castle[7][1] = LoadGraph("dat/img/“ss/“ssé”¼‰ó.png");
	g_castle[7][2] = LoadGraph("dat/img/“ss/ƒƒJ“ssé.png");
	
	LoadDivGraph("dat/img/ƒƒJ‚Ë‚Ş–º.png", ANI_MEKANEMU, ANI_MEKANEMU, 1, WID_MEKANEMU, HEI_CASTLE, g_castle[8]);
	LoadDivGraph("dat/img/ƒ‰ƒXƒ{ƒX—‹.png", 3, 3, 1, 324, 364, g_thunder_mekanemu);



	//sound[0]=LoadSoundMem("sound/kuma.mp3");

	
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
	filelist.push_back("pic/ba2.png");
	filelist.push_back("pic/ha2.png");
	filelist.push_back("pic/ka2.png");
	filelist.push_back("pic/na2.png");
	filelist.push_back("pic/ra2.png");
	filelist.push_back("pic/sa2.png");
	filelist.push_back("pic/‘Œ¹.png");

	
	filelist.push_back("pic/HP.png");
	filelist.push_back("pic/UŒ‚‘¬“x.png");
	filelist.push_back("pic/‘Œ¹ƒ_ƒEƒ“.png");
	filelist.push_back("pic/¶Y‘¬“x.png");
	filelist.push_back("pic/‘¬‚³.png");
	filelist.push_back("pic/–hŒä.png");
	filelist.push_back("pic/—Í.png");

	filelist.push_back("pic/HP2.png");
	filelist.push_back("pic/UŒ‚‘¬“x2.png");
	filelist.push_back("pic/‘Œ¹ƒ_ƒEƒ“2.png");
	filelist.push_back("pic/¶Y‘¬“x2.png");
	filelist.push_back("pic/‘¬‚³2.png");
	filelist.push_back("pic/–hŒä2.png");
	filelist.push_back("pic/—Í2.png");



	filelist.push_back("pic/ƒƒJŠCéa.png");
	filelist.push_back("pic/ƒƒJŠCéa2.png");
	filelist.push_back("pic/ƒƒJRéa.png");
	filelist.push_back("pic/ƒƒJRéa2.png");
	filelist.push_back("pic/ƒƒJXéa.png");
	filelist.push_back("pic/ƒƒJXéa2.png");
	filelist.push_back("pic/ƒƒJ“sséa.png");
	filelist.push_back("pic/ƒƒJ“sséa2.png");
	filelist.push_back("pic/ƒƒJ“´ŒAéa.png");
	filelist.push_back("pic/ƒƒJ“´ŒAéa2.png");
	filelist.push_back("pic/ƒƒJ–éíéa.png");
	filelist.push_back("pic/ƒƒJ–éíéa2.png");
	filelist.push_back("pic/Å‰‚Ì‹’“_a.png");
	filelist.push_back("pic/Å‰‚Ì‹’“_a2.png");
	filelist.push_back("pic/ƒƒJ‘Œ´éa.png");
	filelist.push_back("pic/ƒƒJ‘Œ´éa2.png");
	filelist.push_back("pic/¶Y’†~a.png");
	filelist.push_back("pic/¶Y’†~a2.png");
	filelist.push_back("pic/SUI.png");
	filelist.push_back("pic/‚Ü‚é‚È‚µMUI.png");
	filelist.push_back("pic/SUIAƒIƒvƒVƒ‡ƒ“.png");
	filelist.push_back("pic/ƒ†ƒjƒbƒg‘I‘ğƒEƒCƒ“ƒhƒE.png");
	filelist.push_back("pic/MUI‚ÌƒXƒe[ƒW‚Ì‚Ü‚é.png");
	filelist.push_back("pic/ƒ†ƒjƒbƒg‘I‘ğƒEƒCƒ“ƒhƒE.png");
	filelist.push_back("pic/ƒ†ƒjƒbƒg‘I‘ğƒEƒCƒ“ƒhƒE‚Q.png");
	filelist.push_back("pic/ƒJƒXƒ^ƒ€—p‘åƒEƒCƒ“ƒhƒE.png");
	filelist.push_back("pic/ƒJƒXƒ^ƒ€—p¬‚³‚È•Ô.png");
	filelist.push_back("pic/ƒJƒXƒ^ƒ€—p¬ƒEƒCƒ“ƒhƒE.png");
	filelist.push_back("pic/GAMEOVER.png");
	filelist.push_back("pic/•à•ºƒ{ƒ^ƒ“1.png");
	filelist.push_back("pic/•à•ºƒ{ƒ^ƒ“2.png");
	filelist.push_back("pic/•à•ºƒ{ƒ^ƒ“1m.png");
	filelist.push_back("pic/•à•ºƒ{ƒ^ƒ“3.png");
	filelist.push_back("pic/ƒGƒ“ƒfƒBƒ“ƒO.png");
	filelist.push_back("pic/Lv.png");
	filelist.push_back("pic/CUSTUM.png");
	filelist.push_back("pic/CUSTUMon.png");
	//ƒ|ƒbƒvƒAƒbƒvƒEƒCƒ“ƒhƒE.png
	filelist.push_back("pic/ƒ|ƒbƒvƒAƒbƒvƒEƒCƒ“ƒhƒE.png");
	filelist.push_back("pic/ƒ|ƒbƒvƒAƒbƒv•Ô.png");

	soundlist.push_back("sound/kuma.mp3");
	
	soundlist.push_back("sound/taihou03.mp3");
	soundlist.push_back("sound/misairu.mp3");
	soundlist.push_back("sound/shot002.wav");
	soundlist.push_back("sound/gun04.mp3");
	soundlist.push_back("sound/sen_ge_taihou08.mp3");
	//soundlist.push_back("sound/sen_ge_taihou06.mp3");
	soundlist.push_back("sound/sen_mi_lasergun01.mp3");
	soundlist.push_back("sound/sen_ka_heirappa01.mp3");
	soundlist.push_back("sound/sen_ge_bom17.mp3");
	soundlist.push_back("sound/sen_mi_robo_bato01.mp3");
	soundlist.push_back("sound/sen_ge_hasai02.mp3");
	soundlist.push_back("sound/se_maoudamashii_system49.mp3");
	soundlist.push_back("sound/se_maoudamashii_system39.mp3");//
	soundlist.push_back("sound/se_maoudamashii_system42.mp3");
	
	soundlist.push_back("sound/R.mp3");
	soundlist.push_back("sound/X.mp3");

	
	soundlist.push_back("sound/ƒQ[ƒ€ƒI[ƒo[.mp3");
	/*
	soundlist.push_back("sound/ƒGƒ“ƒfƒBƒ“ƒO.mp3");
	soundlist.push_back("sound/ˆÅ‚Ì¢ŠE.mp3");
	soundlist.push_back("sound/‹´.mp3"); 
	soundlist.push_back("sound/‘Œ´.mp3");
	soundlist.push_back("sound/“ss.mp3");
	soundlist.push_back("sound/“´ŒA.mp3");
	soundlist.push_back("sound/–éí.mp3");
	*/
	for(auto s:filelist){
		if (gs.count(s) == 0)
			gs[s]=LoadGraph(s.c_str());

	}	

	for(auto s:soundlist){
		if (ss.count(s) == 0)
			ss[s]=LoadSoundMem(s.c_str());

	}

	ChangeVolumeSoundMem(255*60/100, ss["sound/shot002.wav"]);
	ChangeVolumeSoundMem(255 * 70 / 100, ss["sound/sen_mi_robo_bato01.mp3"]);


	SetUseASyncLoadFlag( FALSE ); // ”ñ“¯Šú“Ç‚İ‚İƒtƒ‰ƒOOFF



	font=CreateFontToHandle( "ƒƒCƒŠƒI" , 13 , 5 ,DX_FONTTYPE_ANTIALIASING_EDGE_4X4) ;


	
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

	int Images::getMusumeIcon(int id,boolean dfalse){
		string s;
		switch (id){
			case 0:
				s="pic/¶Y’†~a";
				break;
			case 1:
				s="pic/na";
				break;
			case 2:
				s="pic/ha";
				break;
			case 3:
				s="pic/ra";
				break;
			case 4:
				s="pic/ka";
				break;
			case 5:
				s="pic/ba";
				break;
			case 6:
				s="pic/sa";
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
		}
		if(dfalse)s+="2";
		return ins.get((s+".png").c_str());
	}
	int Images::getSiroIcon(int id,boolean defalt_false){
		string s;
		switch (id){
			case 0:
				s="pic/Å‰‚Ì‹’“_a";
				break;
			case 1:
				s="pic/ƒƒJRéa";
				break;
			case 2:
				s="pic/ƒƒJXéa";
				break;
			case 3:
				s="pic/ƒƒJ–éíéa";
				break;
			case 4:
				s="pic/ƒƒJŠCéa";
				break;
			case 5:
				s="pic/ƒƒJ‘Œ´éa";
				break;
			case 6:
				s="pic/ƒƒJ“´ŒAéa";
				break;
			case 7:
				s="pic/ƒƒJ“sséa";
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

	int Images::getParamTypeIcon(ParamType i,boolean dfalse){
		string hoge[]={
			"pic/—Í",
			"pic/HP",
			"pic/‘¬‚³",
			"pic/–hŒä",
			"",
			"pic/¶Y‘¬“x",
			"pic/‘Œ¹ƒ_ƒEƒ“",
			"pic/UŒ‚‘¬“x",
		};
		
		return ins.get((hoge[i]+(dfalse?"2":"")+".png").c_str());

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

	void Images::LoadSound(string s){
		SetUseASyncLoadFlag( TRUE ); // ”ñ“¯Šú“Ç‚İ‚İƒtƒ‰ƒOOFF
		if(ins.ss.count(s)==0)
			ins.ss[s]=LoadSoundMem(s.c_str());
		
		SetUseASyncLoadFlag( FALSE ); // ”ñ“¯Šú“Ç‚İ‚İƒtƒ‰ƒOOFF
	}


