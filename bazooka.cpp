#include "bazooka.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int bazooka::num = 0;

bazooka::bazooka(int fx, int fy, int ln) : musume(fx, fy, ln){
	power = 10;
	hp = 200;
	width = WID_BAZOOKA;
	height = HEI_BAZOOKA;
	num++;
	type = RAND;
	defense = 1;
	atk_type = RAND;
	cost = COST_BAZOOKA;
}

void bazooka::main(int front){
	musume::main(front);
	switch (state){
	case MOV:
		x += 4; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		break;
	case DIE:
		y += vy;
		x += vx;
		vy -= 10;
		vx -= 5;
		if (y + height<0)
			del();
		break;
	}
}

void bazooka::draw(int cx){

	switch (state){
	case MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_bazooka[ani_count / ANIM_SPEED%ANI_BAZOOKA], true);
		break;
	case ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_bazooka_atk[ani_count / ANIM_SPEED%ANI_BAZOOKA_ATK], true);
		break;
	case DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_bazooka_atk[0], true);
		break;
	}

	unit::draw(cx);

}

int bazooka::getNum(){
	return num;
}

void bazooka::setNum(int i){
	num = i;
}

