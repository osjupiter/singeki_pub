#include "balloon.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 5
int balloon::num = 0;


balloon::balloon(int fx, int fy, int ln, shared_ptr<Parameter> pm) : musume(fx, fy, ln, pm){
	dist = -dist+50;
	//hp = param->getParam(MAXHP);
	width = WID_BALLOON;
	height = HEI_BALLOON;
	num++;
	atk = false;
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
		break;
	case UnitState::ATK:
		
		if ((ani_count / ANIM_SPEED%ANI_BALLOON_ATK)
			== ANI_BALLOON_ATK - 1 && atk){
			atk = false;
			Game::getIns()->effect_create(x + 59, y + 111, BOMB);
		}
		if (!((ani_count / ANIM_SPEED%ANI_BALLOON_ATK)
			== ANI_BALLOON_ATK - 1))atk = true;
			break;
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
	case UnitState::DIE:
		break;

	}

	unit::draw(cx);
}

int balloon::getNum(){
	return num;
}

void balloon::setNum(int i){
	num = i;
}

int balloon::getPower(){
	return musume::getPower();
}
