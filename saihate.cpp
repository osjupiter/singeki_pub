#include "saihate.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 5

saihate::saihate(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_SAIHATE){
	width = WID_SAIHATE;
	height = HEI_SAIHATE;
	y = WINDOW_Y - height;

	dist = 200;
	type = ALL;
}

void saihate::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		if (rand() % 10 == 0){
			changeState(UnitState::ST1);
		}
		break;
	case UnitState::ATK:
		state_change_flag = false;
		if (rand() % 10 == 0){
			state_change_flag = true;
			changeState(UnitState::ST1);
		}
		if (ani_count / ANIM_SPEED == 7){
			if (!stopper){
				if (atk_position == RAND){
					shared_ptr<AttackRange> p(new AttackRange(x + WID_SAIHATE - WID_SAIHATE_A_R, x + WID_SAIHATE, power, RAND));
					stopper = true;
				}
			}
		}
		else{ stopper = false; }

		if (ani_count / ANIM_SPEED == ANI_SAIHATE_A - 1){
			state_change_flag = true;
			changeState(UnitState::ST0);
			state_change_flag = false;
		}
		break;
	case UnitState::WAIT:
		break;
	case UnitState::ST0:
		changeState(UnitState::MOV);
		break;
	case UnitState::ST1:
		
		if (ani_count/ANIM_SPEED == ANI_SAIHATE_A){
			
			Game::getIns()->effect_create(x - WID_SAIHATE*1.5,FIELD_H - HEI_YUKIDAMA, YUKIDAMA,NODIR,power);
			changeState(UnitState::ST0);
			stopper = true;
		}
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
		DrawGraph(x - cx + WID_SAIHATE - WID_SAIHATE_A_R, y, Images::getIns()->g_saihate_a_r[(ANI_SAIHATE_A - 1)-ani_count / ANIM_SPEED%ANI_SAIHATE_A], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_saihate_t[ani_count / ANIM_SPEED%ANI_SAIHATE_T], true);
		break;
	case UnitState::ST0:
		DrawGraph(x - cx, y, Images::getIns()->g_saihate_h[ani_count / ANIM_SPEED%ANI_SAIHATE_H], true);
		break;
	case UnitState::ST1:
		DrawGraph(x - cx, y + HEI_SAIHATE - HEI_SAIHATE_A_S, Images::getIns()->g_saihate_a_s[ani_count / ANIM_SPEED%ANI_SAIHATE_A], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_saihate_t[ani_count / ANIM_SPEED%ANI_SAIHATE_T], true);
		break;
	}
	character::draw(cx);
}
