#include "gorem.h"
#include "Images.h"
#include "Game.h"
#include "Status.h"
#include"SoundController.h"


#define ANIM_SPEED 2
#define ANIM_SPEED_ATK 4
#define DIST_GOREMU 60


goremu::goremu(int fx, int ln, int lv) : enemy(fx, ln, lv, UnitType::_GOREMU){
	dist = DIST_GOREMU - rand()%50;
	y = WINDOW_Y - HEI_GOREMU - line * 3;
	width = WID_GOREMU;
	height = HEI_GOREMU;
	type = RAND;
	visible = false;
}



void goremu::main(int front){
	pre_state = state;
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		if (pre_state != UnitState::MOV){
//			visible = false;
			;
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
		}else	state_change_flag = false;
		if (ani_count / ANIM_SPEED_ATK == 10){
			if (!stopper){
				Game::getIns()->effect_create(x, y+60, GVOICE, dir, power);
				stopper = true;
			}
		}
		else { stopper = false; }

		if (ani_count / ANIM_SPEED_ATK == ANI_GOREMU){
			state_change_flag = true;
			changeState(UnitState::WAIT);
		}

		break;
	case UnitState::WAIT:
		if (!visible){
			changeState(UnitState::ST0);
			visible = true;
			no_damage_flag = false;
		}
		break;
	case UnitState::ST0:   //oŒ»
		if (ani_count / ANIM_SPEED == ANI_GOREMU){
			changeState(UnitState::ATK);
		}
		break;
	case UnitState::ST1:  
		if (ani_count / ANIM_SPEED == ANI_GOREMU){

			changeState(UnitState::MOV);
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

void goremu::draw(int cx){
	

	switch (state){
	case UnitState::MOV:
		
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_goremu_a[level / 3][ani_count / ANIM_SPEED_ATK%ANI_GOREMU], true);
	
		break;
	case UnitState::ST0:
		DrawGraph(x - cx, y, Images::getIns()->g_goremu_w[level / 3][ani_count / ANIM_SPEED%ANI_GOREMU], true);
		break;
	case UnitState::ST1:
		DrawGraph(x - cx, y, Images::getIns()->g_goremu_w[level / 3][(ANI_GOREMU -1) - ani_count / ANIM_SPEED%ANI_GOREMU], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_goremu_a[level / 3][0], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_goremu_a[level / 3][ani_count / ANIM_SPEED%ANI_GOREMU], true);
		break;
	}

	if(state != UnitState::MOV)enemy::draw(cx);
}