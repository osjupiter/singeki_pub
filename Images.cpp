#include"Images.h"
#include "DxLib.h"
#include<map>
#include <string>
#include <iostream>
Images Images::ins;

template
<
    typename TYPE,
    std::size_t SIZE
>
std::size_t array_length(const TYPE (&)[SIZE])
{
    return SIZE;
}

void Images::load(){
	vector<string> filelist;

	SetUseASyncLoadFlag( FALSE ); // ”ñ“¯Šú“Ç‚İ‚İƒtƒ‰ƒOOFF
	//ƒ^ƒCƒgƒ‹‚Ég‚¤‚à‚Ì‚½‚¿‚æ
	filelist.push_back("pic/title.png");
	filelist.push_back("pic/’è‚Ú‚é‚¯[‚Ì.png");
	
	
		
	filelist.push_back("pic/test.jpg");
	filelist.push_back("pic/black.jpg");
	
	blend=LoadBlendGraph("pic/blend.jpg");
	

		
	for(auto s:filelist){
		gs[s]=LoadGraph(s.c_str());

	}	





	SetUseASyncLoadFlag( TRUE ); // ”ñ“¯Šú“Ç‚İ‚İƒtƒ‰ƒOON
	

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

	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/—c—w2.png",ANI_YOUJO_W,ANI_YOUJO_W,1,WID_YOUJO,HEI_YOUJO,g_youjo_w);
	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/—c—d2.png", ANI_YOUJO_D, ANI_YOUJO_D, 1, WID_YOUJO, HEI_YOUJO, g_youjo_d);
	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/—c—j2.png", ANI_YOUJO_A, ANI_YOUJO_A/2, 2, WID_YOUJO, HEI_YOUJO, g_youjo_a);

	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/‚˜U‚èw.png", ANI_TATEKO_W, ANI_TATEKO_W, 1, WID_TATEKO, HEI_TATEKO, g_tateko_w);
	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/‚˜U‚èa.png", ANI_TATEKO_A, ANI_TATEKO_A, 1, WID_TATEKO, HEI_TATEKO, g_tateko_a);

	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/•P‹Rmw2.png", ANI_HIME_W, ANI_HIME_W, 1, WID_HIME_W, HEI_HIME, g_hime_w);
	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/•P‹Rma2.png", ANI_HIME_A, ANI_HIME_A, 1, WID_HIME_A, HEI_HIME, g_hime_a);

	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/ƒCƒJƒƒXw2.png", ANI_IKAROS_W, ANI_IKAROS_W, 1, WID_IKAROS_W, HEI_IKAROS, g_ikaros_w);
	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/ƒCƒJƒƒXa2.png", ANI_IKAROS_A, ANI_IKAROS_A, 1, WID_IKAROS_A, HEI_IKAROS, g_ikaros_a);

	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/ƒ}ƒWƒ‡w2.png", ANI_MAJO_W, ANI_MAJO_W, 1, WID_MAJO_W, HEI_MAJO, g_majo_w);
	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/ƒ}ƒWƒ‡a2.png", ANI_MAJO_A, ANI_MAJO_A, 1, WID_MAJO_A, HEI_MAJO, g_majo_a);

	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/”_‰Æw.png", ANI_NOUKA_W, ANI_NOUKA_W, 1, WID_NOUKA_W, HEI_NOUKA, g_nouka_w);
	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/”_‰Æs.png", ANI_NOUKA_A, 4, 4, WID_NOUKA_A, HEI_NOUKA, g_nouka_a1);
	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/”_‰Æm.png", ANI_NOUKA_A, 4, 4, WID_NOUKA_A, HEI_NOUKA, g_nouka_a2);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/ƒKƒWƒKƒWƒƒJw.png", ANI_GAJIGAJI_W, ANI_GAJIGAJI_W, 1, WID_GAJIGAJI, HEI_GAJIGAJI_W, g_gajigaji_w[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/ƒKƒWƒKƒWƒƒJa.png", ANI_GAJIGAJI_A, ANI_GAJIGAJI_A, 1, WID_GAJIGAJI, HEI_GAJIGAJI_A, g_gajigaji_a[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/ƒKƒWƒKƒWƒƒJ2w.png", ANI_GAJIGAJI_W, ANI_GAJIGAJI_W, 1, WID_GAJIGAJI, HEI_GAJIGAJI_W, g_gajigaji_w[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/ƒKƒWƒKƒWƒƒJ2a.png", ANI_GAJIGAJI_A, ANI_GAJIGAJI_A, 1, WID_GAJIGAJI, HEI_GAJIGAJI_A, g_gajigaji_a[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/ƒKƒWƒKƒWƒƒJ3w.png", ANI_GAJIGAJI_W, ANI_GAJIGAJI_W, 1, WID_GAJIGAJI, HEI_GAJIGAJI_W, g_gajigaji_w[2]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/ƒKƒWƒKƒWƒƒJ3a.png", ANI_GAJIGAJI_A, ANI_GAJIGAJI_A, 1, WID_GAJIGAJI, HEI_GAJIGAJI_A, g_gajigaji_a[2]);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/Ô—Ö–C‘äw.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_w[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/Ô—Ö–C‘äa1.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_a[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/Ô—Ö–C‘ä2w.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_w[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/Ô—Ö–C‘ä2a.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_a[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/Ô—Ö–C‘ä3w.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_w[2]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/Ô—Ö–C‘ä3a.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_a[2]);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/ƒSƒŒ[ƒ€1s.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_w[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/ƒSƒŒ[ƒ€1a.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_a[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/ƒSƒŒ[ƒ€2s.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_w[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/ƒSƒŒ[ƒ€2a.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_a[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/ƒSƒŒ[ƒ€3s.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_w[2]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/ƒSƒŒ[ƒ€3a.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_a[2]);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/ƒr[ƒo[w.png", ANI_BEEBAR_W, ANI_BEEBAR_W, 1, WID_BEEBAR_W, HEI_BEEBAR_W, g_beebar_w[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/ƒr[ƒo[a.png", ANI_BEEBAR_A, ANI_BEEBAR_A, 1, WID_BEEBAR_A, HEI_BEEBAR_A, g_beebar_a[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/ƒr[ƒo[2w.png", ANI_BEEBAR_W, ANI_BEEBAR_W, 1, WID_BEEBAR_W, HEI_BEEBAR_W, g_beebar_w[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/ƒr[ƒo[2a.png", ANI_BEEBAR_A, ANI_BEEBAR_A, 1, WID_BEEBAR_A, HEI_BEEBAR_A, g_beebar_a[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/ƒr[ƒo[3w.png", ANI_BEEBAR_W, ANI_BEEBAR_W, 1, WID_BEEBAR_W, HEI_BEEBAR_W, g_beebar_w[2]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/ƒr[ƒo[3a.png", ANI_BEEBAR_A, ANI_BEEBAR_A, 1, WID_BEEBAR_A, HEI_BEEBAR_A, g_beebar_a[2]);

	
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/‚³‚¢‚Í‚Äa1.png", ANI_SAIHATE_A, 1, ANI_SAIHATE_A, WID_SAIHATE_A_R, HEI_SAIHATE, g_saihate_a_r);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/‚³‚¢‚Í‚Äa2.png", ANI_SAIHATE_A, ANI_SAIHATE_A, 1, WID_SAIHATE, HEI_SAIHATE_A_S, g_saihate_a_s);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/‚³‚¢‚Í‚Ät.png", ANI_SAIHATE_T, ANI_SAIHATE_T, 1, WID_SAIHATE, HEI_SAIHATE, g_saihate_t);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/‚³‚¢‚Í‚Äh.png", ANI_SAIHATE_H, 3, 3, WID_SAIHATE, HEI_SAIHATE, g_saihate_h);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/ƒ‚ƒmƒŠƒX1w.png", ANI_MONORIS_W, ANI_MONORIS_W, 1, WID_MONORIS, HEI_MONORIS, g_monoris_w[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/ƒ‚ƒmƒŠƒX1a1.png", ANI_MONORIS_A1, ANI_MONORIS_A1, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a1[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/ƒ‚ƒmƒŠƒX1a2.png", ANI_MONORIS_A2, ANI_MONORIS_A2, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a2[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/ƒ‚ƒmƒŠƒX2w.png", ANI_MONORIS_W, ANI_MONORIS_W, 1, WID_MONORIS, HEI_MONORIS, g_monoris_w[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/ƒ‚ƒmƒŠƒX2a1.png", ANI_MONORIS_A1, ANI_MONORIS_A1, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a1[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/ƒ‚ƒmƒŠƒX2a2.png", ANI_MONORIS_A2, ANI_MONORIS_A2, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a2[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/ƒ‚ƒmƒŠƒX3w.png", ANI_MONORIS_W, ANI_MONORIS_W, 1, WID_MONORIS, HEI_MONORIS, g_monoris_w[2]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/ƒ‚ƒmƒŠƒX3a1.png", ANI_MONORIS_A1, ANI_MONORIS_A1, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a1[2]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/ƒ‚ƒmƒŠƒX3a2.png", ANI_MONORIS_A2, ANI_MONORIS_A2, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a2[2]);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/”­“d‰_‚P•à‚­.png", ANI_DENGUMO_W, ANI_DENGUMO_W, 1, WID_DENGUMO, HEI_DENGUMO, g_dengumo_w[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/”­“d‰_‚PUŒ‚.png", ANI_DENGUMO_A, 5 , 3, WID_DENGUMO, HEI_DENGUMO, g_dengumo_a[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/”­“d‰_‚Q•à‚­.png", ANI_DENGUMO_W, ANI_DENGUMO_W, 1, WID_DENGUMO, HEI_DENGUMO, g_dengumo_w[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/”­“d‰_‚QUŒ‚.png", ANI_DENGUMO_A, 5, 3, WID_DENGUMO, HEI_DENGUMO, g_dengumo_a[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/”­“d‰_‚R•à‚­.png", ANI_DENGUMO_W, ANI_DENGUMO_W, 1, WID_DENGUMO, HEI_DENGUMO, g_dengumo_w[2]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/”­“d‰_‚RUŒ‚.png", ANI_DENGUMO_A, 5, 3, WID_DENGUMO, HEI_DENGUMO, g_dengumo_a[2]);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/ƒr[ƒ€ƒGƒtƒFƒNƒg1.png", ANI_MONOBEAM, ANI_MONOBEAM, 1, WID_MONOBEAM, HEI_MONOBEAM, g_monobeam[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/ƒr[ƒ€ƒGƒtƒFƒNƒg2.png", ANI_MONOBEAM, ANI_MONOBEAM, 1, WID_MONOBEAM, HEI_MONOBEAM, g_monobeam[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/ƒr[ƒ€ƒGƒtƒFƒNƒg3.png", ANI_MONOBEAM, ANI_MONOBEAM, 1, WID_MONOBEAM, HEI_MONOBEAM, g_monobeam[2]);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/—‹‚P.png", ANI_DENKAMI, 1, ANI_DENKAMI, WID_DENKAMI, HEI_DENKAMI, g_denkami[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/—‹2.png", ANI_DENKAMI, 1, ANI_DENKAMI, WID_DENKAMI, HEI_DENKAMI, g_denkami[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/—‹3.png", ANI_DENKAMI, 1, ANI_DENKAMI, WID_DENKAMI, HEI_DENKAMI, g_denkami[2]);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/öq’ø1w.png", ANI_SENKOU_W, ANI_SENKOU_W, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_w[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/öq’ø1a.png", ANI_SENKOU_A, ANI_SENKOU_A, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_a[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/öq’ø2w.png", ANI_SENKOU_W, ANI_SENKOU_W, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_w[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/öq’ø2a.png", ANI_SENKOU_A, ANI_SENKOU_A, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_a[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/öq’ø3w.png", ANI_SENKOU_W, ANI_SENKOU_W, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_w[2]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/öq’ø3a.png", ANI_SENKOU_A, ANI_SENKOU_A, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_a[2]);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/‹›—‹1.png", ANI_GYORAI, ANI_GYORAI, 1, WID_GYORAI, HEI_GYORAI, g_gyorai[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/‹›—‹2.png", ANI_GYORAI, ANI_GYORAI, 1, WID_GYORAI, HEI_GYORAI, g_gyorai[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/‹›—‹3.png", ANI_GYORAI, ANI_GYORAI, 1, WID_GYORAI, HEI_GYORAI, g_gyorai[2]);


	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/“ä‚ÌGè1oŒ».png", ANI_SHOKUSH_S, 5, 3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_s[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/“ä‚ÌGè1UŒ‚.png", ANI_SHOKUSH_A, 3,3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_a[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/“ä‚ÌGè2oŒ».png", ANI_SHOKUSH_S, 5,3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_s[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/“ä‚ÌGè2UŒ‚.png", ANI_SHOKUSH_A, 3,3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_a[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/“ä‚ÌGè3oŒ».png", ANI_SHOKUSH_S, 5,3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_s[2]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/“ä‚ÌGè3UŒ‚.png", ANI_SHOKUSH_A, 3,3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_a[2]);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/“ä‚ÌGè1ƒLƒ‰ƒLƒ‰.png", ANI_KIRAKIRA, 6,2, WID_KIRAKIRA, HEI_KIRAKIRA, g_kirakira[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/“ä‚ÌGè2ƒLƒ‰ƒLƒ‰.png", ANI_KIRAKIRA, 6,2, WID_KIRAKIRA, HEI_KIRAKIRA, g_kirakira[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/“ä‚ÌGè3ƒLƒ‰ƒLƒ‰.png", ANI_KIRAKIRA, 6,2, WID_KIRAKIRA, HEI_KIRAKIRA, g_kirakira[2]);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/XƒK[ƒ‹/‚¨‰Ô–C‘ä1oŒ».png", ANI_OHANA_S, 4, 4, WID_OHANA, HEI_OHANA, g_ohana_s[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/XƒK[ƒ‹/‚¨‰Ô–C‘ä1UŒ‚.png", ANI_OHANA_A, 3, 3, WID_OHANA, HEI_OHANA, g_ohana_a[0]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/XƒK[ƒ‹/‚¨‰Ô–C‘ä2oŒ».png", ANI_OHANA_S, 4, 4, WID_OHANA, HEI_OHANA, g_ohana_s[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/XƒK[ƒ‹/‚¨‰Ô–C‘ä2UŒ‚.png", ANI_OHANA_A, 3, 3, WID_OHANA, HEI_OHANA, g_ohana_a[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/XƒK[ƒ‹/‚¨‰Ô–C‘ä3oŒ».png", ANI_OHANA_S, 4, 4, WID_OHANA, HEI_OHANA, g_ohana_s[2]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/XƒK[ƒ‹/‚¨‰Ô–C‘ä3UŒ‚.png", ANI_OHANA_A, 3, 3, WID_OHANA, HEI_OHANA, g_ohana_a[2]);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/XƒK[ƒ‹/‹Ê‚Ë‚¬ƒ~ƒTƒCƒ‹1.png", ANI_NEGIMISSILE, 2, 1, WID_NEGIMISSILE, HEI_NEGIMISSILE, g_negimissile[2]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/XƒK[ƒ‹/‹Ê‚Ë‚¬ƒ~ƒTƒCƒ‹2.png", ANI_NEGIMISSILE, 2, 1, WID_NEGIMISSILE, HEI_NEGIMISSILE, g_negimissile[1]);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/XƒK[ƒ‹/‹Ê‚Ë‚¬ƒ~ƒTƒCƒ‹3.png", ANI_NEGIMISSILE, 2, 1, WID_NEGIMISSILE, HEI_NEGIMISSILE, g_negimissile[0]);


	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/‰Ô‚“.png", ANI_HANA, 5, 5, WID_HANA, HEI_HANA, g_hana);

	LoadDivGraph("dat/img/”š’e.png", ANI_BOMB, ANI_BOMB, 1, WID_BOMB, HEI_BOMB, g_bomb);
	LoadDivGraph("dat/img/”š”­E.png", ANI_EXP, 6, 2, WID_EXP, HEI_EXP, g_exp);
	LoadDivGraph("dat/img/€–S”š”­.png", ANI_NOMALEXP, ANI_NOMALEXP, 1, WID_NOMALEXP, HEI_NOMALEXP, g_nomalExp);

	LoadDivGraph("dat/img/“Á‘å”š”­ƒGƒtƒFƒNƒg.png", ANI_BIGEXP, 5, 3, WID_BIGEXP, HEI_BIGEXP, g_bigexp);

	LoadDivGraph("dat/img/ÕŒ‚”g.png", ANI_SHOCK, ANI_SHOCK, 1, WID_SHOCK, HEI_SHOCK, g_shock);
	LoadDivGraph("dat/img/ƒ~ƒTƒCƒ‹.png", ANI_MISSILE, ANI_MISSILE, 1, WID_MISSILE, HEI_MISSILE, g_missile);
	LoadDivGraph("dat/img/ƒeƒ|ƒhƒ“.png", ANI_TEPODON, ANI_TEPODON, 1, WID_TEPODON, HEI_TEPODON, g_tepodon);
	LoadDivGraph("dat/img/ƒr[ƒ€”­Ë’†.png", ANI_BEAM, 1,ANI_BEAM, WID_BEAM, HEI_BEAM, g_beam);
	LoadDivGraph("dat/img/ƒr[ƒ€ƒ`ƒƒ[ƒW’†.png", ANI_BEAM_C, ANI_BEAM_C, 1, WID_BEAM_C, HEI_BEAM_C, g_beam_c);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/‚ä‚«‚¾‚Ü1.png", ANI_YUKIDAMA, 4, 2, WID_YUKIDAMA, HEI_YUKIDAMA, g_yukidama1);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/‚ä‚«‚¾‚Ü2.png", ANI_YUKIDAMA, 4, 2, WID_YUKIDAMA, HEI_YUKIDAMA, g_yukidama2);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/áŒ´/ƒSƒŒƒ€‚Ìº.png", ANI_GVOICE, ANI_GVOICE, 1, WID_GVOICE, HEI_GVOICE, g_gvoice);

	LoadDivGraph("dat/img/e”í’ee.png", ANI_GUNSHOT, ANI_GUNSHOT, 1, WID_GUNSHOT, HEI_GUNSHOT, g_gunshot);
	LoadDivGraph("dat/img/–C’e”í’ee.png", ANI_CANNONSHOT, ANI_CANNONSHOT, 1, WID_CANNONSHOT, HEI_CANNONSHOT, g_cannonshot);

	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/‚©‚İ‚Â‚«ƒGƒtƒFƒNƒg.png", ANI_GAJIKAMI, ANI_GAJIKAMI, 1, WID_GAJIKAMI, HEI_GAJIKAMI, g_gajikami);
	LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/‰_‚Ìã/ƒr[ƒ€”í’e‚P.png", ANI_MONOB_H, ANI_MONOB_H, 1, WID_MONOB_H, HEI_MONOB_H, g_monob_h);
	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/–‚•ûw.png", ANI_MAHOJIN, 5, 4, WID_MAHOJIN, HEI_MAHOJIN, g_mahojin);
	LoadDivGraph("dat/img/‚Ş‚·‚ßƒ†ƒjƒbƒg/aŒ‚ƒGƒtƒFƒNƒg1.png", ANI_ZANGEKI, ANI_ZANGEKI, 1, WID_ZANGEKI, HEI_ZANGEKI, g_zangeki);


	LoadDivGraph("dat/img/ˆÅ‚Ì¢ŠE/e2a1.png", 8, 8, 1, 96, 450, g_e_yamidrop[0]);
	LoadDivGraph("dat/img/ˆÅ‚Ì¢ŠE/e2a2.png", 8, 8, 1, 96, 450, g_e_yamidrop[1]);
	LoadDivGraph("dat/img/ˆÅ‚Ì¢ŠE/e2a3.png", 8, 8, 1, 96, 450, g_e_yamidrop[2]);

	LoadDivGraph("dat/img/ˆÅ‚Ì¢ŠE/ea1.png", 7, 7, 1, 155, 168, g_e_wisp[0]);
	LoadDivGraph("dat/img/ˆÅ‚Ì¢ŠE/ea2.png", 7, 7, 1, 155, 168, g_e_wisp[1]);
	LoadDivGraph("dat/img/ˆÅ‚Ì¢ŠE/ea3.png", 7, 7, 1, 155, 168, g_e_wisp[2]);
	houdai_yama = LoadGraph("dat/img/R/Ré–C‘ä.png");
	/*
*/



	g_mekahaikyo=LoadGraph("dat/img/ƒƒJ”pšĞ.png");

	
	LoadDivGraph("dat/img/ƒƒJ‚Ë‚Ş–º.png", ANI_MEKANEMU, ANI_MEKANEMU, 1, WID_MEKANEMU, HEI_CASTLE, g_castle[8]);
	LoadDivGraph("dat/img/ƒ‰ƒXƒ{ƒX—‹.png", 3, 3, 1, 324, 364, g_thunder_mekanemu);



	//sound[0]=LoadSoundMem("sound/kuma.mp3");

	
	
	filelist.push_back("pic/tou.png");

	filelist.push_back("pic/Pause.png");

	filelist.push_back("pic/clear.png");
	
	filelist.push_back("pic/ba.png");
	filelist.push_back("pic/ha.png");
	filelist.push_back("pic/ka.png");
	filelist.push_back("pic/na.png");
	filelist.push_back("pic/ra.png");
	filelist.push_back("pic/sa.png");

	filelist.push_back("pic/bu.png");
	filelist.push_back("pic/ja.png");
	filelist.push_back("pic/ma.png");
	filelist.push_back("pic/ta.png");
	filelist.push_back("pic/wa.png");
	filelist.push_back("pic/ya.png");

	filelist.push_back("pic/ba2.png");
	filelist.push_back("pic/ha2.png");
	filelist.push_back("pic/ka2.png");
	filelist.push_back("pic/na2.png");
	filelist.push_back("pic/ra2.png");
	filelist.push_back("pic/sa2.png");

	
	filelist.push_back("pic/bu2.png");
	filelist.push_back("pic/ja2.png");
	filelist.push_back("pic/ma2.png");
	filelist.push_back("pic/ta2.png");
	filelist.push_back("pic/wa2.png");
	filelist.push_back("pic/ya2.png");

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

	
	filelist.push_back("pic/ƒ[ƒ‹ƒhƒ}ƒbƒva.png");
	filelist.push_back("pic/ƒ[ƒ‹ƒhƒ}ƒbƒvb.png");
	filelist.push_back("pic/ƒ[ƒ‹ƒhƒ}ƒbƒvc.png");
	filelist.push_back("pic/ƒ[ƒ‹ƒhƒ}ƒbƒvd.png");
	filelist.push_back("pic/ƒ[ƒ‹ƒhƒ}ƒbƒve.png");
	filelist.push_back("pic/ƒ[ƒ‹ƒhƒ}ƒbƒvf.png");
	
	filelist.push_back("pic/ƒ[ƒ‹ƒhƒ}ƒbƒvg.png");

	
	filelist.push_back("pic/oŒ‚‘Oƒ†ƒjƒbƒg‘I‘ğƒEƒCƒ“ƒhƒE.png");
	filelist.push_back("pic/oŒ‚ƒ{ƒ^ƒ“ON.png");
	filelist.push_back("pic/oŒ‚ƒ{ƒ^ƒ“OFF.png");
	
	filelist.push_back("pic/oŒ‚ƒ{ƒ^ƒ“NO.png");
	filelist.push_back("pic/world_stage.png");




	filelist.push_back("pic/¶Y’†~a.png");
	filelist.push_back("pic/¶Y’†~a2.png");
	filelist.push_back("pic/MUI.png");

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


	for(auto s:filelist){
		if (gs.count(s) == 0)
			gs[s]=LoadGraph(s.c_str());

	}	

	SetUseASyncLoadFlag( FALSE ); // ”ñ“¯Šú“Ç‚İ‚İƒtƒ‰ƒOOFF
	font=CreateFontToHandle( "ƒƒCƒŠƒI" , 13 , 5 ,DX_FONTTYPE_ANTIALIASING_EDGE_4X4) ;
	
	font2=CreateFontToHandle( "ƒƒCƒŠƒI" , 30 , 5 ,DX_FONTTYPE_ANTIALIASING_EDGE_4X4) ;
}

	void Images::init(){ins.load();}
	Images* Images::getIns(){return &ins;}

	int Images::get(const char name[]){return ins.gs[string(name)];}


	


	int Images::getMusumeIcon(int id,boolean dfalse){
		string hoge[]={
			"pic/¶Y’†~a",
			"pic/na",
			"pic/ha",
			"pic/ra",
			"pic/ka",
			"pic/ba",
			"pic/sa",
			"pic/wa",
			"pic/bu",
			"pic/ta",
			"pic/ma",
			"pic/ya",
			"pic/ja",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",

		};
		string s=hoge[id];

		if(dfalse)s+="2";
		return ins.get((s+".png").c_str());
	}
	int Images::getSiroIcon(int id,boolean defalt_false){
		return ins.g_shiro_icon[id][(defalt_false)?1:0];
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


	void Images::loadStage(int sid){
		


		SetUseASyncLoadFlag( TRUE ); // ”ñ“¯Šú“Ç‚İ‚İƒtƒ‰ƒOON
		switch (sid)
		{
		case 1:
			
			back[0][0] = 0;
			back[0][1] = LoadGraph("dat/img/r–ì/r–ì‚P|‚S.png");
			back[0][2] = LoadGraph("dat/img/r–ì/r–ì‚P|‚R.png");
			back[0][3] = LoadGraph("dat/img/r–ì/r–ì‚P|‚Q.png");
			back[0][4] = LoadGraph("dat/img/r–ì/r–ì‚P|‚P.png");

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/r–ì/r–ì‚PD‚T|‚S.png");
			back[1][2] = LoadGraph("dat/img/r–ì/r–ì‚PD‚T|‚R.png");
			back[1][3] = LoadGraph("dat/img/r–ì/r–ì‚PD‚T|‚Q.png");
			back[1][4] = LoadGraph("dat/img/r–ì/r–ì‚PD‚T|‚P.png");

			back[2][0] = 0;
			back[2][1] = LoadGraph("dat/img/r–ì/r–ì‚Q|‚S.png");
			back[2][2] = LoadGraph("dat/img/r–ì/r–ì‚Q|‚R.png");
			back[2][3] = LoadGraph("dat/img/r–ì/r–ì‚Q|‚Q.png");
			back[2][4] = LoadGraph("dat/img/r–ì/r–ì‚Q|‚P.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/r–ì/r–ì‚R|‚S.png");
			back[3][2] = LoadGraph("dat/img/r–ì/r–ì‚R|‚R.png");
			back[3][3] = LoadGraph("dat/img/r–ì/r–ì‚R|‚Q.png");
			back[3][4] = LoadGraph("dat/img/r–ì/r–ì‚R|‚P.png");

			back[4][0] = LoadGraph("dat/img/r–ì/r–ì‚T|‚T.png");
			back[4][1] = LoadGraph("dat/img/r–ì/r–ì‚T|‚S.png");
			back[4][2] = LoadGraph("dat/img/r–ì/r–ì‚T|‚R.png");
			back[4][3] = LoadGraph("dat/img/r–ì/r–ì‚T|‚Q.png");
			back[4][4] = LoadGraph("dat/img/r–ì/r–ì‚T|‚P.png");

			back[5][0] = 0;
			back[5][1] = LoadGraph("dat/img/r–ì/r–ì‚U|‚S.png");
			back[5][2] = LoadGraph("dat/img/r–ì/r–ì‚U|‚R.png");
			back[5][3] = LoadGraph("dat/img/r–ì/r–ì‚U|‚Q.png");
			back[5][4] = LoadGraph("dat/img/r–ì/r–ì‚U|‚P.png");

			back[6][0] = 0;
			back[6][1] = LoadGraph("dat/img/r–ì/r–ì‚V|‚S.png");
			back[6][2] = LoadGraph("dat/img/r–ì/r–ì‚V|‚R.png");
			back[6][3] = LoadGraph("dat/img/r–ì/r–ì‚V|‚Q.png");
			back[6][4] = LoadGraph("dat/img/r–ì/r–ì‚V|‚P.png");
	
			back[7][0] = LoadGraph("dat/img/r–ì/r–ì‚W|‚T.png");
			back[7][1] = LoadGraph("dat/img/r–ì/r–ì‚W|‚S.png");
			back[7][2] = LoadGraph("dat/img/r–ì/r–ì‚W|‚R.png");
			back[7][3] = LoadGraph("dat/img/r–ì/r–ì‚W|‚Q.png");
			back[7][4] = LoadGraph("dat/img/r–ì/r–ì‚W|‚P.png");


			
			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/Å‰‚Ì‹’“_.png");
	
			g_castle[1][0] = LoadGraph("dat/img/Vé/r–ì/r–ì‚P“Gé‚P.png");
			g_castle[1][1] = LoadGraph("dat/img/Vé/r–ì/r–ì‚P“Gé‚Q.png");
			g_castle[1][2] = LoadGraph("dat/img/Vé/r–ì/r–ì‚P–¡•ûé.png");
	
			g_castle[2][0] = LoadGraph("dat/img/Vé/r–ì/r–ì‚Q“Gé‚P.png");
			g_castle[2][1] = LoadGraph("dat/img/Vé/r–ì/r–ì‚Q“Gé‚Q.png");
			g_castle[2][2] = LoadGraph("dat/img/Vé/r–ì/r–ì‚Q–¡•ûé.png");
	
			g_castle[3][0] = LoadGraph("dat/img/Vé/r–ì/r–ì‚R“Gé‚P.png");
			g_castle[3][1] = LoadGraph("dat/img/Vé/r–ì/r–ì‚R“Gé‚Q.png");
			g_castle[3][2] = LoadGraph("dat/img/Vé/r–ì/r–ì‚R–¡•ûé.png");
	
			g_castle[4][0] = LoadGraph("dat/img/Vé/r–ì/r–ì‚S“Gé‚P.png");
			g_castle[4][1] = LoadGraph("dat/img/Vé/r–ì/r–ì‚S“Gé‚Q.png");
			g_castle[4][2] = LoadGraph("dat/img/Vé/r–ì/r–ì‚S–¡•ûé.png");
	
			g_castle[5][0] = LoadGraph("dat/img/Vé/r–ì/r–ì‚T“Gé‚P.png");
			g_castle[5][1] = LoadGraph("dat/img/Vé/r–ì/r–ì‚T“Gé‚Q.png");
			g_castle[5][2] = LoadGraph("dat/img/Vé/r–ì/r–ì‚T–¡•ûé.png");
	
			g_castle[6][0] = LoadGraph("dat/img/Vé/r–ì/r–ì‚U“Gé‚P.png");
			g_castle[6][1] = LoadGraph("dat/img/Vé/r–ì/r–ì‚U“Gé‚P.png");
			g_castle[6][2] = LoadGraph("dat/img/Vé/r–ì/r–ì‚U–¡•ûé.png");
	
			g_castle[7][0] = LoadGraph("dat/img/Vé/r–ì/r–ì‚V“Gé‚P.png");
			g_castle[7][1] = LoadGraph("dat/img/Vé/r–ì/r–ì‚V“Gé‚Q.png");
			g_castle[7][2] = LoadGraph("dat/img/Vé/r–ì/r–ì‚V–¡•ûé.png");
			{
				string shiro_icon_name[]={
					"pic/first_ufo",
					"pic/wild_s1",
					"pic/wild_s2",
					"pic/wild_s3",
					"pic/wild_s4",
					"pic/wild_s5",
					"pic/wild_s6",
					"pic/wild_s7",
					"pic/wild_s8",
				};
				for(int i=0;i<array_length(shiro_icon_name);i++){
					g_shiro_icon[i][0]= LoadGraph((shiro_icon_name[i]+"_1.png").c_str());
					g_shiro_icon[i][1]= LoadGraph((shiro_icon_name[i]+"_2.png").c_str());
				}
			}

			LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/ƒXƒ`[ƒ€ƒpƒ“ƒNƒƒ{•à‚«.png", ANI_STEAM_W, 3, 3, WID_STEAM, HEI_STEAM, g_steam_w);
			LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/ƒXƒ`[ƒ€ƒpƒ“ƒNƒƒ{UŒ‚.png", ANI_STEAM_A, 4, 4, WID_STEAM, HEI_STEAM, g_steam_a);
			LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/r–ì/ƒXƒ`[ƒ€ƒpƒ“ƒNƒƒ{•œ‹A.png", ANI_STEAM_F, ANI_STEAM_F, 1, WID_STEAM, HEI_STEAM, g_steam_f);


			break;
		case 4:
			back[0][0] = LoadGraph("dat/img/áŒ´/áŒ´‚P-5.png");
			back[0][1] = LoadGraph("dat/img/áŒ´/áŒ´‚P-4.png");
			back[0][2] = LoadGraph("dat/img/áŒ´/áŒ´‚P-3.png");
			back[0][3] = LoadGraph("dat/img/áŒ´/áŒ´‚P-2.png");
			back[0][4] = LoadGraph("dat/img/áŒ´/áŒ´‚P-1.png");

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/áŒ´/áŒ´‚Q|‚S.png");
			back[1][2] = LoadGraph("dat/img/áŒ´/áŒ´‚Q|‚R.png");
			back[1][3] = LoadGraph("dat/img/áŒ´/áŒ´‚Q|‚Q.png");
			back[1][4] = LoadGraph("dat/img/áŒ´/áŒ´‚Q|‚P.png");

			back[2][0] = LoadGraph("dat/img/áŒ´/áŒ´‚R|‚T.png");
			back[2][1] = LoadGraph("dat/img/áŒ´/áŒ´‚R|‚S.png");
			back[2][2] = LoadGraph("dat/img/áŒ´/áŒ´‚R|‚R.png");
			back[2][3] = LoadGraph("dat/img/áŒ´/áŒ´‚R|‚Q.png");
			back[2][4] = LoadGraph("dat/img/áŒ´/áŒ´‚R|‚P.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/áŒ´/áŒ´‚S|‚S.png");
			back[3][2] = LoadGraph("dat/img/áŒ´/áŒ´‚S|‚R.png");
			back[3][3] = LoadGraph("dat/img/áŒ´/áŒ´‚S|‚Q.png");
			back[3][4] = LoadGraph("dat/img/áŒ´/áŒ´‚S|‚P.png");

			back[4][0] = 0;
			back[4][1] = LoadGraph("dat/img/áŒ´/áŒ´‚T|‚S.png");
			back[4][2] = LoadGraph("dat/img/áŒ´/áŒ´‚T|‚R.png");
			back[4][3] = LoadGraph("dat/img/áŒ´/áŒ´‚T|‚Q.png");
			back[4][4] = LoadGraph("dat/img/áŒ´/áŒ´‚T|‚P.png");

			back[5][0] = LoadGraph("dat/img/áŒ´/áŒ´‚U|‚T.png");
			back[5][1] = LoadGraph("dat/img/áŒ´/áŒ´‚U|‚S.png");
			back[5][2] = LoadGraph("dat/img/áŒ´/áŒ´‚U|‚R.png");
			back[5][3] = LoadGraph("dat/img/áŒ´/áŒ´‚U|‚Q.png");
			back[5][4] = LoadGraph("dat/img/áŒ´/áŒ´‚U|‚P.png");
			
			
			back[6][0] = 0;
			back[6][1] = LoadGraph("dat/img/áŒ´/áŒ´‚V|‚S.png");
			back[6][2] = LoadGraph("dat/img/áŒ´/áŒ´‚V|‚R.png");
			back[6][3] = LoadGraph("dat/img/áŒ´/áŒ´‚V|‚Q.png");
			back[6][4] = LoadGraph("dat/img/áŒ´/áŒ´‚V|‚P.png");

			back[7][0] = 0;
			back[7][1] = LoadGraph("dat/img/áŒ´/áŒ´‚W|‚S.png");
			back[7][2] = LoadGraph("dat/img/áŒ´/áŒ´‚W|‚R.png");
			back[7][3] = LoadGraph("dat/img/áŒ´/áŒ´‚W|‚Q.png");
			back[7][4] = LoadGraph("dat/img/áŒ´/áŒ´‚W|‚P.png");

			
			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/Å‰‚Ì‹’“_.png");
	
			g_castle[1][0] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚P“Gé‚P.png");
			g_castle[1][1] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚P“Gé‚Q.png");
			g_castle[1][2] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚P–¡•ûé.png");
	
			g_castle[2][0] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚Q“Gé‚P.png");
			g_castle[2][1] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚Q“Gé‚Q.png");
			g_castle[2][2] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚Q–¡•ûé.png");
	
			g_castle[3][0] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚R“Gé‚P.png");
			g_castle[3][1] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚R“Gé‚Q.png");
			g_castle[3][2] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚R–¡•ûé.png");
	
			g_castle[4][0] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚S“Gé‚P.png");
			g_castle[4][1] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚S“Gé‚Q.png");
			g_castle[4][2] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚S–¡•ûé.png");
	
			g_castle[5][0] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚T“Gé‚P.png");
			g_castle[5][1] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚T“Gé‚Q.png");
			g_castle[5][2] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚T–¡•ûé.png");
	
			g_castle[6][0] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚U“Gé‚P.png");
			g_castle[6][1] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚U“Gé‚P.png");
			g_castle[6][2] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚U–¡•ûé.png");
	
			g_castle[7][0] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚V“Gé‚P.png");
			g_castle[7][1] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚V“Gé‚Q.png");
			g_castle[7][2] = LoadGraph("dat/img/Vé/áŒ´/áŒ´‚V–¡•ûé.png");
			{
				string shiro_icon_name[]={
					"pic/first_ufo",
					"pic/snow_s1",
					"pic/snow_s2",
					"pic/snow_s3",
					"pic/snow_s4",
					"pic/snow_s5",
					"pic/snow_s6",
					"pic/snow_s7",
					"pic/snow_s8",
				};
				for(int i=0;i<array_length(shiro_icon_name);i++){
					g_shiro_icon[i][0]= LoadGraph((shiro_icon_name[i]+"_1.png").c_str());
					g_shiro_icon[i][1]= LoadGraph((shiro_icon_name[i]+"_2.png").c_str());
				}
			}


			break;
		case 2:
			back[0][0] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚P|‚T.png");
			back[0][1] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚P|‚S.png");
			back[0][2] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚P|‚R.png");
			back[0][3] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚P|‚Q.png");
			back[0][4] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚P|‚P.png");
			

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚Q|‚S.png");
			back[1][2] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚Q|‚R.png");
			back[1][3] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚Q|‚Q.png");
			back[1][4] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚Q|‚P.png");

			back[2][0] = 0;
			back[2][1] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚R|‚S.png");
			back[2][2] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚R|‚R.png");
			back[2][3] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚R|‚Q.png");
			back[2][4] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚R|‚P.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚S|‚S.png");
			back[3][2] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚S|‚R.png");
			back[3][3] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚S|‚Q.png");
			back[3][4] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚S|‚P.png");

			back[4][0] = 0;
			back[4][1] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚T|‚S.png");
			back[4][2] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚T|‚R.png");
			back[4][3] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚T|‚Q.png");
			back[4][4] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚T|‚P.png");

			back[5][0] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚U|‚T.png");
			back[5][1] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚U|‚S.png");
			back[5][2] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚U|‚R.png");
			back[5][3] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚U|‚Q.png");
			back[5][4] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚U|‚P.png");
			
			
			back[6][0] = 0;
			back[6][1] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚V|‚S.png");
			back[6][2] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚V|‚R.png");
			back[6][3] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚V|‚Q.png");
			back[6][4] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚V|‚P.png");

			back[7][0] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚W|‚T.png");
			back[7][1] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚W|‚S.png");
			back[7][2] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚W|‚R.png");
			back[7][3] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚W|‚Q.png");
			back[7][4] = LoadGraph("dat/img/‰_‚Ìã/‰_‚Ìã‚W|‚P.png");
			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/Å‰‚Ì‹’“_.png");
	
			g_castle[1][0] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚P“Gé‚P.png");
			g_castle[1][1] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚P“Gé‚Q.png");
			g_castle[1][2] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚P–¡•ûé.png");
	
			g_castle[2][0] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚Q“Gé‚P.png");
			g_castle[2][1] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚Q“Gé‚Q.png");
			g_castle[2][2] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚Q–¡•ûé.png");
	
			g_castle[3][0] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚R“Gé‚P.png");
			g_castle[3][1] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚R“Gé‚Q.png");
			g_castle[3][2] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚R–¡•ûé.png");
	
			g_castle[4][0] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚S“Gé‚P.png");
			g_castle[4][1] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚S“Gé‚Q.png");
			g_castle[4][2] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚S–¡•ûé.png");
	
			g_castle[5][0] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚T“Gé‚P.png");
			g_castle[5][1] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚T“Gé‚Q.png");
			g_castle[5][2] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚T–¡•ûé.png");
	
			g_castle[6][0] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚U“Gé‚P.png");
			g_castle[6][1] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚U“Gé‚P.png");
			g_castle[6][2] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚U–¡•ûé.png");
	
			g_castle[7][0] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚V“Gé‚P.png");
			g_castle[7][1] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚V“Gé‚Q.png");
			g_castle[7][2] = LoadGraph("dat/img/Vé/‰_‚Ìã/‰_‚Ìã‚V–¡•ûé.png");
			{
				string shiro_icon_name[]={
					"pic/first_ufo",
					"pic/cloud_s1",
					"pic/cloud_s2",
					"pic/cloud_s3",
					"pic/cloud_s4",
					"pic/cloud_s5",
					"pic/cloud_s6",
					"pic/cloud_s7",
					"pic/cloud_s8",
				};
				for(int i=0;i<array_length(shiro_icon_name);i++){
					g_shiro_icon[i][0]= LoadGraph((shiro_icon_name[i]+"_1.png").c_str());
					g_shiro_icon[i][1]= LoadGraph((shiro_icon_name[i]+"_2.png").c_str());
				}
			}

			break;
		case 5:
			back[0][0] = 0;
			back[0][1] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚P|‚S.png");
			back[0][2] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚P|‚R.png");
			back[0][3] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚P|‚Q.png");
			back[0][4] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚P|‚P.png");
			

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚Q|‚S.png");
			back[1][2] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚Q|‚R.png");
			back[1][3] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚Q|‚Q.png");
			back[1][4] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚Q|‚P.png");

			back[2][0] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚R|‚T.png");
			back[2][1] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚R|‚S.png");
			back[2][2] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚R|‚R.png");
			back[2][3] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚R|‚Q.png");
			back[2][4] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚R|‚P.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚S|‚S.png");
			back[3][2] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚S|‚R.png");
			back[3][3] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚S|‚Q.png");
			back[3][4] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚S|‚P.png");

			back[4][0] = 0;
			back[4][1] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚T|‚S.png");
			back[4][2] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚T|‚R.png");
			back[4][3] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚T|‚Q.png");
			back[4][4] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚T|‚P.png");

			back[5][0] = 0;
			back[5][1] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚U|‚S.png");
			back[5][2] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚U|‚R.png");
			back[5][3] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚U|‚Q.png");
			back[5][4] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚U|‚P.png");
			
			
			back[6][0] = 0;
			back[6][1] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚V|‚S.png");
			back[6][2] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚V|‚R.png");
			back[6][3] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚V|‚Q.png");
			back[6][4] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚V|‚P.png");

			back[7][0] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚W|‚T.png");
			back[7][1] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚W|‚S.png");
			back[7][2] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚W|‚R.png");
			back[7][3] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚W|‚Q.png");
			back[7][4] = LoadGraph("dat/img/XƒK[ƒ‹/XƒK[ƒ‹‚W|‚P.png");

			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/Å‰‚Ì‹’“_.png");
	
			g_castle[1][0] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚P“Gé‚P.png");
			g_castle[1][1] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚P“Gé2.png");
			g_castle[1][2] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚P–¡•ûé.png");
	
			g_castle[2][0] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚Q“Gé‚P.png");
			g_castle[2][1] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚Q“Gé2.png");
			g_castle[2][2] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚Q–¡•ûé.png");
	
			g_castle[3][0] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚R“Gé‚P.png");
			g_castle[3][1] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚R“Gé2.png");
			g_castle[3][2] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚R–¡•ûé.png");
	
			g_castle[4][0] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚S“Gé‚P.png");
			g_castle[4][1] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚S“Gé2.png");
			g_castle[4][2] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚S–¡•ûé.png");
	
			g_castle[5][0] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚T“Gé‚P.png");
			g_castle[5][1] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚T“Gé2.png");
			g_castle[5][2] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚T–¡•ûé.png");
	
			g_castle[6][0] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚U“Gé‚P.png");
			g_castle[6][1] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚U“Gé2.png");
			g_castle[6][2] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚U–¡•ûé.png");
	
			g_castle[7][0] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚V“Gé‚P.png");
			g_castle[7][1] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚V“Gé‚Q.png");
			g_castle[7][2] = LoadGraph("dat/img/Vé/XƒK[ƒ‹/XƒK[ƒ‹‚V–¡•ûé.png");
			{
				string shiro_icon_name[]={
					"pic/first_ufo",
					"pic/forest_s1",
					"pic/forest_s2",
					"pic/forest_s3",
					"pic/forest_s4",
					"pic/forest_s5",
					"pic/forest_s6",
					"pic/forest_s7",
					"pic/forest_s8",
				};
				for(int i=0;i<array_length(shiro_icon_name);i++){
					g_shiro_icon[i][0]= LoadGraph((shiro_icon_name[i]+"_1.png").c_str());
					g_shiro_icon[i][1]= LoadGraph((shiro_icon_name[i]+"_2.png").c_str());
				}
			}

			LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/XƒK[ƒ‹/‹Ê‚Ë‚¬‘Ò‹@.png", ANI_TAMANEGI_WA, 4, 1, WID_TAMANEGI, HEI_TAMANEGI, g_tamanegi_w);
			LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/XƒK[ƒ‹/‹Ê‚Ë‚¬UŒ‚.png", ANI_TAMANEGI_WA, 4, 1, WID_TAMANEGI, HEI_TAMANEGI, g_tamanegi_a);
			LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/XƒK[ƒ‹/‹Ê‚Ë‚¬ƒgƒ‰ƒ“ƒXƒtƒH[ƒ€.png", ANI_TAMANEGI_T, 4, 3, WID_TAMANEGI, HEI_TAMANEGI, g_tamanegi_t);
			LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/XƒK[ƒ‹/‹Ê‚Ë‚¬reƒgƒ‰ƒ“ƒXƒtƒH[ƒ€.png", ANI_TAMANEGI_TR, 6, 1, WID_TAMANEGI, HEI_TAMANEGI, g_tamanegi_tr);


			break;
		case 3:
			back[0][0] = 0;
			back[0][1] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚P|‚S.png");
			back[0][2] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚P|‚R.png");
			back[0][3] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚P|‚Q.png");
			back[0][4] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚P|‚P.png");

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚Q|‚S.png");
			back[1][2] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚Q|‚R.png");
			back[1][3] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚Q|‚Q.png");
			back[1][4] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚Q|‚P.png");

			back[2][0] = 0;
			back[2][1] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚R|‚S.png");
			back[2][2] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚R|‚R.png");
			back[2][3] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚R|‚Q.png");
			back[2][4] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚R|‚P.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚S|‚S.png");
			back[3][2] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚S|‚R.png");
			back[3][3] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚S|‚Q.png");
			back[3][4] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚S|‚P.png");

			back[4][0] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚T|‚T.png");
			back[4][1] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚T|‚S.png");
			back[4][2] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚T|‚R.png");
			back[4][3] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚T|‚Q.png");
			back[4][4] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚T|‚P.png");

			back[5][0] = 0;
			back[5][1] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚U|‚S.png");
			back[5][2] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚U|‚R.png");
			back[5][3] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚U|‚Q.png");
			back[5][4] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚U|‚P.png");
			
			
			back[6][0] = 0;
			back[6][1] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚V|‚S.png");
			back[6][2] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚V|‚R.png");
			back[6][3] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚V|‚Q.png");
			back[6][4] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚V|‚P.png");

			back[7][0] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚W|‚T.png");
			back[7][1] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚W|‚S.png");
			back[7][2] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚W|‚R.png");
			back[7][3] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚W|‚Q.png");
			back[7][4] = LoadGraph("dat/img/…‚Ì’†/…‚Ì’†‚W|‚P.png");

			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/Å‰‚Ì‹’“_.png");
	
			g_castle[1][0] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚P“Gé‚P.png");
			g_castle[1][1] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚P“Gé‚Q.png");
			g_castle[1][2] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚P–¡•ûé.png");
	
			g_castle[2][0] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚Q“Gé‚P.png");
			g_castle[2][1] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚Q“Gé‚Q.png");
			g_castle[2][2] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚Q–¡•ûé.png");
	
			g_castle[3][0] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚R“Gé‚P.png");
			g_castle[3][1] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚R“Gé‚Q.png");
			g_castle[3][2] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚R–¡•ûé.png");
	
			g_castle[4][0] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚S“Gé‚P.png");
			g_castle[4][1] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚S“Gé‚Q.png");
			g_castle[4][2] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚S–¡•ûé.png");
	
			g_castle[5][0] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚T“Gé‚P.png");
			g_castle[5][1] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚T“Gé‚Q.png");
			g_castle[5][2] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚T–¡•ûé.png");
	
			g_castle[6][0] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚U“Gé‚P.png");
			g_castle[6][1] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚U“Gé‚P.png");
			g_castle[6][2] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚U–¡•ûé.png");
	
			g_castle[7][0] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚V“Gé‚P.png");
			g_castle[7][1] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚V“Gé‚Q.png");
			g_castle[7][2] = LoadGraph("dat/img/Vé/…‚Ì’†/…‚Ì’†‚V–¡•ûé.png");
			{
				string shiro_icon_name[]={
					"pic/first_ufo",
					"pic/water_s1",
					"pic/water_s2",
					"pic/water_s3",
					"pic/water_s4",
					"pic/water_s5",
					"pic/water_s6",
					"pic/water_s7",
					"pic/water_s8",
				};
				for(int i=0;i<array_length(shiro_icon_name);i++){
					g_shiro_icon[i][0]= LoadGraph((shiro_icon_name[i]+"_1.png").c_str());
					g_shiro_icon[i][1]= LoadGraph((shiro_icon_name[i]+"_2.png").c_str());
				}
			}

			LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/…’ê‚Ì‹ô‘œ‘Ò‹@.png", ANI_GUUZO_W, 4, 1, WID_GUUZO, HEI_GUUZO, g_guuzo_w);
			LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/…’ê‚Ì‹ô‘œUŒ‚1.png", ANI_GUUZO_A, 2, 1, WID_GUUZO, HEI_GUUZO, g_guuzo_a1);
			LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/…‚Ì’†/…’ê‚Ì‹ô‘œUŒ‚2.png", ANI_GUUZO_A, 2, 1, WID_GUUZO, HEI_GUUZO, g_guuzo_a2);


			break;
		case 6:
			back[0][0] = 0;
			back[0][1] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚P|‚S.png");
			back[0][2] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚P|‚R.png");
			back[0][3] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚P|‚Q.png");
			back[0][4] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚P|‚P.png");

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚Q|‚S.png");
			back[1][2] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚Q|‚R.png");
			back[1][3] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚Q|‚Q.png");
			back[1][4] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚Q|‚P.png");

			back[2][0] = 0;
			back[2][1] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚R|‚S.png");
			back[2][2] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚R|‚R.png");
			back[2][3] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚R|‚Q.png");
			back[2][4] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚R|‚P.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚S|‚S.png");
			back[3][2] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚S|‚R.png");
			back[3][3] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚S|‚Q.png");
			back[3][4] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚S|‚P.png");

			back[4][0] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚T|‚T.png");
			back[4][1] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚T|‚S.png");
			back[4][2] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚T|‚R.png");
			back[4][3] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚T|‚Q.png");
			back[4][4] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚T|‚P.png");

			back[5][0] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚U|‚T.png");
			back[5][1] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚U|‚S.png");
			back[5][2] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚U|‚R.png");
			back[5][3] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚U|‚Q.png");
			back[5][4] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚U|‚P.png");
			
			
			back[6][0] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚V|‚T.png");
			back[6][1] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚V|‚S.png");
			back[6][2] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚V|‚R.png");
			back[6][3] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚V|‚Q.png");
			back[6][4] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚V|‚P.png");

			back[7][0] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB8-5.png");
			back[7][1] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB8-4.png");
			back[7][2] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB8-3.png");
			back[7][3] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB8-2.png");
			back[7][4] = LoadGraph("dat/img/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB8-1.png");

			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/Å‰‚Ì‹’“_.png");
	
			g_castle[1][0] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚P“Gé1.png");
			g_castle[1][1] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚P“Gé2.png");
			g_castle[1][2] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚P–¡•ûé.png");
	
			g_castle[2][0] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚Q“Gé‚P.png");
			g_castle[2][1] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚Q“Gé‚Q.png");
			g_castle[2][2] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚Q–¡•ûé.png");
	
			g_castle[3][0] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚R“Gé1.png");
			g_castle[3][1] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚R“Gé2.png");
			g_castle[3][2] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚R–¡•ûé.png");
	
			g_castle[4][0] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚S“Gé1.png");
			g_castle[4][1] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚S“Gé2.png");
			g_castle[4][2] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚S–¡•ûé.png");
	
			g_castle[5][0] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚T“Gé1.png");
			g_castle[5][1] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚T“Gé2.png");
			g_castle[5][2] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚T–¡•ûé.png");
	
			g_castle[6][0] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚U“Gé1.png");
			g_castle[6][1] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚U“Gé2.png");
			g_castle[6][2] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚U–¡•ûé.png");
	
			g_castle[7][0] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚V“Gé1.png");
			g_castle[7][1] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚V“Gé2.png");
			g_castle[7][2] = LoadGraph("dat/img/Vé/ƒƒJƒVƒeƒB/ƒƒJƒVƒeƒB‚V–¡•ûé.png");
			{
				string shiro_icon_name[]={
					"pic/first_ufo",
					"pic/meka_s1",
					"pic/meka_s2",
					"pic/meka_s3",
					"pic/meka_s4",
					"pic/meka_s5",
					"pic/meka_s6",
					"pic/meka_s7",
					"pic/meka_s8",
				};
				for(int i=0;i<array_length(shiro_icon_name);i++){
					g_shiro_icon[i][0]= LoadGraph((shiro_icon_name[i]+"_1.png").c_str());
					g_shiro_icon[i][1]= LoadGraph((shiro_icon_name[i]+"_2.png").c_str());
				}
			}

			LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/ƒƒJƒVƒeƒB/‚­‚ë‚¢‚µ‚İw.png", ANI_KUROSHIMI_W, ANI_KUROSHIMI_W, 1, WID_KUROSHIMI, HEI_KUROSHIMI, g_kuroshimi_w);
			LoadDivGraph("dat/img/“Gƒ†ƒjƒbƒg/ƒƒJƒVƒeƒB/‚­‚ë‚¢‚µ‚İa.png", ANI_KUROSHIMI_A, ANI_KUROSHIMI_A, 1, WID_KUROSHIMI, HEI_KUROSHIMI, g_kuroshimi_a);


			break;

		default:
			printfDx("initStageERROR!!");
			break;
		}
		SetUseASyncLoadFlag( FALSE ); // ”ñ“¯Šú“Ç‚İ‚İƒtƒ‰ƒOON
	}

	void Images::releaseStage(){
			
		
		for(int i=0;i<8;i++){
			for(int j=0;j<5;j++){
				DeleteGraph(back[i][j]);
			}
		}

		for(int i=0;i<9;i++){
			for(int j=0;j<3;j++){
				DeleteGraph(g_castle[i][j]);
			}
		}

	
	}

	string Images::getStageSummary(int sid){
	
		string s[]={
		"",
		"‚©‚Â‚Ä‚±‚Ì’n‚Åí‘ˆ‚ª‚ ‚Á‚½",
		"UFO‚Í‰_‚É‚Ô‚Â‚©‚é",
		"…—¤—¼—pUFO",
		"R‚Ì‰œ‚É‚Íå‚ªö‚ñ‚Å‚¢‚é‚Æ‚¢‚¤",
		"¡—q‚ÍXƒK[ƒ‹‚ª”M‚¢I",
		"ŒÌ‹½"	};
	return s[sid];
}

	
	string Images::getStageName(int sid){
	
		string s[]={
		"",
		"r–ì",
		"‰_‚Ìã",
		"…’†",
		"áŒ´",
		"X—Ñ",
		"‹@ŠBŠX"	};
	return s[sid];
}
