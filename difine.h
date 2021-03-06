#pragma once
#define WINDOW_X 800
#define WINDOW_Y 450




#define PKMAX 10

#define LEN 256
#define MOJI_S 24//文字サイズ
#define MOJI_THIN 0
#define M_SX 12 //文字幅と間を足した数（半角）
#define M_SY 32//上に同じ
#define L_MAX 60


enum class UnitState{ MOV, WAIT,ATK, DIE,ST0,ST1,ST2,SENNOU}; //ST0:汎用ステート


//enum CastleState{ACTIVE,STAY,OCCUPY,EN_DIE,MEKA_DIE};
enum class CastleState{ ACTIVE, STAY, DIE};
enum Direction { LEFT = -1, NODIR = 0, RIGHT = 1 };
enum ParamType{ POWER, MAXHP, SPEED, DEFENSE, A_TYPE, CLK, COST, A_FREQ, DIST,PARAM_NUM };
enum Position{ RAND, SKY ,ALL,NOATK};
enum class PropertyType{NONE};


enum UnitType{_NONE,_HOHEI,_BALOON,_BIG,_KAMIKAZE,_BAZOOKA,_SEGWAY,_YOUJO,_TATEKO,_HIME,_IKAROS,_MAJO,_NOUKA,_IDLE,_TAKO,_SUMAPHO,END_MUSUME
				,_TANK,_COPTER,_GEKKO,_RAILGUN,_SHARIN,_GAJIGAJI,_STEAM,_GOREMU,_BEEBAR,_SAIHATE
				,_DENGUMO,_MONORIS,_AKUUMON,_SENKOUTEI,_SHOKUSH,_GUUZOU
				,_OHANA,_SHOKUCHU,_TAMANEGI,_KUROSHIMI,_SHOUSHA,_MEKABOSS,_DARKMUSUME,UNITTYPE_NUM};


enum EffectType{ BOMB = 20, EXP, SHOCK, MISSILE, TEPODON, BEAM, BIGEXP, NOMALEXP, GUNSHOT, CANNONSHOT, DROP, WISP, HANA, YUKIDAMA, GVOICE, MONOBEAM,GYORAI,KIRAKIRA,NEGIMISSILE
	, GAJIKAMI, ZANGEKI, MAHOJIN, MONOB_H, GLIGHT, GBEAM, GOMI, MAHOU, IKAMINARI,BUBBLE
};



/*歩兵*/
#define ANI_HOHEI 6
#define ANI_HOHEI_ATK 2
#define WID_HOHEI 68
#define HEI_HOHEI 90


/*戦車*/
#define ANI_TANK 8
#define ANI_TANK_ATK 5
#define ANI_TANK_DEL 6
#define WID_TANK 150
#define WID_TANK_DEL 220

#define HEI_TANK 120
#define HEI_TANK_DEL 120

/*ゲッコー*/
#define ANI_GEKKO 4
#define ANI_GEKKO_UP 3
#define ANI_GEKKO_DOWN 4

#define WID_GEKKO 200
#define HEI_GEKKO 200

/*レールガン*/
#define ANI_RAILGUN 3

#define WID_RAILGUN 370
#define HEI_RAILGUN 200


/*風船兵*/
#define ANI_BALLOON 8
#define ANI_BALLOON_ATK 10
#define WID_BALLOON 90
#define HEI_BALLOON 180

/*車輪*/
#define ANI_SHARIN 6
#define WID_SHARIN 120
#define HEI_SHARIN 90

/*ガジガジ*/
#define ANI_GAJIGAJI_W 5
#define ANI_GAJIGAJI_A 6
#define WID_GAJIGAJI 220
#define HEI_GAJIGAJI_W  110
#define HEI_GAJIGAJI_A  130


/*ゴレーム*/
#define ANI_GOREMU 12
#define WID_GOREMU 300
#define HEI_GOREMU 300

/*ビーバー*/
#define ANI_BEEBAR_W 4
#define ANI_BEEBAR_A 7
#define WID_BEEBAR_W 120
#define HEI_BEEBAR_W 120
#define WID_BEEBAR_A 240
#define HEI_BEEBAR_A 280

/*モノリス*/
#define ANI_MONORIS_W 11
#define ANI_MONORIS_A1 8
#define ANI_MONORIS_A2 3
#define WID_MONORIS 100
#define HEI_MONORIS 200 

/*モノリスビーム*/
#define ANI_MONOBEAM 4
#define WID_MONOBEAM 100
#define HEI_MONOBEAM 100 

/*発電雲*/
#define ANI_DENGUMO_W 11
#define ANI_DENGUMO_A 15
#define WID_DENGUMO 220
#define HEI_DENGUMO 260 

/*潜航艇*/
#define ANI_SENKOU_W 4
#define ANI_SENKOU_A 6
#define WID_SENKOU 386
#define HEI_SENKOU 307 

/*魚雷*/
#define ANI_GYORAI 2
#define WID_GYORAI 262
#define HEI_GYORAI 170 

/*触手*/
#define ANI_SHOKUSH_S 15 
#define ANI_SHOKUSH_A 9 
#define WID_SHOKUSH 250 
#define HEI_SHOKUSH 210 

/*キラキラ*/
#define ANI_KIRAKIRA 12 
#define WID_KIRAKIRA 250 
#define HEI_KIRAKIRA 210 

/*発電雲雷*/
#define ANI_DENKAMI 4
#define WID_DENKAMI 370
#define HEI_DENKAMI 180 

/*異界の門雷*/
#define ANI_IKAMINARI 10
#define WID_IKAMINARI 390
#define HEI_IKAMINARI 450

/*お花砲台*/
#define ANI_OHANA_S 16
#define ANI_OHANA_A 9
#define WID_OHANA 299
#define HEI_OHANA 296

/*玉ねぎ*/
#define ANI_TAMANEGI_WA 4
#define ANI_TAMANEGI_T 12
#define ANI_TAMANEGI_TR 6
#define WID_TAMANEGI 650
#define HEI_TAMANEGI 450

/*玉ねぎミサイル*/
#define ANI_NEGIMISSILE 2
#define WID_NEGIMISSILE 300
#define HEI_NEGIMISSILE 350

/*ヘリ*/
#define ANI_COPTER 6
#define WID_COPTER 280
#define HEI_COPTER 150

#define ANI_COPTER_DIE 9
#define WID_COPTER_DIE 280
#define HEI_COPTER_DIE 450


/*ロボ兵*/
#define ANI_BIG 7
#define ANI_BIG_ATK 18
#define WID_BIG 150
#define WID_BIG_ATK 180
#define HEI_BIG 200


/*神風兵*/
#define ANI_KAMIKAZE 6
#define ANI_KAMIKAZE_ATK 20
#define WID_KAMIKAZE 120
#define HEI_KAMIKAZE 140
#define WID_KAMIKAZE_ATK 140
#define HEI_KAMIKAZE_ATK 140

/*バズーカ兵*/
#define ANI_BAZOOKA 8
#define ANI_BAZOOKA_ATK 12
#define WID_BAZOOKA 120
#define HEI_BAZOOKA 110
#define WID_BAZOOKA_ATK 130
#define HEI_BAZOOKA_ATK 110

/*セグウェイ*/
#define ANI_SEGWAY 3
#define ANI_SEGWAY_WAIT 2
#define WID_SEGWAY 70
#define HEI_SEGWAY 110
#define WID_SEGWAY_WAIT 85
#define WID_SEGWAY_RUN 85

/*幼女*/
#define ANI_YOUJO_W 4
#define ANI_YOUJO_D 3
#define ANI_YOUJO_A 14
#define WID_YOUJO 150
#define HEI_YOUJO 220

/*盾篭り*/
#define ANI_TATEKO_W 5
#define ANI_TATEKO_A 3
#define WID_TATEKO 100
#define HEI_TATEKO 190

/*姫騎士*/
#define ANI_HIME_W 5
#define ANI_HIME_A 3
#define WID_HIME_W 120
#define WID_HIME_A 120
#define HEI_HIME 140

#define ANI_HIME_O 6
#define WID_HIME_O 80
#define HEI_HIME_O 300

#define ANI_HIME_C 5
#define WID_HIME_C 120
#define HEI_HIME_C 140

#define ANI_HIME_H 5
#define WID_HIME_H 720
#define HEI_HIME_H 290

#define ANI_HIME_HC 2
#define WID_HIME_HC 120
#define HEI_HIME_HC 140

#define ANI_HIME_AE 3
#define WID_HIME_AE 120
#define HEI_HIME_AE 140


/*イカロス*/
#define ANI_IKAROS_W 5
#define ANI_IKAROS_A 4
#define WID_IKAROS_W 120
#define WID_IKAROS_A 120
#define HEI_IKAROS 130

/*マジョ*/
#define ANI_MAJO_W 4
#define ANI_MAJO_A 8
#define WID_MAJO_W 100
#define WID_MAJO_A 100
#define HEI_MAJO 120

#define ANI_MAHOU 10
#define WID_MAHOU 150
#define HEI_MAHOU 150

/*農家*/
#define ANI_NOUKA_W 4
#define ANI_NOUKA_A 16
#define WID_NOUKA_W 84
#define WID_NOUKA_A 103
#define HEI_NOUKA 110

/*スチームパンクロボ*/
#define ANI_STEAM_W 9
#define ANI_STEAM_F 4
#define ANI_STEAM_A 16
#define WID_STEAM 650
#define HEI_STEAM 450

/*異界の門*/
#define ANI_IKAI_W 4
#define ANI_IKAI_A1 3
#define ANI_IKAI_A2 4
#define WID_IKAI 650
#define HEI_IKAI 450

/*ゴミ*/
#define ANI_GOMI 12
#define WID_GOMI 80
#define HEI_GOMI 80


/*偶像*/
#define ANI_GUUZOU_W 4
#define ANI_GUUZOU_A 2
#define WID_GUUZOU 650
#define HEI_GUUZOU 450

/*偶像の光*/
#define ANI_GLIGHT 4
#define WID_GLIGHT 290
#define HEI_GLIGHT 450

/*偶像の洗脳*/
#define ANI_GBEAM 4
#define WID_GBEAM 350
#define HEI_GBEAM 450

#define ANI_SENNOU 6
#define WID_SENNOU 70
#define HEI_SENNOU 50

/*さいはて*/
#define ANI_SAIHATE_H 9
#define ANI_SAIHATE_A 13
#define ANI_SAIHATE_T 6
#define WID_SAIHATE 400
#define WID_SAIHATE_A_R 800
#define HEI_SAIHATE 300
#define HEI_SAIHATE_A_S 450

/*爆弾*/
#define ANI_BOMB 2
#define WID_BOMB 30
#define HEI_BOMB 40

/*星爆発*/
#define ANI_EXP 12
#define WID_EXP 200
#define HEI_EXP 250

/*城爆発*/
#define ANI_BIGEXP 15
#define WID_BIGEXP 600
#define HEI_BIGEXP 450

/*爆発*/
#define ANI_NOMALEXP 7
#define WID_NOMALEXP 250
#define HEI_NOMALEXP 200

/*衝撃波*/
#define ANI_SHOCK 7
#define WID_SHOCK 200
#define HEI_SHOCK 450

/*ミサイル*/
#define ANI_MISSILE 3
#define WID_MISSILE 90
#define HEI_MISSILE 60

#define ANI_TEPODON 3
#define WID_TEPODON 140
#define HEI_TEPODON 70

#define ANI_BEAM 9
#define WID_BEAM 1000
#define HEI_BEAM 200

#define ANI_MONOB_H 3
#define WID_MONOB_H 100
#define HEI_MONOB_H 80

#define ANI_KUROSHIMI_W 7
#define ANI_KUROSHIMI_A 8
#define WID_KUROSHIMI 191 
#define HEI_KUROSHIMI 218

/*魔方陣*/
#define ANI_MAHOJIN 20
#define WID_MAHOJIN 150
#define HEI_MAHOJIN 150

#define ANI_GAJIKAMI 6
#define WID_GAJIKAMI 100
#define HEI_GAJIKAMI 130

#define ANI_ZANGEKI 4
#define WID_ZANGEKI 150
#define HEI_ZANGEKI 120


#define ANI_BEAM_C 5
#define WID_BEAM_C 140
#define HEI_BEAM_C 200

#define ANI_GUNSHOT 3
#define WID_GUNSHOT 74
#define HEI_GUNSHOT 90


#define ANI_CANNONSHOT 4
#define WID_CANNONSHOT 90
#define HEI_CANNONSHOT 120


#define ANI_WISP 7
#define WID_WISP 155
#define HEI_WISP 168


#define ANI_DROP 8
#define WID_DROP 96
#define HEI_DROP 450

#define ANI_BUBBLE 24
#define WID_BUBBLE 120
#define HEI_BUBBLE 450


#define ANI_HANA 25
#define WID_HANA 143
#define HEI_HANA 110

#define ANI_YUKIDAMA 8
#define WID_YUKIDAMA 450
#define HEI_YUKIDAMA 450

#define ANI_GVOICE 7
#define WID_GVOICE 500
#define HEI_GVOICE 500

#define ANI_MEKANEMU 3
#define WID_MEKANEMU 400

#define MUSUME 0
#define ENEMY 1

#define HOHEI 1

#define STAGE_NUM 8
#define WORLD_NUM 6


#define FIELD_W 800
#define FIELD_H 450




#define WID_CASTLE 650
#define HEI_CASTLE 450