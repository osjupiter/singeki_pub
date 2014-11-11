#include "balloon.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int balloon::num = 0;


balloon::balloon(int fx, int ln) : musume(fx, ln, UnitType::_BALOON){
	dist = -dist;

	width = WID_BALLOON;
	height = HEI_BALLOON;
	num++;
	atk = false;
	stopper = false;
	y = 50 - ln * 10;
	type = SKY;

}
void balloon::init(){
	num = 0;
}
void balloon::main(int front){
	musume::main(front);
//	state = ATK;
	switch (state){
	case UnitState::MOV:
		x += param->getParam(SPEED); //‰¡ˆÚ“®
		break;
	case UnitState::ATK:
		
		if (ani_count / ANIM_SPEED % ANI_BALLOON_ATK == ANI_BALLOON_ATK - 1){
			if (!atk){
				Game::getIns()->effect_create(x + 59, y + 111, BOMB,Direction::NODIR,param->getParam(POWER));
				atk = true;
			}
		}
		else{ atk = false;
			state_change_flag = false;
		}
		
		if ((ani_count / ANIM_SPEED == ANI_BALLOON_ATK)){
			state_change_flag = true;

			changeState(UnitState::WAIT);
//			atk = false;
		}

	case UnitState::DIE:
	//	del();
		break;
	}
}

void balloon::draw(int cx){
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_balloon[ani_count / ANIM_SPEED%ANI_BALLOON], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_balloon_atk[ani_count / ANIM_SPEED%ANI_BALLOON_ATK], true);

		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_balloon[ani_count / ANIM_SPEED%ANI_BALLOON], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_balloon[ani_count / ANIM_SPEED%ANI_BALLOON], true);
		break;

	}

	character::draw(cx);
}

int balloon::getNum(){
	return num;
}

void balloon::setNum(int i){
	num = i;
}


