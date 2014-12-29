#pragma once
#include"DxLib.h"

#include "GV.h"


#include<map>
#include<list>
#include<string>
#include<vector>
using namespace std;

class Images
{


	static Images ins;
	std::map<std::string, int> gs;



public:	
	int blend;
	


	int g_hohei[ANI_HOHEI];//•à•º
	int g_hohei_atk[ANI_HOHEI_ATK];
	int g_tank[3][8];
	int g_tank_atk[3][5];
	int g_tank_dei[3][6];
	int g_balloon[8];
	int g_balloon_atk[10];
	int g_bomb[2];
	int g_exp[12];
	int g_robo[7];
	int g_robo_atk[18];
	int g_shock[7];
	int g_copter[6];
	int g_copter_die[9];
	int g_missile[3];
	int g_kamikaze[6];
	int g_kamikaze_atk[20];
	int g_tepodon[3];
	int g_bazooka[8];
	int g_bazooka_atk[12];
	int g_segway[3];
	int g_segway_wait[2];
	int g_segway_run[3];
	int g_youjo_w[ANI_YOUJO_W];
	int g_youjo_d[ANI_YOUJO_D];
	int g_youjo_a[ANI_YOUJO_A];
	int g_tateko_w[ANI_TATEKO_W];
	int g_tateko_a[ANI_TATEKO_A];
	int g_hime_w[ANI_HIME_W];
	int g_hime_a[ANI_HIME_A];
	int g_ikaros_w[ANI_IKAROS_W];
	int g_ikaros_a[ANI_IKAROS_A];
	int g_majo_w[ANI_MAJO_W];
	int g_majo_a[ANI_MAJO_A];
	int g_nouka_w[ANI_NOUKA_W];
	int g_nouka_a1[ANI_NOUKA_A];
	int g_nouka_a2[ANI_NOUKA_A];
	int g_hana[ANI_HANA];
	int g_steam_w[ANI_STEAM_W];
	int g_steam_a[ANI_STEAM_A];
	int g_steam_f[ANI_STEAM_F];
	int g_gyorai[3][ANI_GYORAI];

	int g_gajigaji_w[3][5];
	int g_gajigaji_a[3][6];
	int g_saihate_a_r[ANI_SAIHATE_A];
	int g_saihate_a_s[ANI_SAIHATE_A];
	int g_saihate_t[ANI_SAIHATE_T];
	int g_saihate_h[ANI_SAIHATE_H];
	int g_sharin_w[3][ANI_SHARIN];
	int g_sharin_a[3][ANI_SHARIN];
	int g_goremu_w[3][ANI_GOREMU];
	int g_goremu_a[3][ANI_GOREMU];
	int g_beebar_w[3][ANI_BEEBAR_W];
	int g_beebar_a[3][ANI_BEEBAR_A];
	int g_gvoice[ANI_GVOICE];
	int g_monoris_w[3][ANI_MONORIS_W];
	int g_monoris_a1[3][ANI_MONORIS_A1];
	int g_monoris_a2[3][ANI_MONORIS_A2];
	int g_monobeam[3][ANI_MONOBEAM];
	int g_dengumo_w[3][ANI_DENGUMO_W];
	int g_dengumo_a[3][ANI_DENGUMO_A];
	int g_denkami[3][ANI_DENKAMI];
	int g_senkoutei_w[3][ANI_SENKOU_W];
	int g_senkoutei_a[3][ANI_SENKOU_A];
	int g_kirakira[3][ANI_KIRAKIRA];
	int g_ohana_s[3][ANI_OHANA_S];
	int g_ohana_a[3][ANI_OHANA_A];
	int g_tamanegi_w[ANI_TAMANEGI_WA];
	int g_tamanegi_a[ANI_TAMANEGI_WA];
	int g_tamanegi_t[ANI_TAMANEGI_T];
	int g_tamanegi_tr[ANI_TAMANEGI_TR];
	int g_negimissile[3][ANI_NEGIMISSILE];
	int g_guuzo_w[ANI_GUUZO_W];
	int g_guuzo_a1[ANI_GUUZO_A];
	int g_guuzo_a2[ANI_GUUZO_W];
	int g_gajikami[ANI_GAJIKAMI];
	int g_zangeki[ANI_ZANGEKI];
	int g_mahojin[ANI_MAHOJIN];
	int g_monob_h[ANI_MONOB_H];
	int g_shiro_icon[20][2];

	int g_shokush_s[3][ANI_SHOKUSH_S];
	int g_shokush_a[3][ANI_SHOKUSH_A];

	int g_gekko[4];
	int g_gekko_up[3];
	int g_gekko_down[4];
	int g_rail[4];
	int g_beam[9];
	int g_beam_c[5];
	int g_mekanemu[3];
	int g_castle[9][3];
	int g_mekahaikyo;
	int g_bigexp[15];
	int g_thunder_mekanemu[3];
	int g_nomalExp[7];
	int g_gunshot[3];
	int g_cannonshot[4];
	int g_e_yamidrop[3][8];
	int g_e_wisp[3][7];
	int g_yukidama1[ANI_YUKIDAMA];
	int g_yukidama2[ANI_YUKIDAMA];

	int houdai_yama;

	int font,font2;
	
	int back[8][5];
	Images(void){}
	~Images(void){}
	void load();
	static void init();
	static Images* getIns();
	static int get(const char name[]);

	void loadStage(int);
	void releaseStage();


	
	static int getMusumeIcon(int,boolean=false);
	static int getSiroIcon(int,boolean=false);
	static int getParamTypeIcon(ParamType,boolean=false);

	string getStageSummary(int);
	
	
	string getStageName(int sid);




};