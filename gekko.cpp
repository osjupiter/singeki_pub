#include "gekko.h"
#include "Images.h"
#include "Game.h"
#include "Status.h"

#define ANIM_SPEED 6
#define ANIM_SPEED_ATK 1
#define DIST_GEKKO 250
int gekko::num;

	
gekko::gekko(int fx, int ln, int lv) : enemy(fx, ln, lv, UnitType::_GEKKO){
	dist = dist + DIST_GEKKO;
	y = WINDOW_Y - HEI_GEKKO - line * 3;
	width = WID_GEKKO;
	height = HEI_GEKKO;
	num++;
	type = RAND;

}


void gekko::init(){
	num = 0;
}


void gekko::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		if (x + width < 0) state = UnitState::DIE;
		break;
	case UnitState::ATK:
		atk = false;
		if (ani_count / ANIM_SPEED_ATK % ANI_GEKKO == 2){
			atk=true;
			SoundController::getSE()->playSE("sound/shot002.wav", true);
		}
		else{ atk = false; }
		if (ani_count / ANIM_SPEED_ATK == ANI_GEKKO){
			changeState(UnitState::WAIT);
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

	enemy::draw(cx);
}

int gekko::getNum(){
	return num;
}

void gekko::setNum(int i){
	num = i;
}


