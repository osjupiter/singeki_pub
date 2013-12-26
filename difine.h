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


enum UnitState{ MOV, WAIT,ATK, DIE};

enum CastleState{ACTIVE,STAY,OCCUPY,EN_DIE,MEKA_DIE};
enum Direction { LEFT = -1, NODIR = 0, RIGHT = 1 };
enum ParamType{ POWER, MAXHP, SPEED, DEFENSE, A_TYPE, CLK, COST, A_FREQ, PARAM_NUM };
enum Position{ RAND, SKY ,ALL,NOATK};
/*歩兵*/
#define ANI_HOHEI 6
#define ANI_HOHEI_ATK 2
#define WID_HOHEI 68
#define HEI_HOHEI 90


#define POWER_HOHEI 2
#define MAXHP_HOHEI 500
#define DEFENSE_HOHEI 1
#define SPEED_HOHEI 5
#define A_TYPE_HOHEI ALL
#define COST_HOHEI 50

#define CLK_HOHEI 120
#define A_FREQ_HOHEI 1

/*戦車*/
#define ANI_TANK 8
#define ANI_TANK_ATK 5
#define ANI_TANK_DEL 6
#define WID_TANK 150
#define WID_TANK_DEL 220

#define HEI_TANK 120
#define HEI_TANK_DEL 120

#define POWER_TANK 1
#define MAXHP_TANK 50
#define DEFENSE_TANK 1
#define SPEED_TANK 5
#define A_TYPE_TANK RAND
#define COST_TANK 50
#define CLK_TANK 120
#define A_FREQ_TANK 1000

/*ゲッコー*/
#define ANI_GEKKO 4
#define ANI_GEKKO_UP 3
#define ANI_GEKKO_DOWN 4

#define WID_GEKKO 200
#define HEI_GEKKO 200

#define POWER_GEKKO 10
#define MAXHP_GEKKO 50
#define DEFENSE_GEKKO 1
#define SPEED_GEKKO 5
#define A_TYPE_GEKKO ALL
#define COST_GEKKO 50
#define CLK_GEKKO 120
#define A_FREQ_GEKKO 0

/*レールガン*/
#define ANI_RAILGUN 3

#define WID_RAILGUN 370
#define HEI_RAILGUN 200

#define POWER_RAILGUN 200
#define MAXHP_RAILGUN 500
#define DEFENSE_RAILGUN 1
#define SPEED_RAILGUN 5
#define A_TYPE_RAILGUN NOATK
#define COST_RAILGUN 50
#define CLK_RAILGUN 120
#define A_FREQ_RAILGUN 200

/*風船兵*/
#define ANI_BALLOON 8
#define ANI_BALLOON_ATK 10
#define WID_BALLOON 90
#define HEI_BALLOON 180

#define POWER_BALLOON 40
#define MAXHP_BALLOON 500
#define DEFENSE_BALLOON 1
#define SPEED_BALLOON 5
#define A_TYPE_BALLOON NOATK
#define COST_BALLOON 50
#define CLK_BALLOON 120
#define A_FREQ_BALLOON 100

/*ヘリ*/
#define ANI_COPTER 6
#define WID_COPTER 280
#define HEI_COPTER 150

#define POWER_COPTER 500
#define MAXHP_COPTER 50
#define DEFENSE_COPTER 1
#define SPEED_COPTER 10
#define A_TYPE_COPTER NOATK
#define COST_COPTER 200

#define CLK_COPTER 120
#define A_FREQ_COPTER 50

/*ロボ兵*/
#define ANI_BIG 7
#define ANI_BIG_ATK 18
#define WID_BIG 150
#define WID_BIG_ATK 180
#define HEI_BIG 200

#define POWER_BIG 50
#define MAXHP_BIG 5000
#define DEFENSE_BIG 1
#define SPEED_BIG 2
#define A_TYPE_BIG RAND
#define COST_BIG 50
#define CLK_BIG 120
#define A_FREQ_BIG 50

/*神風兵*/
#define ANI_KAMIKAZE 6
#define ANI_KAMIKAZE_ATK 20
#define WID_KAMIKAZE 120
#define HEI_KAMIKAZE 140
#define WID_KAMIKAZE_ATK 140
#define HEI_KAMIKAZE_ATK 140

#define POWER_KAMIKAZE 100
#define MAXHP_KAMIKAZE 500
#define DEFENSE_KAMIKAZE 1
#define SPEED_KAMIKAZE 10
#define A_TYPE_KAMIKAZE SKY
#define COST_KAMIKAZE 50
#define CLK_KAMIKAZE 120
#define A_FREQ_KAMIKAZE 10
/*バズーカ兵*/
#define ANI_BAZOOKA 8
#define ANI_BAZOOKA_ATK 12
#define WID_BAZOOKA 120
#define HEI_BAZOOKA 110
#define WID_BAZOOKA_ATK 130
#define HEI_BAZOOKA_ATK 110

#define POWER_BAZOOKA 5
#define MAXHP_BAZOOKA 500
#define DEFENSE_BAZOOKA 1
#define SPEED_BAZOOKA 5
#define A_TYPE_BAZOOKA RAND
#define COST_BAZOOKA 50
#define CLK_BAZOOKA 120
#define A_FREQ_BAZOOKA 20

/*セグウェイ兵*/
#define ANI_SEGWAY 3
#define ANI_SEGWAY_WAIT 2
#define WID_SEGWAY 70
#define HEI_SEGWAY 110
#define WID_SEGWAY_WAIT 85
#define WID_SEGWAY_RUN 85

#define POWER_SEGWAY 100
#define MAXHP_SEGWAY 500
#define DEFENSE_SEGWAY 1
#define SPEED_SEGWAY 5
#define A_TYPE_SEGWAY RAND
#define COST_SEGWAY 50
#define CLK_SEGWAY 120
#define A_FREQ_SEGWAY 40
/*爆弾*/
#define ANI_BOMB 2
#define WID_BOMB 30
#define HEI_BOMB 40

/*爆発*/
#define ANI_EXP 12
#define WID_EXP 200
#define HEI_EXP 250

/*衝撃波*/
#define ANI_SHOCK 7
#define WID_SHOCK 200
#define HEI_SHOCK 450

/*ミサイ*/
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



#define MUSUME 0
#define ENEMY 1



//unit type
#define UNIT_M_NUM 6 //娘ユニットの種類

#define NONE 0
#define HOHEI 1
#define BALLOON 2
#define BIG 3
#define KAMIKAZE 4
#define BAZOOKA 5
#define SEGWAY 6


#define TANK 10
#define COPTER 11
#define GEKKO 12
#define RAILGUN 13

#define BOMB 20
#define EXP 21
#define SHOCK 22
#define MISSILE 23
#define TEPODON 24
#define BEAM 25

#define STAGE_NUM 8



#define FIELD_W 800
#define FIELD_H 450



#define STAGE1_W 1950
#define STAGE2_W STAGE1_W+1950
#define STAGE3_W STAGE2_W+1950
#define STAGE4_W STAGE3_W+1950
#define STAGE5_W STAGE4_W+1950
#define STAGE6_W STAGE5_W+1950
#define STAGE7_W STAGE6_W+1950
#define STAGE8_W STAGE7_W+1950

#define WID_CASTLE 650
#define HEI_CASTLE 450