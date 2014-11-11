#include "segway.h"

#include "segway.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 5
#define DIST_SEGWAY 120
#define BACK_SEGWAY 20
int segway::num = 0;


segway::segway(int fx, int ln) : musume(fx, ln, UnitType::_SEGWAY){
	dist = dist + DIST_SEGWAY;
	width = WID_SEGWAY;
	height = HEI_SEGWAY;
	num++;
	type = RAND;
	y = WINDOW_Y - HEI_SEGWAY - line * 3;
	unit_type=UnitType::_SEGWAY;
}
void segway::init(){
	num = 0;
}
void segway::main(int front){
	musume::main(front);
	switch (state){
	case UnitState::MOV:
		x += param->getParam(SPEED); //‰¡ˆÚ“®
		break;
	case UnitState::ATK:
		x += param->getParam(SPEED)*3;

		if (atk){
			//Game::getIns()->effect_create(x - 125, WINDOW_Y - HEI_NOMALEXP + 25, NOMALEXP);
			Images::playSE("sound/sen_mi_robo_bato01.mp3");
			Game::getIns()->damage_effect_create(x - 125 +5, WINDOW_Y - HEI_NOMALEXP + 25, NOMALEXP);
			changeState(UnitState::WAIT);
		}

		if (x-width/2 > front){
			atk = true;
			
			ani_count = 0;
		}

		break;
	case UnitState::WAIT:
		atk=false;
		if (ani_count < 18){
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

	character::draw(cx);

}

int segway::getNum(){
	return num;
}

void segway::setNum(int i){
	num = i;
}

