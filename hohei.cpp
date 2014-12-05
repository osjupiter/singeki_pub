#include "hohei.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
#define DIST_HOHEI 150
int hohei::num = 0;
hohei::hohei(int fx, int ln) : musume(fx, ln, UnitType::_HOHEI){
	dist = dist + DIST_HOHEI;
	type = RAND;

	width = WID_HOHEI;
	height = HEI_HOHEI;
	y = WINDOW_Y - height - ln * 3;
 	num++;

}

void hohei::init(){
	num = 0;
}

void hohei::main(int front){
	atk = false;
	musume::main(front);
	switch (state){
	case UnitState::MOV:
		x += param->getParam(SPEED); //‰¡ˆÚ“®
		break;
	case UnitState::ATK:

		if (ani_count / ANIM_SPEED % ANI_HOHEI_ATK == 1){
			if (!stopper){
				if (!atk){
					SoundController::getSE()->playSE("sound/shot002.wav", true);
					stopper = true;
					atk = true;
				}
			}

		}
		else{ stopper = false; }

		if ((ani_count / ANIM_SPEED == ANI_HOHEI_ATK)){
			changeState(UnitState::WAIT);
		}


		break;
	case UnitState::DIE:
	
		break;
	}
}

void hohei::draw(int cx){
	
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_hohei[ani_count / ANIM_SPEED%ANI_HOHEI], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_hohei_atk[ani_count / ANIM_SPEED%ANI_HOHEI_ATK], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_hohei_atk[0], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_hohei[ani_count / ANIM_SPEED%ANI_HOHEI_ATK], true);
		break;
	}
	character::draw(cx);

}

int hohei::getNum(){
	return num;
}

void hohei::setNum(int i){
	num = i;
}

