#include "bigrobo.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int bigrobo::num = 0;



bigrobo::bigrobo(int fx, int fy, int ln, shared_ptr<Parameter> pm) : musume(fx, fy, ln, pm){

	width = WID_BIG;
	height = HEI_BIG;
	num++;
	type = RAND;
	atk = false;
	dist = width;
	unit_type=UnitType::_BIG;
}

void bigrobo::init(){
	num = 0;
	
}

void bigrobo::main(int front){
	musume::main(front);

	switch (state){		
	case UnitState::MOV:

		break;
	case UnitState::ATK:
		if (ani_count / ANIM_SPEED % ANI_BIG_ATK == ANI_BIG_ATK - 1 ){
			if (!atk){
				Game::getIns()->effect_create(x + 95, FIELD_H - HEI_SHOCK, SHOCK);
				atk = true;
			}
		}
		else {
			atk = false;
		}
		if ((ani_count / ANIM_SPEED == ANI_BIG_ATK )){
			changeState(WAIT);
			atk = false;
		}
		break;
	case UnitState::DIE:
		
		break;
	}
}

void bigrobo::draw(int cx){
	
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_robo[ani_count / ANIM_SPEED%ANI_BIG], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_robo_atk[ani_count / ANIM_SPEED%ANI_BIG_ATK], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_robo_atk[0], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_robo_atk[0], true);
		break;
	}

	unit::draw(cx);

}

int bigrobo::getNum(){
	return num;
}

void bigrobo::setNum(int i){
	num = i;
}

