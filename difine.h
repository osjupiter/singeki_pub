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

#define MOV 1
#define ATK 2
#define DIE 3


enum Direction { LEFT = -1, NODIR = 0, RIGHT = 1 };
enum ParamType{ POWER, MAXHP, SPEED, DEFENSE, A_TYPE, CLK, COST, A_FREQ, PARAM_NUM };
enum Position{ ALL, RAND, SKY };
/*歩兵*/
#define ANI_HOHEI 6
#define ANI_HOHEI_ATK 2
#define WID_HOHEI 68
#define HEI_HOHEI 90


#define POWER_HOHEI 5
#define MAXHP_HOHEI 500
#define DEFENSE_HOHEI 1
#define SPEED_HOHEI 5
#define A_TYPE_HOHEI RAND
#define COST_HOHEI 50
#define CLK_HOHEI 4000
#define A_FREQ_HOHEI 1000

/*戦車*/
#define ANI_TANK 8
#define ANI_TANK_ATK 5
#define WID_TANK 150
#define HEI_TANK 120

#define POWER_TANK 500
#define MAXHP_TANK 50
#define DEFENSE_TANK 1
#define SPEED_TANK 50
#define A_TYPE_TANK RAND
#define COST_TANK 50
#define CLK_TANK 4000
#define A_FREQ_TANK 1000

/*風船兵*/
#define ANI_BALLOON 8
#define ANI_BALLOON_ATK 10
#define WID_BALLOON 90
#define HEI_BALLOON 180

#define POWER_BALLOON 0
#define MAXHP_BALLOON 500
#define DEFENSE_BALLOON 1
#define SPEED_BALLOON 5
#define A_TYPE_BALLOON RAND
#define COST_BALLOON 50
#define CLK_BALLOON 4000
#define A_FREQ_BALLOON 1000

/*ヘリ*/
#define ANI_COPTER 6
#define WID_COPTER 280
#define HEI_COPTER 150

#define POWER_COPTER 0
#define MAXHP_COPTER 50
#define DEFENSE_COPTER 1
#define SPEED_COPTER 50
#define A_TYPE_COPTER RAND
#define COST_COPTER 200
#define CLK_COPTER 4000
#define A_FREQ_COPTER 1000

/*ロボ兵*/
#define ANI_BIG 7
#define ANI_BIG_ATK 18
#define WID_BIG 150
#define WID_BIG_ATK 180
#define HEI_BIG 200

#define POWER_BIG 5
#define MAXHP_BIG 5000
#define DEFENSE_BIG 1
#define SPEED_BIG 2
#define A_TYPE_BIG RAND
#define COST_BIG 50
#define CLK_BIG 4000
#define A_FREQ_BIG 1000
/*神風兵*/
#define ANI_KAMIKAZE 6
#define ANI_KAMIKAZE_ATK 20
#define WID_KAMIKAZE 120
#define HEI_KAMIKAZE 140
#define WID_KAMIKAZE_ATK 140
#define HEI_KAMIKAZE_ATK 140

#define POWER_KAMIKAZE 5
#define MAXHP_KAMIKAZE 500
#define DEFENSE_KAMIKAZE 1
#define SPEED_KAMIKAZE 10
#define A_TYPE_KAMIKAZE SKY
#define COST_KAMIKAZE 50
#define CLK_KAMIKAZE 4000
#define A_FREQ_KAMIKAZE 1000
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
#define CLK_BAZOOKA 4000
#define A_FREQ_BAZOOKA 1000
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


#define MUSUME 0
#define ENEMY 1



//unit type
#define UNIT_M_NUM 5 //娘ユニットの種類

#define NONE 0
#define HOHEI 1
#define BALLOON 2
#define BIG 3
#define KAMIKAZE 4
#define BAZOOKA 5

#define TANK 10
#define COPTER 11


#define BOMB 20
#define EXP 21
#define SHOCK 22
#define MISSILE 23

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

