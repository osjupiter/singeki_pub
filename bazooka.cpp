#include "bazooka.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int bazooka::num = 0;

int bazooka::maxhp;
int bazooka::power;
int bazooka::speed;
int bazooka::defense;
int bazooka::atk_freq;
int bazooka::atk_type;
int bazooka::clk;
int bazooka::cost;

bazooka::bazooka(int fx, int fy, int ln) : musume(fx, fy, ln){
	hp = maxhp;
	width = WID_BAZOOKA;
	height = HEI_BAZOOKA;
	num++;
	type = RAND;
}
void bazooka::init(){
	num = 0;
	maxhp = 500;
	power = 10;
	speed = 4;
	defense = 1;
	atk_freq = 5;
	atk_type = RAND;
	clk = CLK_BAZOOKA;
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

int bazooka::getPower(){
	return power;
}
int bazooka::getAtkType(){
	return atk_type;
}
void bazooka::damage(int d, int op_a_type){

	if (op_a_type == NONE || op_a_type == type){
		hp -= max(d - defense, 0);
		if (hp < 0){
			state = DIE;
		}
	}

}