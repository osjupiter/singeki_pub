#include "gekko.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 2

int gekko::num;


gekko::gekko(int fx, int fy, int ln, int lv) : enemy(fx, fy, ln, lv){
	power = POWER_GEKKO;
	hp = MAXHP_GEKKO*lv;
	width = WID_GEKKO;
	height = HEI_GEKKO;
	speed = SPEED_GEKKO;
	defense = DEFENSE_GEKKO*lv;
	num++;
	type = RAND;
	atk_type = A_TYPE_GEKKO;
	cost = COST_GEKKO;
	atk_freq = A_FREQ_GEKKO;
}


void gekko::init(){
	num = 0;
}


void gekko::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		if (x + width < 0) state = DIE;
		break;
	case UnitState::ATK:
		atk = false;
		if (ani_count / ANIM_SPEED % ANI_GEKKO == 2){			
			atk=true;
		}
		else{ atk = false; }
		if (ani_count / ANIM_SPEED == ANI_GEKKO ){
			changeState(WAIT);
		}
		break;
	case UnitState::WAIT:

		break;
	case UnitState::DIE:
		del();
		break;

	}

}

void gekko::draw(int cx){
	int* graph;
	int anime;


	switch (state){
	case UnitState::MOV:
		if (dir == LEFT){
			DrawGraph(x - cx, y, Images::getIns()->g_gekko[ani_count / ANIM_SPEED%ANI_GEKKO], true);
		}
		else{
			DrawTurnGraph(x - cx, y, Images::getIns()->g_gekko[ani_count / ANIM_SPEED%ANI_GEKKO], true);
		}
		break;
	case UnitState::ATK:
		if (atk_position == RAND){
			graph = Images::getIns()->g_gekko_down;
			anime = ANI_GEKKO_DOWN;
		}
		else{
			graph = Images::getIns()->g_gekko_up;
			anime = ANI_GEKKO_UP;
		}
		if (dir == LEFT){
			DrawGraph(x - cx, y, graph[ani_count / ANIM_SPEED%anime], true);
		}
		else{
			DrawTurnGraph(x - cx, y, graph[ani_count / ANIM_SPEED%anime], true);
		}
		break;
	case UnitState::WAIT:
		if (dir == LEFT){
			DrawGraph(x - cx, y, Images::getIns()->g_gekko[ani_count / ANIM_SPEED%ANI_GEKKO], true);
		}
		else{
			DrawTurnGraph(x - cx, y, Images::getIns()->g_gekko[ani_count / ANIM_SPEED%ANI_GEKKO], true);
		}
		break;
	}

	unit::draw(cx);
}

int gekko::getNum(){
	return num;
}

void gekko::setNum(int i){
	num = i;
}


