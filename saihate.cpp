#include "saihate.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3

saihate::saihate(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_SAIHATE){
	width = WID_SAIHATE;
	height = HEI_SAIHATE;
	y = WINDOW_Y - height;

	dist = 200;
	power = POWER_TANK *(1 * lv);
	hp = MAXHP_TANK + MAXHP_TANK*lv;
	speed = SPEED_TANK + 0.5*SPEED_TANK*lv;
	defense = DEFENSE_TANK*(1 + 0.8*lv);
	type = ALL;
	atk_type = A_TYPE_TANK;
	cost = COST_TANK + 40 * lv;
	atk_freq = A_FREQ_TANK - 0.05*A_FREQ_TANK*lv;
	maxhp = hp;
}

void saihate::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		break;
	case UnitState::ATK:
		if (ani_count / ANIM_SPEED == 5){
			if (!stopper){
				shared_ptr<AttackRange> p(new AttackRange(x + WID_SAIHATE - WID_SAIHATE_A_R, x + WID_SAIHATE, param->getParam(POWER), RAND));
				stopper = true;
			}
		}
		else{ stopper = false; }
		break;
	case UnitState::WAIT:
		break;
	case UnitState::DIE:

		del();
		break;
	}
}

void saihate::draw(int cx){
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_saihate_t[ani_count / ANIM_SPEED%ANI_SAIHATE_T], true);
		break;
	case UnitState::ATK:
		if (atk_position ==RAND )
			DrawGraph(x - cx + WID_SAIHATE -WID_SAIHATE_A_R, y, Images::getIns()->g_saihate_a_r[ani_count / ANIM_SPEED%ANI_SAIHATE_A], true);
		else 
			DrawGraph(x - cx, y + HEI_SAIHATE - HEI_SAIHATE_A_S, Images::getIns()->g_saihate_a_r[ani_count / ANIM_SPEED%ANI_SAIHATE_A], true);

		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_saihate_t[ani_count / ANIM_SPEED%ANI_SAIHATE_T], true);

		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_saihate_t[ani_count / ANIM_SPEED%ANI_SAIHATE_T], true);

		break;
	}
	character::draw(cx);
}