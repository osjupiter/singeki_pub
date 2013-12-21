#include "hohei.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int hohei::num=0;

hohei::hohei(int fx, int fy, int ln) : musume(fx,fy,ln){
	power = 4;
	hp = 200;
	width = WID_HOHEI;
	height = HEI_HOHEI;
	num++;
	type = RAND;
	defense = 1;
	atk_type = RAND;
	cost = COST_HOHEI;
}

void hohei::main(int front){
	musume::main(front);
	switch (state){
	case MOV:
		x += 4; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		break;
	case DIE:
		y -= 60;
		x -= 20; 
		if (y+height<0)
			del();
		break;
	}
}

void hohei::draw(int cx){
	
	switch (state){
	case MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_hohei[ani_count / ANIM_SPEED%ANI_HOHEI], true);
		break;
	case ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_hohei_atk[ani_count / ANIM_SPEED%ANI_HOHEI_ATK], true);
		break;
	case DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_hohei_atk[0], true);
		break;
	}

	unit::draw(cx);

}

int hohei::getNum(){
	return num;
}

void hohei::setNum(int i){
	num = i;
}

