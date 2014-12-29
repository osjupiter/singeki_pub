#include "ohana.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
#define ANIM_SPEED_S 2

#define DIST_OHANA 50
ohana::ohana(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_OHANA){
	width = WID_OHANA;
	height = HEI_OHANA;
	y = WINDOW_Y - height;
	atk_type = RAND;
	dist = dist % 20 + DIST_OHANA;
	type = RAND;
	visible = false;
}

void ohana::main(int front){
	pre_state = state;
	enemy::main(front);

	switch (state){
	case UnitState::MOV:
		if (pre_state != UnitState::MOV){
			visible = false;
		}
		if (pre_state != UnitState::MOV){
			visible = false;
		}
		if (visible){

			changeState(UnitState::WAIT);
		}
		else{
			no_damage_flag = true;
		}

		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®

		break;
	case UnitState::ATK:
		if (!visible){
			changeState(UnitState::ST0);
			visible = true;
			no_damage_flag = false;
		}
		else{
			state_change_flag = false;
		}
		if (ani_count / ANIM_SPEED == 6){
			if (!stopper){
				if (!atk){
					stopper = true;
					atk = true;
				}
			}
			else{ atk = false; }
		}
		else { stopper = false; }

		if (ani_count / ANIM_SPEED == ANI_OHANA_A){
			state_change_flag = true;
			changeState(UnitState::WAIT);
		}

		break;
	case UnitState::WAIT:

		break;
	case UnitState::ST0:   //oŒ»
		if (ani_count / ANIM_SPEED_S == ANI_OHANA_S){
			changeState(UnitState::ATK);
		}
		break;
	case UnitState::DIE:

		if (ani_count == 1){
			Game::getIns()->effect_create(x + width / 2 - WID_NOMALEXP / 2, y + height / 2 - HEI_NOMALEXP / 2, NOMALEXP);
		}
		if (ani_count == 4)
			Game::getIns()->effect_create(x + width / 2 - WID_NOMALEXP / 2 + 10, y + height / 2 - HEI_NOMALEXP / 2, NOMALEXP);

		if (ani_count / 3 == 2){
			del();
		}
		break;

	}
}

void ohana::draw(int cx){
	switch (state){
	case UnitState::MOV:
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_ohana_a[level / 3][ani_count / ANIM_SPEED%ANI_OHANA_A], true);
		break;
	case UnitState::ST0:
		DrawGraph(x - cx, y, Images::getIns()->g_ohana_s[level / 3][ani_count / ANIM_SPEED_S%ANI_OHANA_S], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_ohana_a[level / 3][ani_count / ANIM_SPEED%6], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_ohana_a[level / 3][ani_count / ANIM_SPEED %ANI_OHANA_A], true);
		break;
	}

	if (state != UnitState::MOV)enemy::draw(cx);

}
