#include "hohei.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int hohei::num = 0;
hohei::hohei(int fx, int fy, int ln, shared_ptr<Parameter> pm) : musume(fx, fy, ln, pm){
	
	//hp = param->getParam(MAXHP);
	width = WID_HOHEI;
	height = HEI_HOHEI;
	num++;
	type = RAND;
	unit_type=UnitType::_HOHEI;
}

void hohei::init(){
	num = 0;
}

void hohei::main(int front){
	musume::main(front);
	switch (state){

	case UnitState::ATK:


		if (ani_count / ANIM_SPEED % ANI_HOHEI_ATK == 0){
			if (!atk){
				Images::playSE("sound/gun03.mp3", true);
				atk = true;
			}
		}
		else {
			atk = false;
		}
		if ((ani_count / ANIM_SPEED == ANI_HOHEI_ATK)){
			changeState(WAIT);
			atk = false;
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
	unit::draw(cx);

}

int hohei::getNum(){
	return num;
}

void hohei::setNum(int i){
	num = i;
}

