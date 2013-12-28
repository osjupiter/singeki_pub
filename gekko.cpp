#include "gekko.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 6
#define ANIM_SPEED_ATK 1
#define DIST_GEKKO 100
int gekko::num;


gekko::gekko(int fx, int fy, int ln, int lv) : enemy(fx, fy, ln, lv){
	dist = dist + DIST_GEKKO;
	
	power = POWER_GEKKO;
	hp = MAXHP_GEKKO+120*lv;
	width = WID_GEKKO;
	height = HEI_GEKKO;
	speed = SPEED_GEKKO;
	defense = DEFENSE_GEKKO*lv;
	num++;
	type = RAND;
	atk_type = A_TYPE_GEKKO;
	cost = COST_GEKKO;
	atk_freq = A_FREQ_GEKKO;
	unit_type = UnitType::_GEKKO;
}


void gekko::init(){
	num = 0;
}


void gekko::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //とりあえず横移動
		if (x + width < 0) state = DIE;
		break;
	case UnitState::ATK:
		atk = false;
		if (ani_count / ANIM_SPEED_ATK % ANI_GEKKO == 2){
			atk=true;
	//		Images::playSE("sound/shot002.wav", true);
		}
		else{ atk = false; }
		if (ani_count / ANIM_SPEED_ATK == ANI_GEKKO){
			changeState(WAIT);
		}
		break;
	case UnitState::WAIT:

		break;
	case UnitState::DIE:
		
		if (ani_count == 1){
			Game::getIns()->effect_create(x + width / 2 - WID_NOMALEXP / 2, y + height / 2 - HEI_NOMALEXP / 2, NOMALEXP);
		}
		if (ani_count==4)
			Game::getIns()->effect_create(x + width / 2 - WID_NOMALEXP / 2+10, y + height / 2 - HEI_NOMALEXP / 2, NOMALEXP);

		if (ani_count / 3 == 2){
			del();
		}
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
			DrawGraph(x - cx, y, graph[ani_count / ANIM_SPEED_ATK%anime], true);
		}
		else{
			DrawTurnGraph(x - cx, y, graph[ani_count / ANIM_SPEED_ATK%anime], true);
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
	case UnitState::DIE:
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


