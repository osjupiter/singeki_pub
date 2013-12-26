#include "bazooka.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int bazooka::num = 0;


bazooka::bazooka(int fx, int fy, int ln, shared_ptr<Parameter> pm) : musume(fx, fy, ln, pm){

	width = WID_BAZOOKA;
	height = HEI_BAZOOKA;
	num++;
	type = RAND;
}
void bazooka::init(){
	num = 0;
}
void bazooka::main(int front){
	musume::main(front);
	switch (state){
	case UnitState::MOV:

		break;
	case UnitState::ATK:
		if (ani_count / ANIM_SPEED % ANI_BAZOOKA_ATK == 9){
			if (!atk){

				atk = true;
			}
		}
		else {
			atk = false;
		}
		if ((ani_count / ANIM_SPEED == ANI_BAZOOKA_ATK)){
			changeState(WAIT);
			atk = false;
		}

		break;
	case UnitState::DIE:

		break;
	}
}

void bazooka::draw(int cx){

	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_bazooka[ani_count / ANIM_SPEED%ANI_BAZOOKA], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_bazooka_atk[ani_count / ANIM_SPEED%ANI_BAZOOKA_ATK], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_bazooka[0], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_bazooka_atk[0], true);
		break;
	}

	unit::draw(cx);

}

int bazooka::getNum(){
	return num;
}

void bazooka::setNum(int i){
	num = i;
}

