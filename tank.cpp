#include "tank.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3

int tank::num;


tank::tank(int fx, int fy, int ln,int lv) : enemy(fx, fy, ln,lv){
	power = 5;
	hp = 400*lv;
	width = WID_TANK;
	height = HEI_TANK;
	speed = 5;
	defense = 2*lv;
	num++;
	type = RAND;
	atk_type = RAND;
	cost = COST_TANK;
}

void tank::init(){
	num = 0;	

}

void tank::main(int front){
	enemy::main(front);
	switch (state){
	case MOV:
		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		if (x + width < 0) state = DIE;
		break;
	case ATK:
		if (ani_count / ANIM_SPEED%ANI_TANK_ATK == 2){
			Images::playSE("sound/taihou03.mp3");
		}
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


