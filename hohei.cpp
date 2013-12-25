#include "hohei.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int hohei::num = 0;
hohei::hohei(int fx, int fy, int ln, shared_ptr<Parameter> pm) : musume(fx, fy, ln, pm){
	
	hp = param->getParam(MAXHP);
	width = WID_HOHEI;
	height = HEI_HOHEI;
	num++;
	type = RAND;
		
}

void hohei::init(){
	num = 0;
}

void hohei::main(int front){
	musume::main(front);
	switch (state){
	case MOV:
		x += param->getParam(SPEED); //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		break;
	case ATK:
		if (ani_count / ANIM_SPEED%ANI_HOHEI_ATK == 0)
			Images::playSE("sound/gun03.mp3",true);
			
		break;
	case DIE:
		y += vy;
		x += vx;
		vy -= 10;
		vx -= 5;
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

