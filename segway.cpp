#include "segway.h"

#include "segway.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 5
#define DIST_SEGWAY 120
#define BACK_SEGWAY 20
int segway::num = 0;


segway::segway(int fx, int fy, int ln, shared_ptr<Parameter> pm) : musume(fx, fy, ln, pm){
	dist = dist + DIST_SEGWAY;
	width = WID_SEGWAY;
	height = HEI_SEGWAY;
	num++;
	type = RAND;
	unit_type=UnitType::_SEGWAY;
}
void segway::init(){
	num = 0;
}
void segway::main(int front){
	musume::main(front);
	switch (state){
	case UnitState::MOV:

		break;
	case UnitState::ATK:
		x += param->getParam(SPEED)*3;

		if (atk){
			changeState(WAIT);
		}

		if (x-width > front){
			atk = true;
			ani_count = 0;
		}

		break;
	case UnitState::WAIT:
		atk=false;
		if (ani_count < 15){
			state_change_flag = false;
			x -= BACK_SEGWAY;			
		}
		else{
			state_change_flag = true;
		}
		break;
	case UnitState::DIE:

		break;
	}
}

void segway::draw(int cx){

	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_segway[ani_count / ANIM_SPEED%ANI_SEGWAY], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_segway_run[ani_count / ANIM_SPEED%ANI_SEGWAY], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_segway_wait[1], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_segway[0], true);
		break;
	}

	unit::draw(cx);

}

int segway::getNum(){
	return num;
}

void segway::setNum(int i){
	num = i;
}

