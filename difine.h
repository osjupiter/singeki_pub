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


enum class UnitState{ MOV, WAIT,ATK, DIE,ST0,ST1,ST2}; //ST0:汎用ステート


//enum CastleState{ACTIVE,STAY,OCCUPY,EN_DIE,MEKA_DIE};
enum class CastleState{ ACTIVE, STAY, DIE};
enum Direction { LEFT = -1, NODIR = 0, RIGHT = 1 };
enum ParamType{ POWER, MAXHP, SPEED, DEFENSE, A_TYPE, CLK, COST, A_FREQ, PARAM_NUM };
enum Position{ RAND, SKY ,ALL,NOATK};
enum class PropertyType{NONE};


enum UnitType{_NONE,_HOHEI,_BALOON,_BIG,_KAMIKAZE,_BAZOOKA,_SEGWAY,_YOUJO,_TATEKO,_HIME,_IKAROS,_MAJO,_NOUKA,_IDLE,_TAKO,_SUMAPHO,END_MUSUME
				,_TANK,_COPTER,_GEKKO,_RAILGUN,_SHARIN,_GAJIGAJI,_STEAM,_GOREMU,_BEEBAR,_SAIHATE
				,_DENGUMO,_MONORIS,_AKUUMON,_SENKOUTEI,_SHOKUSH,_GUUZOU
				,_OHANA,_SHOKUCHU,_TAMANEGI,_SHIMI,_SHOUSHA,_MEKABOSS,_DARKMUSUME,UNITTYPE_NUM};


enum EffectType{ BOMB = 20, EXP, SHOCK, MISSILE, TEPODON, BEAM, BIGEXP,NOMALEXP ,GUNSHOT,CANNONSHOT,DROP,WISP,HANA,YUKIDAMA,GVOICE};



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

/**/

/**/


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
#define ANI_HIME_A 6
#define WID_HIME_W 120
#define WID_HIME_A 120
#define HEI_HIME 140

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

/*農家*/
#define ANI_NOUKA_W 4
#define ANI_NOUKA_A 16
#define WID_NOUKA_W 84
#define WID_NOUKA_A 103
#define HEI_NOUKA 110



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