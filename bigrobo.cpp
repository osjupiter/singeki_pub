#include "bigrobo.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int bigrobo::num = 0;

bigrobo::bigrobo(int fx, int fy, int ln) : musume(fx, fy, ln){
	power = 4;
	hp = 200;
	width = WID_BIG;
	height = HEI_BIG;
	num++;
	type = RAND;
	
	defense = 1;
	atk_type = RAND;
	cost = COST_BIG;
}

void bigrobo::main(int front){
	musume::main(front);
	state = MOV;
	switch (state){

	case MOV:
		x += 4; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		break;
	case DIE:
		del();
		break;
	}
}

void bigrobo::draw(int cx){
	
	switch (state){
	case MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_robo[ani_count / ANIM_SPEED%ANI_BIG], true);
		break;
	case ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_hohei_atk[ani_count / ANIM_SPEED%ANI_BIG_ATK], true);
		break;
	}

	unit::draw(cx);

}

int bigrobo::getNum(){
	return num;
}

void bigrobo::setNum(int i){
	num = i;
}

