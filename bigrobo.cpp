#include "bigrobo.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int bigrobo::num = 0;



bigrobo::bigrobo(int fx, int fy, int ln, shared_ptr<Parameter> pm) : musume(fx, fy, ln, pm){
	hp = param->getParam(MAXHP);
	width = WID_BIG;
	height = HEI_BIG;
	num++;
	type = RAND;
	atk = false;
	dist = width;
}

void bigrobo::init(){
	num = 0;
	
}

void bigrobo::main(int front){
	musume::main(front);
//	state = ATK;
	switch (state){		
	case MOV:
		x += 3; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		break;
	case ATK:
		if (ani_count / ANIM_SPEED%ANI_BIG_ATK == ANI_BIG_ATK - 1 && atk){
			Game::getIns()->effect_create(x + 95, FIELD_H - HEI_SHOCK, SHOCK);
			atk = false;
			//power = 500;
		}
		if (!(ani_count / ANIM_SPEED%ANI_BIG_ATK == ANI_BIG_ATK - 1)){
			atk = true;
		//	power = 0;
		}
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
		DrawGraph(x - cx, y, Images::getIns()->g_robo_atk[ani_count / ANIM_SPEED%ANI_BIG_ATK], true);
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

