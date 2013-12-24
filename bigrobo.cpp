#include "bigrobo.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int bigrobo::num = 0;

int bigrobo::maxhp;
int bigrobo::power;
int bigrobo::speed;
int bigrobo::defense;
int bigrobo::atk_freq;
int bigrobo::atk_type;
int bigrobo::clk;
int bigrobo::cost;

bigrobo::bigrobo(int fx, int fy, int ln) : musume(fx, fy, ln){
	hp = maxhp;
	width = WID_BIG;
	height = HEI_BIG;
	num++;
	type = RAND;
	atk = false;
	dist = width;
}

void bigrobo::init(){
	num = 0;
	maxhp = 500;
	power = 500;
	speed = 2;
	defense = 1;
	atk_freq = 5;
	atk_type = RAND;
	clk = CLK_BIG;
	cost = COST_BIG;
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
			power = 00;
		}
		if (!(ani_count / ANIM_SPEED%ANI_BIG_ATK == ANI_BIG_ATK - 1)){
			atk = true;
			power = 0;
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

int bigrobo::getPower(){
	return power;
}
int bigrobo::getAtkType(){
	return atk_type;
}
void bigrobo::damage(int d, int op_a_type){

	if (op_a_type == NONE || op_a_type == type){
		hp -= max(d - defense, 0);
		if (hp < 0){
			state = DIE;
		}
	}

}