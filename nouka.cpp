#include "nouka.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
#define DIST_NOUKA 200

nouka::nouka(int fx, int ln) : musume(fx, ln, UnitType::_NOUKA){
	dist = dist + DIST_NOUKA;
	type = RAND;

	width = WID_NOUKA_W;
	height = HEI_NOUKA;
	y = WINDOW_Y - height - ln * 3;
	

}

void nouka::main(int front){
	atk = false;
	musume::main(front);
	switch (state){
	case UnitState::MOV:
		x += param->getParam(SPEED); //‰¡ˆÚ“®
		break;
	case UnitState::ATK:
		state_change_flag = false;
		//atk = false;
		if (ani_count / ANIM_SPEED == ANI_NOUKA_A*2){
			if (!stopper){
				Game::getIns()->effect_create(x + 88 -71, FIELD_H - HEI_HANA, HANA);
				state_change_flag = true;
				changeState(UnitState::DIE);
					stopper = true;
			}

		}
		else{ stopper = false; }

		

		
		break;
	case UnitState::DIE:

		break;
	}
}

void nouka::draw(int cx){
	int* image = (ani_count / ANIM_SPEED < ANI_NOUKA_A) ? &(Images::getIns()->g_nouka_a1[0]) : &(Images::getIns()->g_nouka_a2[0]);
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_nouka_w[ani_count / ANIM_SPEED%ANI_NOUKA_W], true);
		break;
	case UnitState::ATK:

		DrawGraph(x - cx, y, image[ani_count / ANIM_SPEED%ANI_NOUKA_A], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_nouka_w[0], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_nouka_w[ani_count / ANIM_SPEED%ANI_NOUKA_A], true);
		break;
	}
	character::draw(cx);

}
