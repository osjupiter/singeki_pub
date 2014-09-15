#include "bazooka.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
#define DIST_BAZOOKA 300
int bazooka::num = 0;


bazooka::bazooka(int fx, int fy, int ln, shared_ptr<Parameter> pm) : musume(fx, fy, ln, pm){
	dist = dist + DIST_BAZOOKA;
	width = WID_BAZOOKA;
	height = HEI_BAZOOKA;
	num++;
	type = RAND;
	unit_type=UnitType::_BAZOOKA;
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
				SoundController::getSE()->playSE("sound/taihou03.mp3");
				atk = true;
			}
		}
		else {
			atk = false;
		}
		if ((ani_count / ANIM_SPEED == ANI_BAZOOKA_ATK+1)){
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
		if (atk_position == RAND)
			DrawGraph(x - cx, y, Images::getIns()->g_bazooka_atk[ani_count / ANIM_SPEED%ANI_BAZOOKA_ATK], true);
		else
			DrawRotaGraph2(x+2 - cx, y+102, 58,105,1.0, 3.1415926535*(345 / 180.0), Images::getIns()->g_bazooka_atk[ani_count / ANIM_SPEED%ANI_BAZOOKA_ATK], true);
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

