#include "tank.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3

int tank::num;
/*
int tank::power;
int tank::speed;
int tank::defense;
int tank::atk_freq;
int tank::atk_type;
int tank::clk;
int tank::cost;*/

tank::tank(int fx, int fy, int ln,int lv) : enemy(fx, fy, ln,lv){
	power = 5;
	hp = 400*lv;
	width = WID_TANK;
	height = HEI_TANK;
	defense = 2*lv;
	num++;
	type = RAND;
	atk_type = RAND;
	cost = COST_TANK;
}

void tank::init(){
	num = 0;	
/*	power = 10;
	speed = 4;
	defense = 1;
	atk_freq = 5;
	atk_type = RAND;
	clk = 0;
	cost = COST_TANK;*/
}

void tank::main(int front){
	enemy::main(front);
	switch (state){
	case MOV:
		x += 5*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
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


int tank::getPower(){
	return power;
}
int tank::getAtkType(){
	return atk_type;
}
void tank::damage(int d, int op_a_type){

	if (op_a_type == NONE || op_a_type == type){
		hp -= max(d - defense, 0);
		if (hp < 0){
			state = DIE;
		}
	}

}

void tank::del(){
	Game::getIns()->push_del_enemy(*(new shared_ptr<enemy>(this)));
	Game::getIns()->gainResource(cost);
}