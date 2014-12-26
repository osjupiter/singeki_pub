#include "gorem.h"
#include "Images.h"
#include "Game.h"
#include "Status.h"
#include"SoundController.h"


#define ANIM_SPEED 2
#define ANIM_SPEED_ATK 4
#define DIST_GOREMU 350


goremu::goremu(int fx, int ln, int lv) : enemy(fx, ln, lv, UnitType::_GOREMU){
	dist = dist + DIST_GOREMU;
	y = WINDOW_Y - HEI_GOREMU - line * 3;
	power = 200;
	hp = MAXHP_GEKKO + MAXHP_GEKKO*0.4*lv;
	width = WID_GOREMU;
	height = HEI_GOREMU;
	speed = SPEED_GEKKO + 0.5*SPEED_GEKKO;
	defense = DEFENSE_GEKKO*(1 + 0.3*lv);
	type = RAND;
	atk_type = A_TYPE_GEKKO;
	cost = COST_GEKKO + 120 * lv;
	atk_freq = 10;
	maxhp = hp;
	visible = false;
}



void goremu::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		if (visible){
			changeState(UnitState::WAIT);
		}
		else{
			x += speed*dir; //�Ƃ肠�������ړ�
		}
		break;
	case UnitState::ATK:
		if (!visible){
			changeState(UnitState::ST0);
			visible = true;
		}else	state_change_flag = false;
		if (ani_count / ANIM_SPEED_ATK == 10){
			if (!stopper){
				Game::getIns()->effect_create(x, y, GVOICE, dir, power);
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
		
		break;
	case UnitState::ST0:   //�o��
		if (ani_count / ANIM_SPEED == ANI_GOREMU){
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
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_goremu_a[level / 3][0], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_goremu_a[level / 3][ani_count / ANIM_SPEED%ANI_GOREMU], true);
		break;
	}

	if(state != UnitState::MOV)enemy::draw(cx);
}