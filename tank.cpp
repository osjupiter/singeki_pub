#include "tank.h"
#include "Images.h"
#define ANIM_SPEED 3

int tank::num;

tank::tank(int fx, int fy, int ln) : enemy(fx, fy, ln){
	power = 4;
	hp = 200;
	width = WID_TANK;
	height = HEI_TANK;
	num++;
}
void tank::main(int front){
	enemy::main(front);
	if (state == MOV)x -= 4; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
	if (x > FIELD_W * 15) life = false;
	
	
}

void tank::draw(int cx){
	switch (state){
	case MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_tank[ani_count / ANIM_SPEED%ANI_TANK], true);
		break;
	case ATK:
		DrawTurnGraph(x - cx-15, y, Images::getIns()->g_tank_atk[ani_count / ANIM_SPEED%ANI_TANK_ATK], true);
		break;
	}
}

int tank::getNum(){
	return num;
}

void tank::setNum(int i){
	num = i;
}