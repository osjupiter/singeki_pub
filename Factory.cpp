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
#include "youjo.h"
#include "tateko.h"
#include "himekishi.h"
#include "ikaros.h"
#include "majo.h"
#include "nouka.h"

#include "gunshot.h"
#include "cannonshot.h"
#include "tepodon.h"
#include "bomb.h"
#include "missile.h"
#include "shock.h"
#include "explode.h"
#include "bigExplode.h"
#include "nomalExp.h"
#include "beam.h"
#include "hana.h"
using namespace std;


shared_ptr<character> Factory::create_chara(int x, int st, int line, UnitType type){
	shared_ptr<character> chara_ins(nullptr);
	switch (type){
	case UnitType::_HOHEI:
		chara_ins.reset(new hohei(x, line));
		break;

	case UnitType::_BALOON:
		chara_ins.reset(new nouka(x, line));
		break;

	case UnitType::_BIG:
		chara_ins.reset(new youjo(x, line));
		break;

	case UnitType::_KAMIKAZE:
		chara_ins.reset(new ikaros(x, line));
		break;

	case UnitType::_BAZOOKA:

		chara_ins.reset(new tateko(x, line));
		break;

	case UnitType::_SEGWAY:
		chara_ins.reset(new himekishi(x, line));
		break;
	case UnitType::_YOUJO:
		chara_ins.reset(new youjo(x, line));
		break;
	case UnitType::_TATEKO:
		chara_ins.reset(new tateko(x, line));
		break;
	case UnitType::_HIME:
		chara_ins.reset(new himekishi(x, line));
		break;
	case UnitType::_IKAROS:
		chara_ins.reset(new ikaros(x, line));
		break;
	case UnitType::_MAJO:
		chara_ins.reset(new majo(x, line));
		break;
	case UnitType::_NOUKA:
		chara_ins.reset(new nouka(x, line));
		break;
	case UnitType::_TANK:
		chara_ins.reset(new tank(x, line, st));
		break;
	case UnitType::_COPTER:
		chara_ins.reset(new copter(x, line, st));
		break;
	case UnitType::_GEKKO:
		chara_ins.reset(new gekko(x, line, st));
		break;
	case UnitType::_RAILGUN :
		chara_ins.reset(new railgun(x, line, st));
		break;

	default:
		break;
	}

	return chara_ins;
}

std::shared_ptr<effect> Factory::create_effect(int fx, int fy, int type, Direction dr, int atk_power, int dest){
/*	shared_ptr<effect> ret_ins(nullptr);
	switch (type) {
	case BOMB:
		ret_ins.reset(new bomb(fx, fy, atk_power));
		break;	
	
	case EXP:
		ret_ins.reset(new explode(fx, fy));
		break;
	
	case SHOCK:
		ret_ins.reset(new shock(fx, fy));
		break;

	case MISSILE:
		ret_ins.reset(new missile(fx, fy, dr, atk_power));
		break;
	
	case TEPODON:
		ret_ins.reset(new tepodon(fx, fy, atk_power, dest));
		break;
	
	case BEAM:
		ret_ins.reset(new beam(fx, fy, atk_power));
		break;
	
	case BIGEXP:
		ret_ins.reset(new bigExp(fx, fy));
		break;
	
	case NOMALEXP:
		ret_ins.reset(new nomalExp(fx, fy));		
		break;
	
	case WISP:
		ret_ins.reset(new wisp(fx, fy));
		break;
	
	case DROP:
		ret_ins.reset(new drop(fx, fy));
		break;
	case HANA:
		ret_ins.reset(new hana(fx, fy));
		break;
	}
	return ret_ins;
	*/
	shared_ptr<effect> p(new drop(fx, fy));
	return p;
}

shared_ptr<effect> Factory::create_damage_effect(int fx, int fy, int e_type, bool TurnFlag){
	shared_ptr<effect> ret_ins(nullptr);
	switch (e_type) {
	case GUNSHOT:
		ret_ins.reset(new gunshot(fx, fy, TurnFlag));
		break;
	
	case CANNONSHOT:
		ret_ins.reset(new cannonshot(fx, fy, TurnFlag));
		break;
	
	case NOMALEXP:
		ret_ins.reset(new nomalExp(fx, fy, true));
		break;
	
	}
	return ret_ins;
}
