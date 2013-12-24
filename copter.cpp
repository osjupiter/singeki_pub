#include "copter.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int copter::num = 0;

copter::copter(int fx, int fy, int ln,int lv) : enemy(fx, fy, ln,lv){
	
	power = 0;
	hp = 200;
	width = WID_COPTER;
	height = HEI_COPTER;
	num++;
	atk = false;
	defense = 1;
	type = SKY;
	atk_type = RAND;
	cost = COST_COPTER;
}

void copter::main(int front){
	enemy::main(front);
	//	state = ATK;
	switch (state){
	case MOV:
		x += 3*dir; //�Ƃ肠�������ړ�
		break;
	case ATK:
		if ((ani_count / ANIM_SPEED%ANI_COPTER)
			== ANI_COPTER - 1 && atk){
			atk = false;
			Game::getIns()->effect_create(x , y + 155, MISSILE,dir);
		}
		if (!((ani_count / ANIM_SPEED%ANI_COPTER)
			== ANI_COPTER - 1))atk = true;
		break;
	case DIE:
		del();
		break;
	}
}

void copter::draw(int cx){
	switch (state){
	case MOV:
		if (dir==LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_copter[ani_count / ANIM_SPEED%ANI_COPTER], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_copter[ani_count / ANIM_SPEED%ANI_COPTER], true);
		break;
	case ATK:
		if (dir==LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_copter[ani_count / ANIM_SPEED%ANI_COPTER], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_copter[ani_count / ANIM_SPEED%ANI_COPTER], true);
		break;
	case DIE:
		break;

	}

	unit::draw(cx);
}

int copter::getNum(){
	return num;
}

void copter::setNum(int i){
	num = i;
}
