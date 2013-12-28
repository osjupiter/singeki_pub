#pragma once
#define WINDOW_X 800
#define WINDOW_Y 450




#define PKMAX 10

#define LEN 256
#define MOJI_S 24//�����T�C�Y
#define MOJI_THIN 0
#define M_SX 12 //�������ƊԂ𑫂������i���p�j
#define M_SY 32//��ɓ���
#define L_MAX 60


enum UnitState{ MOV, WAIT,ATK, DIE};

enum CastleState{ACTIVE,STAY,OCCUPY,EN_DIE,MEKA_DIE};
enum Direction { LEFT = -1, NODIR = 0, RIGHT = 1 };
enum ParamType{ POWER, MAXHP, SPEED, DEFENSE, A_TYPE, CLK, COST, A_FREQ, PARAM_NUM };
enum Position{ RAND, SKY ,ALL,NOATK};



enum class UnitType{_NONE,_HOHEI,_BALOON,_BIG,_KAMIKAZE,_BAZOOKA,_SEGWAY,END_MUSUME,_TANK=10,_COPTER,_GEKKO,_RAILGUN};

enum EffectType{ BOMB = 20, EXP, SHOCK, MISSILE, TEPODON, BEAM, BIGEXP,NOMALEXP ,GUNSHOT,CANNONSHOT,DROP,WISP};


/*����*/
#define ANI_HOHEI 6
#define ANI_HOHEI_ATK 2
#define WID_HOHEI 68
#define HEI_HOHEI 90


/*���*/
#define ANI_TANK 8
#define ANI_TANK_ATK 5
#define ANI_TANK_DEL 6
#define WID_TANK 150
#define WID_TANK_DEL 220

#define HEI_TANK 120
#define HEI_TANK_DEL 120

/*�Q�b�R�[*/
#define ANI_GEKKO 4
#define ANI_GEKKO_UP 3
#define ANI_GEKKO_DOWN 4

#define WID_GEKKO 200
#define HEI_GEKKO 200

/*���[���K��*/
#define ANI_RAILGUN 3

#define WID_RAILGUN 370
#define HEI_RAILGUN 200


/*���D��*/
#define ANI_BALLOON 8
#define ANI_BALLOON_ATK 10
#define WID_BALLOON 90
#define HEI_BALLOON 180



/*�w��*/
#define ANI_COPTER 6
#define WID_COPTER 280
#define HEI_COPTER 150

#define ANI_COPTER_DIE 9
#define WID_COPTER_DIE 280
#define HEI_COPTER_DIE 450


/*���{��*/
#define ANI_BIG 7
#define ANI_BIG_ATK 18
#define WID_BIG 150
#define WID_BIG_ATK 180
#define HEI_BIG 200


/*�_����*/
#define ANI_KAMIKAZE 6
#define ANI_KAMIKAZE_ATK 20
#define WID_KAMIKAZE 120
#define HEI_KAMIKAZE 140
#define WID_KAMIKAZE_ATK 140
#define HEI_KAMIKAZE_ATK 140

/*�o�Y�[�J��*/
#define ANI_BAZOOKA 8
#define ANI_BAZOOKA_ATK 12
#define WID_BAZOOKA 120
#define HEI_BAZOOKA 110
#define WID_BAZOOKA_ATK 130
#define HEI_BAZOOKA_ATK 110


#define ANI_SEGWAY 3
#define ANI_SEGWAY_WAIT 2
#define WID_SEGWAY 70
#define HEI_SEGWAY 110
#define WID_SEGWAY_WAIT 85
#define WID_SEGWAY_RUN 85

/*���e*/
#define ANI_BOMB 2
#define WID_BOMB 30
#define HEI_BOMB 40

/*������*/
#define ANI_EXP 12
#define WID_EXP 200
#define HEI_EXP 250

/*�锚��*/
#define ANI_BIGEXP 15
#define WID_BIGEXP 600
#define HEI_BIGEXP 450

/*����*/
#define ANI_NOMALEXP 7
#define WID_NOMALEXP 250
#define HEI_NOMALEXP 200

/*�Ռ��g*/
#define ANI_SHOCK 7
#define WID_SHOCK 200
#define HEI_SHOCK 450

/*�~�T�C*/
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

#define ANI_MEKANEMU 3
#define WID_MEKANEMU 400

#define MUSUME 0
#define ENEMY 1



//unit type
#define UNIT_M_NUM 6 //�����j�b�g�̎��

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
/*
#define BOMB 20
#define EXP 21
#define SHOCK 22
#define MISSILE 23
#define TEPODON 24
#define BEAM 25
#define BIGEXP 26
*/
#define STAGE_NUM 8


#define FIELD_W 800
#define FIELD_H 450




#define WID_CASTLE 650
#define HEI_CASTLE 450