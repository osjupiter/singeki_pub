#include "Factory.h"
#include "Game.h"
#include "hohei.h"
#include "bigrobo.h"
#include "tank.h"
#include "railgun.h"
#include "copter.h"
#include "kuroshimi.h"
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
#include "gajigaji.h"
#include "sharin.h"
#include "gorem.h"
#include "steam.h"
#include "beebar.h"
#include "gunshot.h"
#include "cannonshot.h"
#include "tepodon.h"
#include "bomb.h"
#include "missile.h"
#include "shock.h"
#include "explode.h"
#include "bigExplode.h"
#include "nomalExp.h"
#include "senkoutei.h"
#include "gyorai.h"
#include "shokush.h"
#include "kirakira.h"
#include "negimissile.h"
#include "monob_hidan.h"
#include "beam.h"
#include "hana.h"
#include "guuzou.h"
#include "yukidama.h"
#include "g_voice.h"
#include "monoris.h"
#include "dengumo.h"
#include "saihate.h"
#include "ohana.h"
#include "tamanegi.h"
#include "gajikami.h"
#include "zangeki.h"
#include "ikai.h"
#include "gomi.h"

using namespace std;


shared_ptr<character> Factory::create_chara(int x, int st, int line, UnitType type){
	shared_ptr<character> chara_ins(nullptr);
	switch (type){
	case UnitType::_NONE:
		break;
	case UnitType::_HOHEI:
		chara_ins.reset(new hohei(x, line));
		break;

	case UnitType::_BALOON:
		chara_ins.reset(new balloon(x, line));
		break;

	case UnitType::_BIG:
		chara_ins.reset(new bigrobo(x, line));
		break;

	case UnitType::_KAMIKAZE:
		chara_ins.reset(new kamikaze(x, line));
		break;

	case UnitType::_BAZOOKA:

		chara_ins.reset(new bazooka(x, line));
		break;

	case UnitType::_SEGWAY:
		chara_ins.reset(new segway(x, line));
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
	case UnitType::_GAJIGAJI:
		chara_ins.reset(new gajigaji(x, line, st));
		break;
	case UnitType::_SHARIN:
		chara_ins.reset(new sharin(x, line, st));
		break;
	case UnitType::_GOREMU:
		chara_ins.reset(new goremu(x, line, st));
		break;
	case UnitType::_BEEBAR:
		chara_ins.reset(new beebar(x, line, st));
		break;
	case UnitType::_MONORIS:
		chara_ins.reset(new monoris(x, line, st));
		break;
	case UnitType::_DENGUMO:
		chara_ins.reset(new dengumo(x, line, st));
		break;
	case UnitType::_SENKOUTEI:
		chara_ins.reset(new senkoutei(x, line, st));
		break;
	case UnitType::_SHOKUSH:
		chara_ins.reset(new shokush(x, line, st));
		break;
	case UnitType::_OHANA:
		chara_ins.reset(new ohana(x, line, st));
		break;
	case UnitType::_KUROSHIMI:
		chara_ins.reset(new kuroshimi(x, line, st));
		break;

	case UnitType::_SAIHATE:
		chara_ins.reset(new saihate(x, line, st));
		break;
	case UnitType::_STEAM:
		chara_ins.reset(new steam(x, line, st));
		break;
	case UnitType::_TAMANEGI:
		chara_ins.reset(new tamanegi(x, line, st));
		break;
	case UnitType::_GUUZOU:
		chara_ins.reset(new guuzou(x, line, st));
		break;
	case UnitType::_AKUUMON:
		chara_ins.reset(new ikai(x, line, st));
		break;
	default:
//		printfDx("FactoryTypeError\n");
		break;
	}

	return chara_ins;
}

std::shared_ptr<effect> Factory::create_effect(int fx, int fy, int type, Direction dr, int atk_power, int destx = 0, int desty = 0, int lv = 0){
	shared_ptr<effect> ret_ins(nullptr);
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
		ret_ins.reset(new tepodon(fx, fy, atk_power, destx));
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
	case YUKIDAMA:
		ret_ins.reset(new yukidama(fx, fy,atk_power));
		break;
	case GVOICE:
		ret_ins.reset(new gvoice(fx, fy,dr, atk_power));
		break;
	case GYORAI:
		ret_ins.reset(new gyorai(fx, fy, dr, atk_power,destx,desty,lv));
		break;
	case KIRAKIRA:
		ret_ins.reset(new kirakira(fx, fy, dr, atk_power, destx, desty, lv));
		break;
	case NEGIMISSILE:
		ret_ins.reset(new negimissile(fx, fy, dr, atk_power, destx, desty, lv));
		break;
	case GLIGHT:
		ret_ins.reset(new glight(fx, fy,atk_power));
		break;
	case GOMI:
		ret_ins.reset(new gomi(fx, fy, atk_power));
		break;
	}
	return ret_ins;
	
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
	case GAJIKAMI:
		ret_ins.reset(new gajikami(fx, fy, TurnFlag));
		break;
	case ZANGEKI:
		ret_ins.reset(new zangeki(fx, fy, TurnFlag));
		break;
	case NOMALEXP:
		ret_ins.reset(new nomalExp(fx, fy, true));
		break;
	case MONOB_H:
		ret_ins.reset(new monob_hidan(fx, fy, true));
		break;

	}
	return ret_ins;
}
