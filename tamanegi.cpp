#include "tamanegi.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 5

tamanegi::tamanegi(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_TAMANEGI){
	width = WID_TAMANEGI;
	height = HEI_TAMANEGI;
	y = WINDOW_Y - height + 20;
	x = x -	width +260;
	atk_type = ALL;
	dist = 600;
	type = ALL;
	dx = x - 180;
}

void tamanegi::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		if (x + width < 0) state = UnitState::DIE;
		break;
	case UnitState::ATK:
		state_change_flag = false;

		if (((ani_count / ANIM_SPEED) == ANI_TAMANEGI_T)){
			state_change_flag = true;
			changeState(UnitState::ST0);
			state_change_flag = false;
		}

		break;
	case UnitState::WAIT:
		atk = false;
		break;
	case UnitState::DIE:
		del();
		break;
	case UnitState::ST0://UŒ‚
		state_change_flag = false;

		if (ani_count / ANIM_SPEED == 2){
			if (!stopper){
				stopper = true;

			}
		}
		else{ stopper = false; }

		if (ani_count / ANIM_SPEED == 4){
			if (!stopper){
				stopper = true;

			}
		}
		else{ stopper = false; }

		if (ani_count / ANIM_SPEED == 6){
			if (!stopper){
				stopper = true;

			}
		}
		else{ stopper = false; }
		if (ani_count / ANIM_SPEED == ANI_TAMANEGI_WA*2 ){
			state_change_flag = true;
			changeState(UnitState::ST1);
			state_change_flag = false;
		}

		break;
	case UnitState::ST1:
		state_change_flag = false;
		if (ani_count / ANIM_SPEED==ANI_TAMANEGI_TR){
			state_change_flag = true;
			changeState(UnitState::MOV);
		}
		break;
	}

}

void tamanegi::draw(int cx){
	switch (state){
	case UnitState::MOV:
		DrawGraph(dx+138-85 - cx, y, Images::getIns()->g_tamanegi_w[ani_count / ANIM_SPEED%ANI_TAMANEGI_WA], true);
		break;
	case UnitState::ATK:
		DrawGraph(dx - cx, y, Images::getIns()->g_tamanegi_t[ani_count / ANIM_SPEED%ANI_TAMANEGI_T], true);
		break;
	case UnitState::WAIT:
		DrawGraph(dx - cx, y, Images::getIns()->g_tamanegi_w[ani_count / ANIM_SPEED%ANI_TAMANEGI_WA], true);
		break;
	case UnitState::DIE:
		//			DrawGraph(x - cx, y, Images::getIns()->g_tamanegi_dei[level / 3][ani_count / ANIM_SPEED_DIE%ANI_TAMANEGI_DEL], true);
		break;
	case UnitState::ST0:
		DrawGraph(dx - cx, y, Images::getIns()->g_tamanegi_a[ani_count / ANIM_SPEED%ANI_TAMANEGI_WA], true);
		break;
	case UnitState::ST1:
		DrawGraph(dx - cx, y, Images::getIns()->g_tamanegi_tr[ani_count / ANIM_SPEED%ANI_TAMANEGI_TR], true);
		break;
	}

	enemy::drawBossHP(dx,cx,height/2);
}
