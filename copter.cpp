#include "copter.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int copter::num = 0;

/*
int copter::power;
int copter::speed;
int copter::defense;
int copter::atk_freq;
int copter::atk_type;
int copter::clk;
int copter::cost;*/

copter::copter(int fx, int fy, int ln,int lv) : enemy(fx, fy, ln,lv){
	
	power = 0;
	hp = 500;
	width = WID_COPTER;
	height = HEI_COPTER;
	num++;
	atk = false;
	defense = 1;
	type = SKY;
	atk_type = RAND;
	cost = COST_COPTER;
	
}
void copter::init(){
	num = 0;

}
void copter::main(int front){
	enemy::main(front);
	//	state = ATK;
	switch (state){
	case MOV:
		x += 3*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		break;
	case ATK:
		if ((ani_count / ANIM_SPEED%ANI_COPTER)
			== ANI_COPTER - 1 && atk){
			atk = false;
			Game::getIns()->effect_create(x , y + 155, MISSILE,dir);
			Images::playSE("sound/misairu.mp3");
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

int copter::getPower(){
	return power;
}
int copter::getAtkType(){
	return atk_type;
}
void copter::damage(int d, int op_a_type){

	if (op_a_type == NONE || op_a_type == type){
		hp -= max(d - defense, 0);
		if (hp < 0){
			state = DIE;
		}
	}

}
void copter::del(){
	Game::getIns()->push_del_enemy(*(new shared_ptr<enemy>(this)));
	Game::getIns()->gainResource(cost);
}