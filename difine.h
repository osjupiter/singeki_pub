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

#define ANI_HOHEI 6
#define ANI_HOHEI_ATK 2
#define WID_HOHEI 68
#define HEI_HOHEI 90
#define COST_HOHEI 50
#define CLK_HOHEI 1000

#define ANI_TANK 8
#define ANI_TANK_ATK 5
#define WID_TANK 150
#define HEI_TANK 120
#define COST_TANK 200

#define ANI_BALLOON 8
#define ANI_BALLOON_ATK 10
#define WID_BALLOON 90
#define HEI_BALLOON 180
#define COST_BALLOON 50
#define CLK_BALLOON 2000

#define ANI_COPTER 6
#define WID_COPTER 280
#define HEI_COPTER 150
#define COST_COPTER 50
//#define CLK_COPTER 2000


#define ANI_BIG 7
#define ANI_BIG_ATK 18
#define WID_BIG 150
#define WID_BIG_ATK 180
#define HEI_BIG 200
#define COST_BIG 50
#define CLK_BIG 4000

#define ANI_KAMIKAZE 6
#define ANI_KAMIKAZE_ATK 20
#define WID_KAMIKAZE 120
#define HEI_KAMIKAZE 140
#define WID_KAMIKAZE_ATK 140
#define HEI_KAMIKAZE_ATK 140
#define COST_KAMIKAZE 50
#define CLK_KAMIKAZE 4000


#define ANI_BOMB 2
#define WID_BOMB 30
#define HEI_BOMB 40


#define ANI_EXP 12
#define WID_EXP 200
#define HEI_EXP 250

#define ANI_SHOCK 7
#define WID_SHOCK 150
#define HEI_SHOCK 350

#define ANI_MISSILE 3
#define WID_MISSILE 90
#define HEI_MISSILE 60


//unit type
#define NONE 0
#define HOHEI 1
#define BALLOON 2
#define BIG 3
#define KAMIKAZE 4

#define TANK 10
#define COPTER 11


#define BOMB 20
#define EXP 21
#define SHOCK 22
#define MISSILE 23

#define STAGE_NUM 8

#define FIELD_W 800
#define FIELD_H 450

enum Direction {LEFT=-1,NODIR=0,RIGHT=1};

#define STAGE1_W 1950
#define STAGE2_W STAGE1_W+1950
#define STAGE3_W STAGE2_W+1950
#define STAGE4_W STAGE3_W+1950
#define STAGE5_W STAGE4_W+1950
#define STAGE6_W STAGE5_W+1950
#define STAGE7_W STAGE6_W+1950
#define STAGE8_W STAGE7_W+1950

