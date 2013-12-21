#include "tank.h"
#include "Images.h"
#define ANIM_SPEED 3

int tank::num;

tank::tank(int fx, int fy, int ln) : enemy(fx, fy, ln){
	power = 10;
	hp = 400;
	width = WID_TANK;
	height = HEI_TANK;
	defense = 1;
	num++;
	type = RAND;
	atk_type = RAND;
}


void tank::main(int front){
	enemy::main(front);
	switch (state){
	case MOV:
		x -= 5; //とりあえず横移動
		if (x + width < 0) state = DIE;
		break;
	case ATK:
		break;
	case DIE:
		del();
		break;
		
	}
	
}

void tank::draw(int cx){
	switch (state){
	case MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_tank[ani_count / ANIM_SPEED%ANI_TANK], true);
		break;
	case ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_tank_atk[ani_count / ANIM_SPEED%ANI_TANK_ATK], true);
		break;
	}

	unit::draw(cx);

}

int tank::getNum(){
	return num;
}

void tank::setNum(int i){
	num = i;
}