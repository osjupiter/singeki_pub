#include "ikaros.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
#define DIST_IKAROS 300


ikaros::ikaros(int fx, int ln) : musume(fx, ln, UnitType::_IKAROS){
	dist = dist + DIST_IKAROS;
	width = WID_IKAROS_W;
	height = HEI_IKAROS;
	stopper = false;
	type = SKY;
	y = 60 - line * 10;
}


void ikaros::main(int front){
	musume::main(front);
	switch (state){
	case UnitState::MOV:
		x += param->getParam(SPEED); //‰¡ˆÚ“®
		break;
	case UnitState::ATK:
		state_change_flag = false;
		if (ani_count / ANIM_SPEED == ANI_IKAROS_A - 1 ){
			if (!stopper){
				if (!atk){
					
					atk = true;
					stopper = true;
				}
			}
			else {
				atk = false;
			}
		}
		else { stopper = false; }
		if ((ani_count / ANIM_SPEED == ANI_IKAROS_A)){
			state_change_flag = true;
			changeState(UnitState::WAIT);
			atk = false;
		}

		break;
	case UnitState::DIE:

		break;

	}
}
void ikaros::draw(int cx){

	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_ikaros_w[ani_count / ANIM_SPEED%ANI_IKAROS_W], true);
		break;
	case UnitState::ATK:
			DrawGraph(x - cx, y, Images::getIns()->g_ikaros_a[ani_count / ANIM_SPEED%ANI_IKAROS_A], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_ikaros_w[ani_count / ANIM_SPEED%ANI_IKAROS_W], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_ikaros_w[0], true);
		break;
	}

	character::draw(cx);

}

