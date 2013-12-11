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
}

void hohei::main(int front){
	musume::main(front);
	if(state == MOV)x += 4; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
	if (x > FIELD_W * 15) life = false;
	
}

void hohei::draw(int cx){
	switch (state){
	case MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_hohei[ani_count / ANIM_SPEED%ANI_HOHEI], true);
		break;
	case ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_hohei_atk[ani_count / ANIM_SPEED%ANI_HOHEI_ATK], true);
		break;
	}
}

int hohei::getNum(){
	return num;
}

void hohei::setNum(int i){
	num = i;
}

