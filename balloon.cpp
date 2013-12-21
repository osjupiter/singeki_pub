#include "balloon.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int balloon::num = 0;

balloon::balloon(int fx, int fy, int ln) : musume(fx, fy, ln){
	dist = -dist+100;
	power = 0;
	hp = 200;
	width = WID_BALLOON;
	height = HEI_BALLOON;
	num++;
	test = false;
	defense = 1;
	type = SKY;
	atk_type = RAND;
	cost = COST_BALLOON;
}

void balloon::main(int front){
	musume::main(front);
//	state = ATK;
	switch (state){
	case MOV:
		x += 4; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		break;
	case ATK:
		
		if ((ani_count / ANIM_SPEED%ANI_BALLOON_ATK)
			== ANI_BALLOON_ATK - 1 && test){
			test = false;
			Game::getIns()->effect_create(x + 59, y + 111, BOMB);
		}
		if (!((ani_count / ANIM_SPEED%ANI_BALLOON_ATK)
			== ANI_BALLOON_ATK - 1))test = true;
			break;
	case DIE:
		del();
		break;
	}
}

void balloon::draw(int cx){
	switch (state){
	case MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_balloon[ani_count / ANIM_SPEED%ANI_BALLOON], true);
		break;
	case ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_balloon_atk[ani_count / ANIM_SPEED%ANI_BALLOON_ATK], true);

		break;
	case DIE:
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

