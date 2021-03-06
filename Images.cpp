#include"Images.h"
#include "DxLib.h"
#include<map>
#include <string>
#include <iostream>
#include"CsvReader.h"
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

	SetUseASyncLoadFlag( FALSE ); // 非同期読み込みフラグOFF
	//タイトルに使うものたちよ
	filelist.push_back("pic/title.png");
	filelist.push_back("pic/定刻ぼるけーの.png");
	
	
		
	filelist.push_back("pic/test.jpg");
	filelist.push_back("pic/black.jpg");
	
	blend=LoadBlendGraph("pic/blend.jpg");
	

		
	for(auto s:filelist){
		gs[s]=LoadGraph(s.c_str());

	}	





	SetUseASyncLoadFlag( TRUE ); // 非同期読み込みフラグON
	

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

	LoadDivGraph("dat/img/むすめユニット/幼女w2.png",ANI_YOUJO_W,ANI_YOUJO_W,1,WID_YOUJO,HEI_YOUJO,g_youjo_w);
	LoadDivGraph("dat/img/むすめユニット/幼女d2.png", ANI_YOUJO_D, ANI_YOUJO_D, 1, WID_YOUJO, HEI_YOUJO, g_youjo_d);
	LoadDivGraph("dat/img/むすめユニット/幼女j2.png", ANI_YOUJO_A, ANI_YOUJO_A/2, 2, WID_YOUJO, HEI_YOUJO, g_youjo_a);

	LoadDivGraph("dat/img/むすめユニット/盾篭りw.png", ANI_TATEKO_W, ANI_TATEKO_W, 1, WID_TATEKO, HEI_TATEKO, g_tateko_w);
	LoadDivGraph("dat/img/むすめユニット/盾篭りa.png", ANI_TATEKO_A, ANI_TATEKO_A, 1, WID_TATEKO, HEI_TATEKO, g_tateko_a);

	LoadDivGraph("dat/img/むすめユニット/姫騎士てこ入れ/姫騎士w3.png", ANI_HIME_W, ANI_HIME_W, 1, WID_HIME_W, HEI_HIME, g_hime_w);
	LoadDivGraph("dat/img/むすめユニット/姫騎士てこ入れ/姫騎士a3.png", ANI_HIME_A, ANI_HIME_A, 1, WID_HIME_A, HEI_HIME, g_hime_a);
	LoadDivGraph("dat/img/むすめユニット/姫騎士てこ入れ/姫騎士オーラ.png", ANI_HIME_O, ANI_HIME_O, 1, WID_HIME_O, HEI_HIME_O, g_hime_o);
	LoadDivGraph("dat/img/むすめユニット/姫騎士てこ入れ/姫騎士チャージ.png", ANI_HIME_C, ANI_HIME_C, 1, WID_HIME_C, HEI_HIME_C, g_hime_c);
	LoadDivGraph("dat/img/むすめユニット/姫騎士てこ入れ/姫騎士攻撃終了.png", ANI_HIME_AE, ANI_HIME_AE, 1, WID_HIME_AE, HEI_HIME_AE, g_hime_ae);
	LoadDivGraph("dat/img/むすめユニット/姫騎士てこ入れ/大衆宝具.png", ANI_HIME_H, 1,ANI_HIME_H, WID_HIME_H, HEI_HIME_H, g_hime_h);
	LoadDivGraph("dat/img/むすめユニット/姫騎士てこ入れ/大衆宝具発動中.png", ANI_HIME_HC, ANI_HIME_HC, 1, WID_HIME_HC, HEI_HIME_HC, g_hime_hc);



	LoadDivGraph("dat/img/むすめユニット/イカロスw2.png", ANI_IKAROS_W, ANI_IKAROS_W, 1, WID_IKAROS_W, HEI_IKAROS, g_ikaros_w);
	LoadDivGraph("dat/img/むすめユニット/イカロスa2.png", ANI_IKAROS_A, ANI_IKAROS_A, 1, WID_IKAROS_A, HEI_IKAROS, g_ikaros_a);

	LoadDivGraph("dat/img/むすめユニット/マジョw2.png", ANI_MAJO_W, ANI_MAJO_W, 1, WID_MAJO_W, HEI_MAJO, g_majo_w);
	LoadDivGraph("dat/img/むすめユニット/マジョa2.png", ANI_MAJO_A, ANI_MAJO_A, 1, WID_MAJO_A, HEI_MAJO, g_majo_a);
	LoadDivGraph("dat/img/むすめユニット/魔女てこ入れ/魔女ソウルの矢.png", ANI_MAHOU, 5, 2, WID_MAHOU, HEI_MAHOU, g_mahou);

	LoadDivGraph("dat/img/むすめユニット/農家w.png", ANI_NOUKA_W, ANI_NOUKA_W, 1, WID_NOUKA_W, HEI_NOUKA, g_nouka_w);
	LoadDivGraph("dat/img/むすめユニット/農家s.png", ANI_NOUKA_A, 4, 4, WID_NOUKA_A, HEI_NOUKA, g_nouka_a1);
	LoadDivGraph("dat/img/むすめユニット/農家m.png", ANI_NOUKA_A, 4, 4, WID_NOUKA_A, HEI_NOUKA, g_nouka_a2);

	LoadDivGraph("dat/img/敵ユニット/荒野/ガジガジメカw.png", ANI_GAJIGAJI_W, ANI_GAJIGAJI_W, 1, WID_GAJIGAJI, HEI_GAJIGAJI_W, g_gajigaji_w[0]);
	LoadDivGraph("dat/img/敵ユニット/荒野/ガジガジメカa.png", ANI_GAJIGAJI_A, ANI_GAJIGAJI_A, 1, WID_GAJIGAJI, HEI_GAJIGAJI_A, g_gajigaji_a[0]);
	LoadDivGraph("dat/img/敵ユニット/荒野/ガジガジメカ2w.png", ANI_GAJIGAJI_W, ANI_GAJIGAJI_W, 1, WID_GAJIGAJI, HEI_GAJIGAJI_W, g_gajigaji_w[1]);
	LoadDivGraph("dat/img/敵ユニット/荒野/ガジガジメカ2a.png", ANI_GAJIGAJI_A, ANI_GAJIGAJI_A, 1, WID_GAJIGAJI, HEI_GAJIGAJI_A, g_gajigaji_a[1]);
	LoadDivGraph("dat/img/敵ユニット/荒野/ガジガジメカ3w.png", ANI_GAJIGAJI_W, ANI_GAJIGAJI_W, 1, WID_GAJIGAJI, HEI_GAJIGAJI_W, g_gajigaji_w[2]);
	LoadDivGraph("dat/img/敵ユニット/荒野/ガジガジメカ3a.png", ANI_GAJIGAJI_A, ANI_GAJIGAJI_A, 1, WID_GAJIGAJI, HEI_GAJIGAJI_A, g_gajigaji_a[2]);

	LoadDivGraph("dat/img/敵ユニット/荒野/車輪砲台w.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_w[0]);
	LoadDivGraph("dat/img/敵ユニット/荒野/車輪砲台a1.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_a[0]);
	LoadDivGraph("dat/img/敵ユニット/荒野/車輪砲台2w.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_w[1]);
	LoadDivGraph("dat/img/敵ユニット/荒野/車輪砲台2a.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_a[1]);
	LoadDivGraph("dat/img/敵ユニット/荒野/車輪砲台3w.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_w[2]);
	LoadDivGraph("dat/img/敵ユニット/荒野/車輪砲台3a.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_a[2]);

	LoadDivGraph("dat/img/敵ユニット/雪原/ゴレーム1s.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_w[0]);
	LoadDivGraph("dat/img/敵ユニット/雪原/ゴレーム1a.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_a[0]);
	LoadDivGraph("dat/img/敵ユニット/雪原/ゴレーム2s.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_w[1]);
	LoadDivGraph("dat/img/敵ユニット/雪原/ゴレーム2a.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_a[1]);
	LoadDivGraph("dat/img/敵ユニット/雪原/ゴレーム3s.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_w[2]);
	LoadDivGraph("dat/img/敵ユニット/雪原/ゴレーム3a.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_a[2]);

	LoadDivGraph("dat/img/敵ユニット/雪原/ビーバーw.png", ANI_BEEBAR_W, ANI_BEEBAR_W, 1, WID_BEEBAR_W, HEI_BEEBAR_W, g_beebar_w[0]);
	LoadDivGraph("dat/img/敵ユニット/雪原/ビーバーa.png", ANI_BEEBAR_A, ANI_BEEBAR_A, 1, WID_BEEBAR_A, HEI_BEEBAR_A, g_beebar_a[0]);
	LoadDivGraph("dat/img/敵ユニット/雪原/ビーバー2w.png", ANI_BEEBAR_W, ANI_BEEBAR_W, 1, WID_BEEBAR_W, HEI_BEEBAR_W, g_beebar_w[1]);
	LoadDivGraph("dat/img/敵ユニット/雪原/ビーバー2a.png", ANI_BEEBAR_A, ANI_BEEBAR_A, 1, WID_BEEBAR_A, HEI_BEEBAR_A, g_beebar_a[1]);
	LoadDivGraph("dat/img/敵ユニット/雪原/ビーバー3w.png", ANI_BEEBAR_W, ANI_BEEBAR_W, 1, WID_BEEBAR_W, HEI_BEEBAR_W, g_beebar_w[2]);
	LoadDivGraph("dat/img/敵ユニット/雪原/ビーバー3a.png", ANI_BEEBAR_A, ANI_BEEBAR_A, 1, WID_BEEBAR_A, HEI_BEEBAR_A, g_beebar_a[2]);

	

	LoadDivGraph("dat/img/敵ユニット/雲の上/モノリス1w.png", ANI_MONORIS_W, ANI_MONORIS_W, 1, WID_MONORIS, HEI_MONORIS, g_monoris_w[0]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/モノリス1a1.png", ANI_MONORIS_A1, ANI_MONORIS_A1, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a1[0]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/モノリス1a2.png", ANI_MONORIS_A2, ANI_MONORIS_A2, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a2[0]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/モノリス2w.png", ANI_MONORIS_W, ANI_MONORIS_W, 1, WID_MONORIS, HEI_MONORIS, g_monoris_w[1]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/モノリス2a1.png", ANI_MONORIS_A1, ANI_MONORIS_A1, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a1[1]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/モノリス2a2.png", ANI_MONORIS_A2, ANI_MONORIS_A2, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a2[1]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/モノリス3w.png", ANI_MONORIS_W, ANI_MONORIS_W, 1, WID_MONORIS, HEI_MONORIS, g_monoris_w[2]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/モノリス3a1.png", ANI_MONORIS_A1, ANI_MONORIS_A1, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a1[2]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/モノリス3a2.png", ANI_MONORIS_A2, ANI_MONORIS_A2, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a2[2]);

	LoadDivGraph("dat/img/敵ユニット/雲の上/発電雲１歩く.png", ANI_DENGUMO_W, ANI_DENGUMO_W, 1, WID_DENGUMO, HEI_DENGUMO, g_dengumo_w[0]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/発電雲１攻撃.png", ANI_DENGUMO_A, 5 , 3, WID_DENGUMO, HEI_DENGUMO, g_dengumo_a[0]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/発電雲２歩く.png", ANI_DENGUMO_W, ANI_DENGUMO_W, 1, WID_DENGUMO, HEI_DENGUMO, g_dengumo_w[1]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/発電雲２攻撃.png", ANI_DENGUMO_A, 5, 3, WID_DENGUMO, HEI_DENGUMO, g_dengumo_a[1]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/発電雲３歩く.png", ANI_DENGUMO_W, ANI_DENGUMO_W, 1, WID_DENGUMO, HEI_DENGUMO, g_dengumo_w[2]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/発電雲３攻撃.png", ANI_DENGUMO_A, 5, 3, WID_DENGUMO, HEI_DENGUMO, g_dengumo_a[2]);

	LoadDivGraph("dat/img/敵ユニット/雲の上/ビームエフェクト1.png", ANI_MONOBEAM, ANI_MONOBEAM, 1, WID_MONOBEAM, HEI_MONOBEAM, g_monobeam[0]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/ビームエフェクト2.png", ANI_MONOBEAM, ANI_MONOBEAM, 1, WID_MONOBEAM, HEI_MONOBEAM, g_monobeam[1]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/ビームエフェクト3.png", ANI_MONOBEAM, ANI_MONOBEAM, 1, WID_MONOBEAM, HEI_MONOBEAM, g_monobeam[2]);

	LoadDivGraph("dat/img/敵ユニット/雲の上/雷１.png", ANI_DENKAMI, 1, ANI_DENKAMI, WID_DENKAMI, HEI_DENKAMI, g_denkami[0]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/雷2.png", ANI_DENKAMI, 1, ANI_DENKAMI, WID_DENKAMI, HEI_DENKAMI, g_denkami[1]);
	LoadDivGraph("dat/img/敵ユニット/雲の上/雷3.png", ANI_DENKAMI, 1, ANI_DENKAMI, WID_DENKAMI, HEI_DENKAMI, g_denkami[2]);


	LoadDivGraph("dat/img/敵ユニット/水の中/潜航艇1w.png", ANI_SENKOU_W, ANI_SENKOU_W, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_w[0]);
	LoadDivGraph("dat/img/敵ユニット/水の中/潜航艇1a.png", ANI_SENKOU_A, ANI_SENKOU_A, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_a[0]);
	LoadDivGraph("dat/img/敵ユニット/水の中/潜航艇2w.png", ANI_SENKOU_W, ANI_SENKOU_W, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_w[1]);
	LoadDivGraph("dat/img/敵ユニット/水の中/潜航艇2a.png", ANI_SENKOU_A, ANI_SENKOU_A, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_a[1]);
	LoadDivGraph("dat/img/敵ユニット/水の中/潜航艇3w.png", ANI_SENKOU_W, ANI_SENKOU_W, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_w[2]);
	LoadDivGraph("dat/img/敵ユニット/水の中/潜航艇3a.png", ANI_SENKOU_A, ANI_SENKOU_A, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_a[2]);

	LoadDivGraph("dat/img/敵ユニット/水の中/魚雷1.png", ANI_GYORAI, ANI_GYORAI, 1, WID_GYORAI, HEI_GYORAI, g_gyorai[0]);
	LoadDivGraph("dat/img/敵ユニット/水の中/魚雷2.png", ANI_GYORAI, ANI_GYORAI, 1, WID_GYORAI, HEI_GYORAI, g_gyorai[1]);
	LoadDivGraph("dat/img/敵ユニット/水の中/魚雷3.png", ANI_GYORAI, ANI_GYORAI, 1, WID_GYORAI, HEI_GYORAI, g_gyorai[2]);


	LoadDivGraph("dat/img/敵ユニット/水の中/謎の触手１出現.png", ANI_SHOKUSH_S, 5, 3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_s[0]);
	LoadDivGraph("dat/img/敵ユニット/水の中/謎の触手1攻撃.png", ANI_SHOKUSH_A, 3,3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_a[0]);
	LoadDivGraph("dat/img/敵ユニット/水の中/謎の触手2出現.png", ANI_SHOKUSH_S, 5,3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_s[1]);
	LoadDivGraph("dat/img/敵ユニット/水の中/謎の触手2攻撃.png", ANI_SHOKUSH_A, 3,3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_a[1]);
	LoadDivGraph("dat/img/敵ユニット/水の中/謎の触手3出現.png", ANI_SHOKUSH_S, 5,3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_s[2]);
	LoadDivGraph("dat/img/敵ユニット/水の中/謎の触手3攻撃.png", ANI_SHOKUSH_A, 3,3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_a[2]);

	LoadDivGraph("dat/img/敵ユニット/水の中/謎の触手1キラキラ.png", ANI_KIRAKIRA, 6,2, WID_KIRAKIRA, HEI_KIRAKIRA, g_kirakira[0]);
	LoadDivGraph("dat/img/敵ユニット/水の中/謎の触手2キラキラ.png", ANI_KIRAKIRA, 6,2, WID_KIRAKIRA, HEI_KIRAKIRA, g_kirakira[1]);
	LoadDivGraph("dat/img/敵ユニット/水の中/謎の触手3キラキラ.png", ANI_KIRAKIRA, 6,2, WID_KIRAKIRA, HEI_KIRAKIRA, g_kirakira[2]);

	
	LoadDivGraph("dat/img/敵ユニット/森ガール/お花砲台1出現.png", ANI_OHANA_S, 4, 4, WID_OHANA, HEI_OHANA, g_ohana_s[0]);
	LoadDivGraph("dat/img/敵ユニット/森ガール/お花砲台1攻撃.png", ANI_OHANA_A, 3, 3, WID_OHANA, HEI_OHANA, g_ohana_a[0]);
	LoadDivGraph("dat/img/敵ユニット/森ガール/お花砲台2出現.png", ANI_OHANA_S, 4, 4, WID_OHANA, HEI_OHANA, g_ohana_s[1]);
	LoadDivGraph("dat/img/敵ユニット/森ガール/お花砲台2攻撃.png", ANI_OHANA_A, 3, 3, WID_OHANA, HEI_OHANA, g_ohana_a[1]);
	LoadDivGraph("dat/img/敵ユニット/森ガール/お花砲台3出現.png", ANI_OHANA_S, 4, 4, WID_OHANA, HEI_OHANA, g_ohana_s[2]);
	LoadDivGraph("dat/img/敵ユニット/森ガール/お花砲台3攻撃.png", ANI_OHANA_A, 3, 3, WID_OHANA, HEI_OHANA, g_ohana_a[2]);

	LoadDivGraph("dat/img/敵ユニット/森ガール/玉ねぎミサイル1.png", ANI_NEGIMISSILE, 2, 1, WID_NEGIMISSILE, HEI_NEGIMISSILE, g_negimissile[2]);
	LoadDivGraph("dat/img/敵ユニット/森ガール/玉ねぎミサイル2.png", ANI_NEGIMISSILE, 2, 1, WID_NEGIMISSILE, HEI_NEGIMISSILE, g_negimissile[1]);
	LoadDivGraph("dat/img/敵ユニット/森ガール/玉ねぎミサイル3.png", ANI_NEGIMISSILE, 2, 1, WID_NEGIMISSILE, HEI_NEGIMISSILE, g_negimissile[0]);


	LoadDivGraph("dat/img/むすめユニット/花ｓ.png", ANI_HANA, 5, 5, WID_HANA, HEI_HANA, g_hana);

	LoadDivGraph("dat/img/爆弾.png", ANI_BOMB, ANI_BOMB, 1, WID_BOMB, HEI_BOMB, g_bomb);
	LoadDivGraph("dat/img/爆発E.png", ANI_EXP, 6, 2, WID_EXP, HEI_EXP, g_exp);
	LoadDivGraph("dat/img/死亡時爆発.png", ANI_NOMALEXP, ANI_NOMALEXP, 1, WID_NOMALEXP, HEI_NOMALEXP, g_nomalExp);

	LoadDivGraph("dat/img/特大爆発エフェクト.png", ANI_BIGEXP, 5, 3, WID_BIGEXP, HEI_BIGEXP, g_bigexp);

	LoadDivGraph("dat/img/衝撃波.png", ANI_SHOCK, ANI_SHOCK, 1, WID_SHOCK, HEI_SHOCK, g_shock);
	LoadDivGraph("dat/img/ミサイル.png", ANI_MISSILE, ANI_MISSILE, 1, WID_MISSILE, HEI_MISSILE, g_missile);
	LoadDivGraph("dat/img/テポドン.png", ANI_TEPODON, ANI_TEPODON, 1, WID_TEPODON, HEI_TEPODON, g_tepodon);
	LoadDivGraph("dat/img/ビーム発射中.png", ANI_BEAM, 1,ANI_BEAM, WID_BEAM, HEI_BEAM, g_beam);
	LoadDivGraph("dat/img/ビームチャージ中.png", ANI_BEAM_C, ANI_BEAM_C, 1, WID_BEAM_C, HEI_BEAM_C, g_beam_c);


	LoadDivGraph("dat/img/敵ユニット/雪原/ゴレムの声.png", ANI_GVOICE, ANI_GVOICE, 1, WID_GVOICE, HEI_GVOICE, g_gvoice);

	LoadDivGraph("dat/img/銃被弾時e.png", ANI_GUNSHOT, ANI_GUNSHOT, 1, WID_GUNSHOT, HEI_GUNSHOT, g_gunshot);
	LoadDivGraph("dat/img/砲弾被弾時e.png", ANI_CANNONSHOT, ANI_CANNONSHOT, 1, WID_CANNONSHOT, HEI_CANNONSHOT, g_cannonshot);

	LoadDivGraph("dat/img/敵ユニット/荒野/かみつきエフェクト.png", ANI_GAJIKAMI, ANI_GAJIKAMI, 1, WID_GAJIKAMI, HEI_GAJIKAMI, g_gajikami);
	LoadDivGraph("dat/img/敵ユニット/雲の上/ビーム被弾１.png", ANI_MONOB_H, ANI_MONOB_H, 1, WID_MONOB_H, HEI_MONOB_H, g_monob_h);
	LoadDivGraph("dat/img/むすめユニット/魔方陣.png", ANI_MAHOJIN, 5, 4, WID_MAHOJIN, HEI_MAHOJIN, g_mahojin);
	LoadDivGraph("dat/img/むすめユニット/斬撃エフェクト1.png", ANI_ZANGEKI, ANI_ZANGEKI, 1, WID_ZANGEKI, HEI_ZANGEKI, g_zangeki);


	LoadDivGraph("dat/img/闇の世界/e2a1.png", 8, 8, 1, 96, 450, g_e_yamidrop[0]);
	LoadDivGraph("dat/img/闇の世界/e2a2.png", 8, 8, 1, 96, 450, g_e_yamidrop[1]);
	LoadDivGraph("dat/img/闇の世界/e2a3.png", 8, 8, 1, 96, 450, g_e_yamidrop[2]);

	LoadDivGraph("dat/img/闇の世界/ea1.png", 7, 7, 1, 155, 168, g_e_wisp[0]);
	LoadDivGraph("dat/img/闇の世界/ea2.png", 7, 7, 1, 155, 168, g_e_wisp[1]);
	LoadDivGraph("dat/img/闇の世界/ea3.png", 7, 7, 1, 155, 168, g_e_wisp[2]);

	LoadDivGraph("dat/img/水の中/水の中気泡.png", ANI_BUBBLE, ANI_BUBBLE, 1, WID_BUBBLE, HEI_BUBBLE, g_e_bubble);


	houdai_yama = LoadGraph("dat/img/山/山城砲台.png");
	/*
*/



	g_mekahaikyo=LoadGraph("dat/img/メカ廃墟.png");

	



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

	filelist.push_back("pic/資源.png");

	
	filelist.push_back("pic/HP.png");
	filelist.push_back("pic/攻撃速度.png");
	filelist.push_back("pic/資源ダウン.png");
	filelist.push_back("pic/生産速度.png");
	filelist.push_back("pic/速さ.png");
	filelist.push_back("pic/防御.png");
	filelist.push_back("pic/力.png");

	filelist.push_back("pic/HP2.png");
	filelist.push_back("pic/攻撃速度2.png");
	filelist.push_back("pic/資源ダウン2.png");
	filelist.push_back("pic/生産速度2.png");
	filelist.push_back("pic/速さ2.png");
	filelist.push_back("pic/防御2.png");
	filelist.push_back("pic/力2.png");

	
	filelist.push_back("pic/ワールドマップa.png");
	filelist.push_back("pic/ワールドマップb.png");
	filelist.push_back("pic/ワールドマップc.png");
	filelist.push_back("pic/ワールドマップd.png");
	filelist.push_back("pic/ワールドマップe.png");
	filelist.push_back("pic/ワールドマップf.png");
	
	filelist.push_back("pic/ワールドマップg.png");

	
	filelist.push_back("pic/出撃前ユニット選択ウインドウ.png");
	filelist.push_back("pic/出撃前ユニット選択ウインドウ選ぶ用.png");
	filelist.push_back("pic/出撃ボタンON.png");
	filelist.push_back("pic/出撃ボタンOFF.png");
	
	filelist.push_back("pic/出撃ボタンNO.png");
	filelist.push_back("pic/world_stage.png");

	filelist.push_back("pic/stage_ss_1.png");
	filelist.push_back("pic/stage_ss_2.png");
	filelist.push_back("pic/stage_ss_3.png");
	filelist.push_back("pic/stage_ss_4.png");
	filelist.push_back("pic/stage_ss_5.png");
	filelist.push_back("pic/stage_ss_6.png");
	
	filelist.push_back("pic/ワールドマップg.png");



	filelist.push_back("pic/生産中止a.png");
	filelist.push_back("pic/生産中止a2.png");
	filelist.push_back("pic/MUI.png");

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
	filelist.push_back("pic/CUSTUM.png");
	filelist.push_back("pic/CUSTUMon.png");
	//ポップアップウインドウ.png
	filelist.push_back("pic/ポップアップウインドウ.png");
	filelist.push_back("pic/ポップアップ歯車.png");


	for(auto s:filelist){
		if (gs.count(s) == 0)
			gs[s]=LoadGraph(s.c_str());

	}	

	SetUseASyncLoadFlag( FALSE ); // 非同期読み込みフラグOFF
	font=CreateFontToHandle( "メイリオ" , 13 , 5 ,DX_FONTTYPE_ANTIALIASING_EDGE_4X4) ;
	
	font2=CreateFontToHandle( "メイリオ" , 30 , 5 ,DX_FONTTYPE_ANTIALIASING_EDGE_4X4) ;

	/*文字列リソース読み込み */
	auto res = CsvReader::parseTableDX("dat/文字リソース.csv", ",");

	pramSummary = res.at(0);
	pramName = res.at(1);
	unitName = res.at(2);
	unitSummary = res.at(3);
	unitTarget = res.at(4);

	auto data = CsvReader::parseTableDX("dat/ステージ情報.csv", ",");
	stageName = data.at(0);
	stageSummary = data.at(1);
	

	auto data1 = CsvReader::parseTableDX("dat/ステージごとキャラ表.csv", ",");
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < data1.at(i).size(); j++){
			unitByStage[i].push_back(stoi(data1.at(i).at(j)));
		}
		
	}
	
}

	void Images::init(){ins.load();}
	Images* Images::getIns(){return &ins;}

	int Images::get(const char name[]){return ins.gs[string(name)];}


	


	int Images::getMusumeIcon(int id,boolean dfalse){
		string hoge[]={
			"pic/生産中止a",
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
			"pic/力",
			"pic/HP",
			"pic/速さ",
			"pic/防御",
			"",
			"pic/生産速度",
			"pic/資源ダウン",
			"pic/攻撃速度",
		};
		
		return ins.get((hoge[i]+(dfalse?"2":"")+".png").c_str());

	}


	void Images::loadStage(int sid){
		


		SetUseASyncLoadFlag( TRUE ); // 非同期読み込みフラグON
		switch (sid)
		{
		case 1:
			{
					  int stage_back_ismove[8][5] =
					  {
						  { 0, 1, 0, 0, 0 },
						  { 0, 1, 0, 0, 0 },
						  { 0, 1, 0, 0, 0 },
						  { 0, 1, 0, 0, 0 },
						  { 1, 0, 0, 0, 0 },
						  { 0, 1, 0, 0, 0 },
						  { 0, 1, 0, 0, 0 },
						  { 1, 0, 0, 0, 0 },
					  };
					  for (int i = 0; i < 8; i++){
						  for (int j = 0; j < 5; j++){
							  back_ismove[i][j] = (stage_back_ismove[i][j] );
						  }
					  }

					  int stage_drawgap[9][3] =
					  {
						{0,0,20},
						{62,-16,-16}, 
						{25,30,-70}, 
						{5,5,0}, 
						{0,0,0},  
						{0,0,0}, 
						{0,0,0}, 
						{0,0,0}, 
						{0,0,0}
					  };
					  for (int i = 0; i < 9; i++){
						  for (int j = 0; j < 3; j++){
							  draw_gap[i][j] = stage_drawgap[i][j];
						  }
					  }
					  
			}
			back[0][0] = 0;
			back[0][1] = LoadGraph("dat/img/荒野/荒野１−４.png");
			back[0][2] = LoadGraph("dat/img/荒野/荒野１−３.png");
			back[0][3] = LoadGraph("dat/img/荒野/荒野１−２.png");
			back[0][4] = LoadGraph("dat/img/荒野/荒野１−１.png");

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/荒野/荒野１．５−４.png");
			back[1][2] = LoadGraph("dat/img/荒野/荒野１．５−３.png");
			back[1][3] = LoadGraph("dat/img/荒野/荒野１．５−２.png");
			back[1][4] = LoadGraph("dat/img/荒野/荒野１．５−１.png");

			back[2][0] = 0;
			back[2][1] = LoadGraph("dat/img/荒野/荒野２−４.png");
			back[2][2] = LoadGraph("dat/img/荒野/荒野２−３.png");
			back[2][3] = LoadGraph("dat/img/荒野/荒野２−２.png");
			back[2][4] = LoadGraph("dat/img/荒野/荒野２−１.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/荒野/荒野３−４.png");
			back[3][2] = LoadGraph("dat/img/荒野/荒野３−３.png");
			back[3][3] = LoadGraph("dat/img/荒野/荒野３−２.png");
			back[3][4] = LoadGraph("dat/img/荒野/荒野３−１.png");

			back[4][0] = LoadGraph("dat/img/荒野/荒野５−５.png");
			back[4][1] = LoadGraph("dat/img/荒野/荒野５−４.png");
			back[4][2] = LoadGraph("dat/img/荒野/荒野５−３.png");
			back[4][3] = LoadGraph("dat/img/荒野/荒野５−２.png");
			back[4][4] = LoadGraph("dat/img/荒野/荒野５−１.png");

			back[5][0] = 0;
			back[5][1] = LoadGraph("dat/img/荒野/荒野６−４.png");
			back[5][2] = LoadGraph("dat/img/荒野/荒野６−３.png");
			back[5][3] = LoadGraph("dat/img/荒野/荒野６−２.png");
			back[5][4] = LoadGraph("dat/img/荒野/荒野６−１.png");

			back[6][0] = 0;
			back[6][1] = LoadGraph("dat/img/荒野/荒野７−４.png");
			back[6][2] = LoadGraph("dat/img/荒野/荒野７−３.png");
			back[6][3] = LoadGraph("dat/img/荒野/荒野７−２.png");
			back[6][4] = LoadGraph("dat/img/荒野/荒野７−１.png");
	
			back[7][0] = LoadGraph("dat/img/荒野/荒野８−５.png");
			back[7][1] = LoadGraph("dat/img/荒野/荒野８−４.png");
			back[7][2] = LoadGraph("dat/img/荒野/荒野８−３.png");
			back[7][3] = LoadGraph("dat/img/荒野/荒野８−２.png");
			back[7][4] = LoadGraph("dat/img/荒野/荒野８−１.png");


			
			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/最初の拠点.png");
	
			g_castle[1][0] = LoadGraph("dat/img/新城/荒野/荒野１敵城１.png");
			g_castle[1][1] = LoadGraph("dat/img/新城/荒野/荒野１敵城２.png");
			g_castle[1][2] = LoadGraph("dat/img/新城/荒野/荒野１味方城.png");
	
			g_castle[2][0] = LoadGraph("dat/img/新城/荒野/荒野２敵城１.png");
			g_castle[2][1] = LoadGraph("dat/img/新城/荒野/荒野２敵城２.png");
			g_castle[2][2] = LoadGraph("dat/img/新城/荒野/荒野２味方城.png");
	
			g_castle[3][0] = LoadGraph("dat/img/新城/荒野/荒野３敵城１.png");
			g_castle[3][1] = LoadGraph("dat/img/新城/荒野/荒野３敵城２.png");
			g_castle[3][2] = LoadGraph("dat/img/新城/荒野/荒野３味方城.png");
	
			g_castle[4][0] = LoadGraph("dat/img/新城/荒野/荒野４敵城１.png");
			g_castle[4][1] = LoadGraph("dat/img/新城/荒野/荒野４敵城２.png");
			g_castle[4][2] = LoadGraph("dat/img/新城/荒野/荒野４味方城.png");
	
			g_castle[5][0] = LoadGraph("dat/img/新城/荒野/荒野５敵城１.png");
			g_castle[5][1] = LoadGraph("dat/img/新城/荒野/荒野５敵城２.png");
			g_castle[5][2] = LoadGraph("dat/img/新城/荒野/荒野５味方城.png");
	
			g_castle[6][0] = LoadGraph("dat/img/新城/荒野/荒野６敵城１.png");
			g_castle[6][1] = LoadGraph("dat/img/新城/荒野/荒野６敵城１.png");
			g_castle[6][2] = LoadGraph("dat/img/新城/荒野/荒野６味方城.png");
	
			g_castle[7][0] = LoadGraph("dat/img/新城/荒野/荒野７敵城１.png");
			g_castle[7][1] = LoadGraph("dat/img/新城/荒野/荒野７敵城２.png");
			g_castle[7][2] = LoadGraph("dat/img/新城/荒野/荒野７味方城.png");
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

			LoadDivGraph("dat/img/敵ユニット/荒野/スチームパンクロボ歩き.png", ANI_STEAM_W, 3, 3, WID_STEAM, HEI_STEAM, g_steam_w);
			LoadDivGraph("dat/img/敵ユニット/荒野/スチームパンクロボ攻撃.png", ANI_STEAM_A, 4, 4, WID_STEAM, HEI_STEAM, g_steam_a);
			LoadDivGraph("dat/img/敵ユニット/荒野/スチームパンクロボ復帰.png", ANI_STEAM_F, ANI_STEAM_F, 1, WID_STEAM, HEI_STEAM, g_steam_f);


			break;
		case 4:
			{
					  int stage_back_ismove[8][5] =
					  {
						  { 1, 0, 0, 0, 0 },
						  { 0, 1, 0, 0, 0 },
						  { 1, 0, 0, 0, 0 },
						  { 0, 1, 0, 1, 0 },
						  { 0, 0, 1, 0, 0 },
						  { 0, 0, 0, 0, 0 },
						  { 1, 0, 0, 0, 0 },
						  { 0, 1, 1, 1, 0 },
					  };
					  for (int i = 0; i < 8; i++){
						  for (int j = 0; j < 5; j++){
							  back_ismove[i][j] = (stage_back_ismove[i][j] );
						  }
					  }
					   int stage_drawgap[9][3] =
					  {
						{0,0,20},
						{20,20,-20}, 
						{10,10,-70}, 
						{5,5,0}, 
						{0,0,0},  
						{200,200,200}, 
						{0,0,0}, 
						{50,50,0}, 
						{0,0,0}
					  };
					  for (int i = 0; i < 9; i++){
						  for (int j = 0; j < 3; j++){
							  draw_gap[i][j] = stage_drawgap[i][j];
						  }
					  }
			}
			back[0][0] = LoadGraph("dat/img/雪原/雪原１-5.png");
			back[0][1] = LoadGraph("dat/img/雪原/雪原１-4.png");
			back[0][2] = LoadGraph("dat/img/雪原/雪原１-3.png");
			back[0][3] = LoadGraph("dat/img/雪原/雪原１-2.png");
			back[0][4] = LoadGraph("dat/img/雪原/雪原１-1.png");

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/雪原/雪原２−４.png");
			back[1][2] = LoadGraph("dat/img/雪原/雪原２−３.png");
			back[1][3] = LoadGraph("dat/img/雪原/雪原２−２.png");
			back[1][4] = LoadGraph("dat/img/雪原/雪原２−１.png");

			back[2][0] = LoadGraph("dat/img/雪原/雪原３−５.png");
			back[2][1] = LoadGraph("dat/img/雪原/雪原３−４.png");
			back[2][2] = LoadGraph("dat/img/雪原/雪原３−３.png");
			back[2][3] = LoadGraph("dat/img/雪原/雪原３−２.png");
			back[2][4] = LoadGraph("dat/img/雪原/雪原３−１.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/雪原/雪原４−４.png");
			back[3][2] = LoadGraph("dat/img/雪原/雪原４−３.png");
			back[3][3] = LoadGraph("dat/img/雪原/雪原４−２.png");
			back[3][4] = LoadGraph("dat/img/雪原/雪原４−１.png");

			back[4][0] = 0;
			back[4][1] = LoadGraph("dat/img/雪原/雪原５−４.png");
			back[4][2] = LoadGraph("dat/img/雪原/雪原５−３.png");
			back[4][3] = LoadGraph("dat/img/雪原/雪原５−２.png");
			back[4][4] = LoadGraph("dat/img/雪原/雪原５−１.png");

			back[5][0] = LoadGraph("dat/img/雪原/雪原６−５.png");
			back[5][1] = LoadGraph("dat/img/雪原/雪原６−４.png");
			back[5][2] = LoadGraph("dat/img/雪原/雪原６−３.png");
			back[5][3] = LoadGraph("dat/img/雪原/雪原６−２.png");
			back[5][4] = LoadGraph("dat/img/雪原/雪原６−１.png");
			
			
			back[6][0] = 0;
			back[6][1] = LoadGraph("dat/img/雪原/雪原７−４.png");
			back[6][2] = LoadGraph("dat/img/雪原/雪原７−３.png");
			back[6][3] = LoadGraph("dat/img/雪原/雪原７−２.png");
			back[6][4] = LoadGraph("dat/img/雪原/雪原７−１.png");

			back[7][0] = 0;
			back[7][1] = LoadGraph("dat/img/雪原/雪原８−４.png");
			back[7][2] = LoadGraph("dat/img/雪原/雪原８−３.png");
			back[7][3] = LoadGraph("dat/img/雪原/雪原８−２.png");
			back[7][4] = LoadGraph("dat/img/雪原/雪原８−１.png");

			
			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/最初の拠点.png");
	
			g_castle[1][0] = LoadGraph("dat/img/新城/雪原/雪原１敵城１.png");
			g_castle[1][1] = LoadGraph("dat/img/新城/雪原/雪原１敵城２.png");
			g_castle[1][2] = LoadGraph("dat/img/新城/雪原/雪原１味方城.png");
	
			g_castle[2][0] = LoadGraph("dat/img/新城/雪原/雪原２敵城１.png");
			g_castle[2][1] = LoadGraph("dat/img/新城/雪原/雪原２敵城２.png");
			g_castle[2][2] = LoadGraph("dat/img/新城/雪原/雪原２味方城.png");
	
			g_castle[3][0] = LoadGraph("dat/img/新城/雪原/雪原３敵城１.png");
			g_castle[3][1] = LoadGraph("dat/img/新城/雪原/雪原３敵城２.png");
			g_castle[3][2] = LoadGraph("dat/img/新城/雪原/雪原３味方城.png");
	
			g_castle[4][0] = LoadGraph("dat/img/新城/雪原/雪原４敵城１.png");
			g_castle[4][1] = LoadGraph("dat/img/新城/雪原/雪原４敵城２.png");
			g_castle[4][2] = LoadGraph("dat/img/新城/雪原/雪原４味方城.png");
	
			g_castle[5][0] = LoadGraph("dat/img/新城/雪原/雪原５敵城１.png");
			g_castle[5][1] = LoadGraph("dat/img/新城/雪原/雪原５敵城２.png");
			g_castle[5][2] = LoadGraph("dat/img/新城/雪原/雪原５味方城.png");
	
			g_castle[6][0] = LoadGraph("dat/img/新城/雪原/雪原６敵城１.png");
			g_castle[6][1] = LoadGraph("dat/img/新城/雪原/雪原６敵城１.png");
			g_castle[6][2] = LoadGraph("dat/img/新城/雪原/雪原６味方城.png");
	
			g_castle[7][0] = LoadGraph("dat/img/新城/雪原/雪原７敵城１.png");
			g_castle[7][1] = LoadGraph("dat/img/新城/雪原/雪原７敵城２.png");
			g_castle[7][2] = LoadGraph("dat/img/新城/雪原/雪原７味方城.png");
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

			LoadDivGraph("dat/img/敵ユニット/雪原/さいはてa1.png", ANI_SAIHATE_A, 1, ANI_SAIHATE_A, WID_SAIHATE_A_R, HEI_SAIHATE, g_saihate_a_r);
			LoadDivGraph("dat/img/敵ユニット/雪原/さいはてa2.png", ANI_SAIHATE_A, ANI_SAIHATE_A, 1, WID_SAIHATE, HEI_SAIHATE_A_S, g_saihate_a_s);
			LoadDivGraph("dat/img/敵ユニット/雪原/さいはてt.png", ANI_SAIHATE_T, ANI_SAIHATE_T, 1, WID_SAIHATE, HEI_SAIHATE, g_saihate_t);
			LoadDivGraph("dat/img/敵ユニット/雪原/さいはてh.png", ANI_SAIHATE_H, 3, 3, WID_SAIHATE, HEI_SAIHATE, g_saihate_h);

			LoadDivGraph("dat/img/敵ユニット/雪原/ゆきだま1.png", ANI_YUKIDAMA, 4, 2, WID_YUKIDAMA, HEI_YUKIDAMA, g_yukidama1);
			LoadDivGraph("dat/img/敵ユニット/雪原/ゆきだま2.png", ANI_YUKIDAMA, 4, 2, WID_YUKIDAMA, HEI_YUKIDAMA, g_yukidama2);

			break;
		case 2:
		{
				  int stage_back_ismove[8][5] =
				  {
					  { 1, 0, 0, 0, 0 },
					  { 0, 0, 1, 1, 0 },
					  { 0, 1, 0, 0, 0 },
					  { 0, 0, 1, 1, 0 },
					  { 0, 0, 1, 1, 0 },
					  { 0, 0, 1, 1, 0 },
					  { 0, 0, 0, 0, 0 },
					  { 0, 1, 0, 0, 0 },
				  };
				  for (int i = 0; i < 8; i++){
					  for (int j = 0; j < 5; j++){
						  back_ismove[i][j] = (stage_back_ismove[i][j] );
					  }
				  }
					  int stage_drawgap[9][3] =
					  {
						{0,0,20},
						{-16,-16,-16}, 
						{25,30,-70}, 
						{5,5,0}, 
						{0,0,0},  
						{0,0,0}, 
						{0,0,0}, 
						{0,0,0}, 
						{0,0,0}
					  };
					  for (int i = 0; i < 9; i++){
						  for (int j = 0; j < 3; j++){
							  draw_gap[i][j] = stage_drawgap[i][j];
						  }
					  }
		}
			back[0][0] = LoadGraph("dat/img/雲の上/雲の上１−５.png");
			back[0][1] = LoadGraph("dat/img/雲の上/雲の上１−４.png");
			back[0][2] = LoadGraph("dat/img/雲の上/雲の上１−３.png");
			back[0][3] = LoadGraph("dat/img/雲の上/雲の上１−２.png");
			back[0][4] = LoadGraph("dat/img/雲の上/雲の上１−１.png");
			

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/雲の上/雲の上２−４.png");
			back[1][2] = LoadGraph("dat/img/雲の上/雲の上２−３.png");
			back[1][3] = LoadGraph("dat/img/雲の上/雲の上２−２.png");
			back[1][4] = LoadGraph("dat/img/雲の上/雲の上２−１.png");

			back[2][0] = 0;
			back[2][1] = LoadGraph("dat/img/雲の上/雲の上３−４.png");
			back[2][2] = LoadGraph("dat/img/雲の上/雲の上３−３.png");
			back[2][3] = LoadGraph("dat/img/雲の上/雲の上３−２.png");
			back[2][4] = LoadGraph("dat/img/雲の上/雲の上３−１.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/雲の上/雲の上４−４.png");
			back[3][2] = LoadGraph("dat/img/雲の上/雲の上４−３.png");
			back[3][3] = LoadGraph("dat/img/雲の上/雲の上４−２.png");
			back[3][4] = LoadGraph("dat/img/雲の上/雲の上４−１.png");

			back[4][0] = 0;
			back[4][1] = LoadGraph("dat/img/雲の上/雲の上５−４.png");
			back[4][2] = LoadGraph("dat/img/雲の上/雲の上５−３.png");
			back[4][3] = LoadGraph("dat/img/雲の上/雲の上５−２.png");
			back[4][4] = LoadGraph("dat/img/雲の上/雲の上５−１.png");

			back[5][0] = LoadGraph("dat/img/雲の上/雲の上６−５.png");
			back[5][1] = LoadGraph("dat/img/雲の上/雲の上６−４.png");
			back[5][2] = LoadGraph("dat/img/雲の上/雲の上６−３.png");
			back[5][3] = LoadGraph("dat/img/雲の上/雲の上６−２.png");
			back[5][4] = LoadGraph("dat/img/雲の上/雲の上６−１.png");
			
			
			back[6][0] = 0;
			back[6][1] = LoadGraph("dat/img/雲の上/雲の上７−４.png");
			back[6][2] = LoadGraph("dat/img/雲の上/雲の上７−３.png");
			back[6][3] = LoadGraph("dat/img/雲の上/雲の上７−２.png");
			back[6][4] = LoadGraph("dat/img/雲の上/雲の上７−１.png");

			back[7][0] = LoadGraph("dat/img/雲の上/雲の上８−５.png");
			back[7][1] = LoadGraph("dat/img/雲の上/雲の上８−４.png");
			back[7][2] = LoadGraph("dat/img/雲の上/雲の上８−３.png");
			back[7][3] = LoadGraph("dat/img/雲の上/雲の上８−２.png");
			back[7][4] = LoadGraph("dat/img/雲の上/雲の上８−１.png");
			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/最初の拠点.png");
	
			g_castle[1][0] = LoadGraph("dat/img/新城/雲の上/雲の上１敵城１.png");
			g_castle[1][1] = LoadGraph("dat/img/新城/雲の上/雲の上１敵城２.png");
			g_castle[1][2] = LoadGraph("dat/img/新城/雲の上/雲の上１味方城.png");
	
			g_castle[2][0] = LoadGraph("dat/img/新城/雲の上/雲の上２敵城１.png");
			g_castle[2][1] = LoadGraph("dat/img/新城/雲の上/雲の上２敵城２.png");
			g_castle[2][2] = LoadGraph("dat/img/新城/雲の上/雲の上２味方城.png");
	
			g_castle[3][0] = LoadGraph("dat/img/新城/雲の上/雲の上３敵城１.png");
			g_castle[3][1] = LoadGraph("dat/img/新城/雲の上/雲の上３敵城２.png");
			g_castle[3][2] = LoadGraph("dat/img/新城/雲の上/雲の上３味方城.png");
	
			g_castle[4][0] = LoadGraph("dat/img/新城/雲の上/雲の上４敵城１.png");
			g_castle[4][1] = LoadGraph("dat/img/新城/雲の上/雲の上４敵城２.png");
			g_castle[4][2] = LoadGraph("dat/img/新城/雲の上/雲の上４味方城.png");
	
			g_castle[5][0] = LoadGraph("dat/img/新城/雲の上/雲の上５敵城１.png");
			g_castle[5][1] = LoadGraph("dat/img/新城/雲の上/雲の上５敵城２.png");
			g_castle[5][2] = LoadGraph("dat/img/新城/雲の上/雲の上５味方城.png");
	
			g_castle[6][0] = LoadGraph("dat/img/新城/雲の上/雲の上６敵城１.png");
			g_castle[6][1] = LoadGraph("dat/img/新城/雲の上/雲の上６敵城１.png");
			g_castle[6][2] = LoadGraph("dat/img/新城/雲の上/雲の上６味方城.png");
	
			g_castle[7][0] = LoadGraph("dat/img/新城/雲の上/雲の上７敵城１.png");
			g_castle[7][1] = LoadGraph("dat/img/新城/雲の上/雲の上７敵城２.png");
			g_castle[7][2] = LoadGraph("dat/img/新城/雲の上/雲の上７味方城.png");
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


			LoadDivGraph("dat/img/敵ユニット/雲の上/異界の門待機.png", ANI_IKAI_W, 4, 1, WID_IKAI, HEI_IKAI, g_ikai_w);
			LoadDivGraph("dat/img/敵ユニット/雲の上/異界の門攻撃1.png", ANI_IKAI_A1, 3, 1, WID_IKAI, HEI_IKAI, g_ikai_a1);
			LoadDivGraph("dat/img/敵ユニット/雲の上/異界の門攻撃2.png", ANI_IKAI_A2, 4, 1, WID_IKAI, HEI_IKAI, g_ikai_a2);

			LoadDivGraph("dat/img/敵ユニット/雲の上/ごみ1.png", ANI_GOMI, 6, 2, WID_GOMI, HEI_GOMI, g_gomi[0]);
			LoadDivGraph("dat/img/敵ユニット/雲の上/ごみ2.png", ANI_GOMI, 6, 2, WID_GOMI, HEI_GOMI, g_gomi[1]);
			LoadDivGraph("dat/img/敵ユニット/雲の上/ごみ3.png", ANI_GOMI, 6, 2, WID_GOMI, HEI_GOMI, g_gomi[2]);

			LoadDivGraph("dat/img/敵ユニット/いかずちE.png", ANI_IKAMINARI, 5, 2, WID_IKAMINARI, HEI_IKAMINARI, g_ikaminari);

			break;
		case 5:
		{
				  int stage_back_ismove[8][5] =
				  {
					  { 0, 1, 0, 0, 0 },
					  { 0, 1, 0, 0, 0 },
					  { 1, 1, 0, 0, 0 },
					  { 0, 1, 0, 0, 0 },
					  { 0, 0, 0, 0, 0 },
					  { 0, 1, 0, 0, 0 },
					  { 0, 0, 0, 0, 0 },
					  { 1, 0, 0, 0, 0 },
				  };
				  for (int i = 0; i < 8; i++){
					  for (int j = 0; j < 5; j++){
						  back_ismove[i][j] = (stage_back_ismove[i][j] );
					  }
				  }
					  int stage_drawgap[9][3] =
					  {
						{0,0,20},
						{0,0,0}, 
						{-20,-20,-70}, 
						{5,5,0}, 
						{0,0,0},  
						{0,0,0}, 
						{0,0,0}, 
						{0,0,0}, 
						{0,0,0}
					  };
					  for (int i = 0; i < 9; i++){
						  for (int j = 0; j < 3; j++){
							  draw_gap[i][j] = stage_drawgap[i][j];
						  }
					  }
		}
			back[0][0] = 0;
			back[0][1] = LoadGraph("dat/img/森ガール/森ガール１−４.png");
			back[0][2] = LoadGraph("dat/img/森ガール/森ガール１−３.png");
			back[0][3] = LoadGraph("dat/img/森ガール/森ガール１−２.png");
			back[0][4] = LoadGraph("dat/img/森ガール/森ガール１−１.png");
			

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/森ガール/森ガール２−４.png");
			back[1][2] = LoadGraph("dat/img/森ガール/森ガール２−３.png");
			back[1][3] = LoadGraph("dat/img/森ガール/森ガール２−２.png");
			back[1][4] = LoadGraph("dat/img/森ガール/森ガール２−１.png");

			back[2][0] = LoadGraph("dat/img/森ガール/森ガール３−５.png");
			back[2][1] = LoadGraph("dat/img/森ガール/森ガール３−４.png");
			back[2][2] = LoadGraph("dat/img/森ガール/森ガール３−３.png");
			back[2][3] = LoadGraph("dat/img/森ガール/森ガール３−２.png");
			back[2][4] = LoadGraph("dat/img/森ガール/森ガール３−１.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/森ガール/森ガール４−４.png");
			back[3][2] = LoadGraph("dat/img/森ガール/森ガール４−３.png");
			back[3][3] = LoadGraph("dat/img/森ガール/森ガール４−２.png");
			back[3][4] = LoadGraph("dat/img/森ガール/森ガール４−１.png");

			back[4][0] = 0;
			back[4][1] = LoadGraph("dat/img/森ガール/森ガール５−４.png");
			back[4][2] = LoadGraph("dat/img/森ガール/森ガール５−３.png");
			back[4][3] = LoadGraph("dat/img/森ガール/森ガール５−２.png");
			back[4][4] = LoadGraph("dat/img/森ガール/森ガール５−１.png");

			back[5][0] = 0;
			back[5][1] = LoadGraph("dat/img/森ガール/森ガール６−４.png");
			back[5][2] = LoadGraph("dat/img/森ガール/森ガール６−３.png");
			back[5][3] = LoadGraph("dat/img/森ガール/森ガール６−２.png");
			back[5][4] = LoadGraph("dat/img/森ガール/森ガール６−１.png");
			
			
			back[6][0] = 0;
			back[6][1] = LoadGraph("dat/img/森ガール/森ガール７−４.png");
			back[6][2] = LoadGraph("dat/img/森ガール/森ガール７−３.png");
			back[6][3] = LoadGraph("dat/img/森ガール/森ガール７−２.png");
			back[6][4] = LoadGraph("dat/img/森ガール/森ガール７−１.png");

			back[7][0] = LoadGraph("dat/img/森ガール/森ガール８−５.png");
			back[7][1] = LoadGraph("dat/img/森ガール/森ガール８−４.png");
			back[7][2] = LoadGraph("dat/img/森ガール/森ガール８−３.png");
			back[7][3] = LoadGraph("dat/img/森ガール/森ガール８−２.png");
			back[7][4] = LoadGraph("dat/img/森ガール/森ガール８−１.png");

			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/最初の拠点.png");
	
			g_castle[1][0] = LoadGraph("dat/img/新城/森ガール/森ガール１敵城１.png");
			g_castle[1][1] = LoadGraph("dat/img/新城/森ガール/森ガール１敵城2.png");
			g_castle[1][2] = LoadGraph("dat/img/新城/森ガール/森ガール１味方城.png");
	
			g_castle[2][0] = LoadGraph("dat/img/新城/森ガール/森ガール２敵城１.png");
			g_castle[2][1] = LoadGraph("dat/img/新城/森ガール/森ガール２敵城2.png");
			g_castle[2][2] = LoadGraph("dat/img/新城/森ガール/森ガール２味方城.png");
	
			g_castle[3][0] = LoadGraph("dat/img/新城/森ガール/森ガール３敵城１.png");
			g_castle[3][1] = LoadGraph("dat/img/新城/森ガール/森ガール３敵城2.png");
			g_castle[3][2] = LoadGraph("dat/img/新城/森ガール/森ガール３味方城.png");
	
			g_castle[4][0] = LoadGraph("dat/img/新城/森ガール/森ガール４敵城１.png");
			g_castle[4][1] = LoadGraph("dat/img/新城/森ガール/森ガール４敵城2.png");
			g_castle[4][2] = LoadGraph("dat/img/新城/森ガール/森ガール４味方城.png");
	
			g_castle[5][0] = LoadGraph("dat/img/新城/森ガール/森ガール５敵城１.png");
			g_castle[5][1] = LoadGraph("dat/img/新城/森ガール/森ガール５敵城2.png");
			g_castle[5][2] = LoadGraph("dat/img/新城/森ガール/森ガール５味方城.png");
	
			g_castle[6][0] = LoadGraph("dat/img/新城/森ガール/森ガール６敵城１.png");
			g_castle[6][1] = LoadGraph("dat/img/新城/森ガール/森ガール６敵城2.png");
			g_castle[6][2] = LoadGraph("dat/img/新城/森ガール/森ガール６味方城.png");
	
			g_castle[7][0] = LoadGraph("dat/img/新城/森ガール/森ガール７敵城１.png");
			g_castle[7][1] = LoadGraph("dat/img/新城/森ガール/森ガール７敵城２.png");
			g_castle[7][2] = LoadGraph("dat/img/新城/森ガール/森ガール７味方城.png");
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

			LoadDivGraph("dat/img/敵ユニット/森ガール/玉ねぎ待機.png", ANI_TAMANEGI_WA, 4, 1, WID_TAMANEGI, HEI_TAMANEGI, g_tamanegi_w);
			LoadDivGraph("dat/img/敵ユニット/森ガール/玉ねぎ攻撃.png", ANI_TAMANEGI_WA, 4, 1, WID_TAMANEGI, HEI_TAMANEGI, g_tamanegi_a);
			LoadDivGraph("dat/img/敵ユニット/森ガール/玉ねぎトランスフォーム.png", ANI_TAMANEGI_T, 4, 3, WID_TAMANEGI, HEI_TAMANEGI, g_tamanegi_t);
			LoadDivGraph("dat/img/敵ユニット/森ガール/玉ねぎreトランスフォーム.png", ANI_TAMANEGI_TR, 6, 1, WID_TAMANEGI, HEI_TAMANEGI, g_tamanegi_tr);


			break;
		case 3:
			{
					  int stage_back_ismove[8][5] =
					  {
						  { 0, 1, 0, 0, 0 },
						  { 0, 1, 0, 0, 0 },
						  { 0, 1, 666, 0, 0 },
						  { 0, 1, 0, 0, 0 },
						  { 1, 1, 0, 0, 0 },
						  { 0, 1, 0, 0, 0 },
						  { 0, 1, 0, 0, 0 },
						  { 0, 0, 0, 0, 0 },
					  };
					  for (int i = 0; i < 8; i++){
						  for (int j = 0; j < 5; j++){
							  back_ismove[i][j] = (stage_back_ismove[i][j] );
						  }
					  }
					  int stage_drawgap[9][3] =
					  {
						{0,0,20},
						{62,-16,-16}, 
						{25,30,-70}, 
						{5,5,0}, 
						{170,160,0},  
						{20,20,0}, 
						{0,0,0}, 
						{0,0,0}, 
						{0,0,0}
					  };
					  for (int i = 0; i < 9; i++){
						  for (int j = 0; j < 3; j++){
							  draw_gap[i][j] = stage_drawgap[i][j];
						  }
					  }
			}			
			back[0][0] = 0;
			back[0][1] = LoadGraph("dat/img/水の中/水の中１−４.png");
			back[0][2] = LoadGraph("dat/img/水の中/水の中１−３.png");
			back[0][3] = LoadGraph("dat/img/水の中/水の中１−２.png");
			back[0][4] = LoadGraph("dat/img/水の中/水の中１−１.png");

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/水の中/水の中２−４.png");
			back[1][2] = LoadGraph("dat/img/水の中/水の中２−３.png");
			back[1][3] = LoadGraph("dat/img/水の中/水の中２−２.png");
			back[1][4] = LoadGraph("dat/img/水の中/水の中２−１.png");

			back[2][0] = 0;
			back[2][1] = LoadGraph("dat/img/水の中/水の中３−４.png");
			back[2][2] = LoadGraph("dat/img/水の中/水の中３−３.png");
			back[2][3] = LoadGraph("dat/img/水の中/水の中３−２.png");
			back[2][4] = LoadGraph("dat/img/水の中/水の中３−１.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/水の中/水の中４−４.png");
			back[3][2] = LoadGraph("dat/img/水の中/水の中４−３.png");
			back[3][3] = LoadGraph("dat/img/水の中/水の中４−２.png");
			back[3][4] = LoadGraph("dat/img/水の中/水の中４−１.png");

			back[4][0] = LoadGraph("dat/img/水の中/水の中５−５.png");
			back[4][1] = LoadGraph("dat/img/水の中/水の中５−４.png");
			back[4][2] = LoadGraph("dat/img/水の中/水の中５−３.png");
			back[4][3] = LoadGraph("dat/img/水の中/水の中５−２.png");
			back[4][4] = LoadGraph("dat/img/水の中/水の中５−１.png");

			back[5][0] = 0;
			back[5][1] = LoadGraph("dat/img/水の中/水の中６−４.png");
			back[5][2] = LoadGraph("dat/img/水の中/水の中６−３.png");
			back[5][3] = LoadGraph("dat/img/水の中/水の中６−２.png");
			back[5][4] = LoadGraph("dat/img/水の中/水の中６−１.png");
			
			
			back[6][0] = 0;
			back[6][1] = LoadGraph("dat/img/水の中/水の中７−４.png");
			back[6][2] = LoadGraph("dat/img/水の中/水の中７−３.png");
			back[6][3] = LoadGraph("dat/img/水の中/水の中７−２.png");
			back[6][4] = LoadGraph("dat/img/水の中/水の中７−１.png");

			back[7][0] = LoadGraph("dat/img/水の中/水の中８−５.png");
			back[7][1] = LoadGraph("dat/img/水の中/水の中８−４.png");
			back[7][2] = LoadGraph("dat/img/水の中/水の中８−３.png");
			back[7][3] = LoadGraph("dat/img/水の中/水の中８−２.png");
			back[7][4] = LoadGraph("dat/img/水の中/水の中８−１.png");

			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/最初の拠点.png");
	
			g_castle[1][0] = LoadGraph("dat/img/新城/水の中/水の中１敵城１.png");
			g_castle[1][1] = LoadGraph("dat/img/新城/水の中/水の中１敵城２.png");
			g_castle[1][2] = LoadGraph("dat/img/新城/水の中/水の中１味方城.png");
	
			g_castle[2][0] = LoadGraph("dat/img/新城/水の中/水の中２敵城１.png");
			g_castle[2][1] = LoadGraph("dat/img/新城/水の中/水の中２敵城２.png");
			g_castle[2][2] = LoadGraph("dat/img/新城/水の中/水の中２味方城.png");
	
			g_castle[3][0] = LoadGraph("dat/img/新城/水の中/水の中３敵城１.png");
			g_castle[3][1] = LoadGraph("dat/img/新城/水の中/水の中３敵城２.png");
			g_castle[3][2] = LoadGraph("dat/img/新城/水の中/水の中３味方城.png");
	
			g_castle[4][0] = LoadGraph("dat/img/新城/水の中/水の中４敵城１.png");
			g_castle[4][1] = LoadGraph("dat/img/新城/水の中/水の中４敵城２.png");
			g_castle[4][2] = LoadGraph("dat/img/新城/水の中/水の中４味方城.png");
	
			g_castle[5][0] = LoadGraph("dat/img/新城/水の中/水の中５敵城１.png");
			g_castle[5][1] = LoadGraph("dat/img/新城/水の中/水の中５敵城２.png");
			g_castle[5][2] = LoadGraph("dat/img/新城/水の中/水の中５味方城.png");
	
			g_castle[6][0] = LoadGraph("dat/img/新城/水の中/水の中６敵城１.png");
			g_castle[6][1] = LoadGraph("dat/img/新城/水の中/水の中６敵城１.png");
			g_castle[6][2] = LoadGraph("dat/img/新城/水の中/水の中６味方城.png");
	
			g_castle[7][0] = LoadGraph("dat/img/新城/水の中/水の中７敵城１.png");
			g_castle[7][1] = LoadGraph("dat/img/新城/水の中/水の中７敵城２.png");
			g_castle[7][2] = LoadGraph("dat/img/新城/水の中/水の中７味方城.png");
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

			LoadDivGraph("dat/img/敵ユニット/水の中/水底の偶像待機.png", ANI_GUUZOU_W, 4, 1, WID_GUUZOU, HEI_GUUZOU, g_guuzou_w);
			LoadDivGraph("dat/img/敵ユニット/水の中/水底の偶像攻撃1.png", ANI_GUUZOU_A, 2, 1, WID_GUUZOU, HEI_GUUZOU, g_guuzou_a1);
			LoadDivGraph("dat/img/敵ユニット/水の中/水底の偶像攻撃2.png", ANI_GUUZOU_A, 2, 1, WID_GUUZOU, HEI_GUUZOU, g_guuzou_a2);

			LoadDivGraph("dat/img/敵ユニット/水の中/偶像の光.png", ANI_GLIGHT, 4, 1, WID_GLIGHT, HEI_GLIGHT, g_glight);

		
			break;
		case 6:
		{
				  int stage_back_ismove[8][5] =
				  {
					  { 0, 0, 1, 0, 0 },
					  { 0, 0, 0, 1, 1 },
					  { 0, 0, 0, 0, 0 },
					  { 0, 1, 0, 0, 0 },
					  { 0, 1, 0, 0, 0 },
					  { 0, 0, 0, 0, 0 },
					  { 0, 0, 0, 777, 0 },
					  { 666, 1, 1, 1, 1 },
				  };
				  for (int i = 0; i < 8; i++){
					  for (int j = 0; j < 5; j++){
						  back_ismove[i][j] = (stage_back_ismove[i][j] );
					  }
				  }
					  int stage_drawgap[9][3] =
					  {
						{0,0,20},
						{62,-16,-16}, 
						{25,30,0}, 
						{5,5,0}, 
						{0,0,0},  
						{0,0,0}, 
						{0,0,0}, 
						{0,0,0}, 
						{0,0,0}
					  };
					  for (int i = 0; i < 9; i++){
						  for (int j = 0; j < 3; j++){
							  draw_gap[i][j] = stage_drawgap[i][j];
						  }
					  }
		}	
			back[0][0] = 0;
			back[0][1] = LoadGraph("dat/img/メカシティ/メカシティ１−４.png");
			back[0][2] = LoadGraph("dat/img/メカシティ/メカシティ１−３.png");
			back[0][3] = LoadGraph("dat/img/メカシティ/メカシティ１−２.png");
			back[0][4] = LoadGraph("dat/img/メカシティ/メカシティ１−１.png");

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/メカシティ/メカシティ2−４.png");
			back[1][2] = LoadGraph("dat/img/メカシティ/メカシティ２−３.png");
			back[1][3] = LoadGraph("dat/img/メカシティ/メカシティ２−２.png");
			back[1][4] = LoadGraph("dat/img/メカシティ/メカシティ２−１.png");

			back[2][0] = 0;
			back[2][1] = LoadGraph("dat/img/メカシティ/メカシティ３−４.png");
			back[2][2] = LoadGraph("dat/img/メカシティ/メカシティ３−３.png");
			back[2][3] = LoadGraph("dat/img/メカシティ/メカシティ３−２.png");
			back[2][4] = LoadGraph("dat/img/メカシティ/メカシティ３−１.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/メカシティ/メカシティ４−４.png");
			back[3][2] = LoadGraph("dat/img/メカシティ/メカシティ４−３.png");
			back[3][3] = LoadGraph("dat/img/メカシティ/メカシティ４−２.png");
			back[3][4] = LoadGraph("dat/img/メカシティ/メカシティ４−１.png");

			back[4][0] = LoadGraph("dat/img/メカシティ/メカシティ５−５.png");
			back[4][1] = LoadGraph("dat/img/メカシティ/メカシティ５−４.png");
			back[4][2] = LoadGraph("dat/img/メカシティ/メカシティ５−３.png");
			back[4][3] = LoadGraph("dat/img/メカシティ/メカシティ５−２.png");
			back[4][4] = LoadGraph("dat/img/メカシティ/メカシティ５−１.png");

			back[5][0] = LoadGraph("dat/img/メカシティ/メカシティ６−５.png");
			back[5][1] = LoadGraph("dat/img/メカシティ/メカシティ６−４.png");
			back[5][2] = LoadGraph("dat/img/メカシティ/メカシティ６−３.png");
			back[5][3] = LoadGraph("dat/img/メカシティ/メカシティ６−２.png");
			back[5][4] = LoadGraph("dat/img/メカシティ/メカシティ６−１.png");
			
			
			back[6][0] = LoadGraph("dat/img/メカシティ/メカシティ７−５.png");
			back[6][1] = LoadGraph("dat/img/メカシティ/メカシティ７−４.png");
			back[6][2] = LoadGraph("dat/img/メカシティ/メカシティ７−３.png");
			back[6][3] = LoadGraph("dat/img/メカシティ/メカシティ７−２.png");
			back[6][4] = LoadGraph("dat/img/メカシティ/メカシティ７−１.png");

			back[7][0] = LoadGraph("dat/img/メカシティ/メカシティ8-8.png");
			back[7][1] = LoadGraph("dat/img/メカシティ/メカシティ8-6.png");
			back[7][2] = LoadGraph("dat/img/メカシティ/メカシティ8-4.png");
			back[7][3] = LoadGraph("dat/img/メカシティ/メカシティ8-3.png");
			back[7][4] = LoadGraph("dat/img/メカシティ/メカシティ8-2.png");

			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/最初の拠点.png");
	
			g_castle[1][0] = LoadGraph("dat/img/新城/メカシティ/メカシティ１敵城1.png");
			g_castle[1][1] = LoadGraph("dat/img/新城/メカシティ/メカシティ１敵城2.png");
			g_castle[1][2] = LoadGraph("dat/img/新城/メカシティ/メカシティ１味方城.png");
	
			g_castle[2][0] = LoadGraph("dat/img/新城/メカシティ/メカシティ２敵城１.png");
			g_castle[2][1] = LoadGraph("dat/img/新城/メカシティ/メカシティ２敵城２.png");
			g_castle[2][2] = LoadGraph("dat/img/新城/メカシティ/メカシティ２味方城.png");
	
			g_castle[3][0] = LoadGraph("dat/img/新城/メカシティ/メカシティ３敵城1.png");
			g_castle[3][1] = LoadGraph("dat/img/新城/メカシティ/メカシティ３敵城2.png");
			g_castle[3][2] = LoadGraph("dat/img/新城/メカシティ/メカシティ３味方城.png");
	
			g_castle[4][0] = LoadGraph("dat/img/新城/メカシティ/メカシティ４敵城1.png");
			g_castle[4][1] = LoadGraph("dat/img/新城/メカシティ/メカシティ４敵城2.png");
			g_castle[4][2] = LoadGraph("dat/img/新城/メカシティ/メカシティ４味方城.png");
	
			g_castle[5][0] = LoadGraph("dat/img/新城/メカシティ/メカシティ５敵城1.png");
			g_castle[5][1] = LoadGraph("dat/img/新城/メカシティ/メカシティ５敵城2.png");
			g_castle[5][2] = LoadGraph("dat/img/新城/メカシティ/メカシティ５味方城.png");
	
			g_castle[6][0] = LoadGraph("dat/img/新城/メカシティ/メカシティ６敵城1.png");
			g_castle[6][1] = LoadGraph("dat/img/新城/メカシティ/メカシティ６敵城2.png");
			g_castle[6][2] = LoadGraph("dat/img/新城/メカシティ/メカシティ６味方城.png");
	
			g_castle[7][0] = LoadGraph("dat/img/新城/メカシティ/メカシティ７敵城1.png");
			g_castle[7][1] = LoadGraph("dat/img/新城/メカシティ/メカシティ７敵城2.png");
			g_castle[7][2] = LoadGraph("dat/img/新城/メカシティ/メカシティ７味方城.png");
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

			LoadDivGraph("dat/img/敵ユニット/メカシティ/くろいしみw.png", ANI_KUROSHIMI_W, ANI_KUROSHIMI_W, 1, WID_KUROSHIMI, HEI_KUROSHIMI, g_kuroshimi_w);
			LoadDivGraph("dat/img/敵ユニット/メカシティ/くろいしみa.png", ANI_KUROSHIMI_A, ANI_KUROSHIMI_A, 1, WID_KUROSHIMI, HEI_KUROSHIMI, g_kuroshimi_a);

			LoadDivGraph("dat/img/メカねむ娘.png", ANI_MEKANEMU, ANI_MEKANEMU, 1, WID_MEKANEMU, HEI_CASTLE, g_castle[8]);

			LoadDivGraph("dat/img/ラスボス雷.png", 3, 3, 1, 324, 364, g_thunder_mekanemu);
			break;

		default:
			printfDx("initStageERROR!!");
			break;
		}
		SetUseASyncLoadFlag( FALSE ); // 非同期読み込みフラグON
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
	return stageSummary.at(sid);
}

	
	string Images::getStageName(int sid){
	return stageName.at(sid);
}

	string Images::getParamSummary(ParamType p){

		return pramSummary.at(p);


	}

	string Images::getParamName(ParamType p){

		return pramName.at(p);
	}

	string Images::getUnitName(UnitType p){
		int i = static_cast<int>(p);
		return unitName.at(i);
	}

	string Images::getUnitSummary(UnitType p){
		int i = static_cast<int>(p);
		return unitSummary.at(i);
	}
	string Images::getUnitTarget(UnitType p){
		int i = static_cast<int>(p);
		return unitTarget.at(i);
	}

	vector<int> Images::getUnitIdByStage(int sid){
		return unitByStage[sid-1];
	}