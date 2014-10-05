#include "Factory.h"
#include "Game.h"
#include "hohei.h"
#include "bigrobo.h"
#include "tank.h"
#include "railgun.h"
#include "copter.h"
#include "segway.h"
#include "kamikaze.h"
#include "gekko.h"
#include "bazooka.h"
#include "balloon.h"

using namespace std;

shared_ptr<musume> Factory::create_musume(int x, int st, int line, UnitType type){
	shared_ptr<musume> chara_ins = NULL;
	switch (type){
	case UnitType::_HOHEI:
		chara_ins.reset(new hohei(x, line));
		break;
		/*
	case BALLOON:
		chara_ins = new balloon(stage_W[st], 50 - line * 10, line, param_list[BALLOON]);
		break;

	case BIG:		
		chara_ins = new bigrobo(stage_W[st], WINDOW_Y - HEI_BIG + line * 3, line, param_list[BIG]);
		break;

	case KAMIKAZE:
		chara_ins = new kamikaze(stage_W[st], 50 - line * 3, line, param_list[KAMIKAZE]);
		break;
	
	case BAZOOKA:
	
		chara_ins = new bazooka(stage_W[st], WINDOW_Y - HEI_BAZOOKA - line * 3, line, param_list[BAZOOKA]);
		break;
	
	case SEGWAY:
	
		chara_ins = new segway(stage_W[st], WINDOW_Y - HEI_SEGWAY - line * 3, line, param_list[SEGWAY]);
		break;
	*/
/*	case UnitType::_TANK:
		chara_ins = new tank(x, WINDOW_Y - HEI_TANK - line * 3, line, st);
		break;
		
	case COPTER:
		chara_ins = new copter(stage_W[st], 50 - line * 3, line, getNowStage());
		break;
	
	case GEKKO:
		chara_ins = new gekko(stage_W[st], WINDOW_Y - HEI_GEKKO - line * 3, line, getNowStage());
		break;
	
	case RAILGUN:
		chara_ins = new railgun(stage_W[st], WINDOW_Y - HEI_RAILGUN - line * 3, line, getNowStage());
		break;
	*/
	default:
		break;
	}
//	shared_ptr<character> p(chara_ins);
	return chara_ins;
}

shared_ptr<enemy> Factory::create_enemy(int x, int st, int line, UnitType type){
	shared_ptr<enemy> chara_ins = NULL;
	switch (type){
	case UnitType::_TANK:
		chara_ins.reset(new tank(x, WINDOW_Y - HEI_TANK - line * 3, line, st));
		break;
		/*
		case COPTER:
		chara_ins = new copter(stage_W[st], 50 - line * 3, line, getNowStage());
		break;

		case GEKKO:
		chara_ins = new gekko(stage_W[st], WINDOW_Y - HEI_GEKKO - line * 3, line, getNowStage());
		break;

		case RAILGUN:
		chara_ins = new railgun(stage_W[st], WINDOW_Y - HEI_RAILGUN - line * 3, line, getNowStage());
		break;
		*/
	default:
		break;
	}

	return chara_ins;
}