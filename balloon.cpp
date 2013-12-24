#include "balloon.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 5
int balloon::num = 0;

int balloon::maxhp;
int balloon::power;
int balloon::speed;
int balloon::defense;
int balloon::atk_freq;
int balloon::atk_type;
int balloon::clk;
int balloon::cost;

balloon::balloon(int fx, int fy, int ln) : musume(fx, fy, ln){
	dist = -dist+50;
	hp = maxhp;
	width = WID_BALLOON;
	height = HEI_BALLOON;
	num++;
	atk = false;
	type = SKY;
}
void balloon::init(){
	num = 0;
	maxhp = 500;
	power = 0;
	speed = 4;
	defense = 1;
	atk_freq = 5;
	atk_type = RAND;
	clk = CLK_BALLOON;
	cost = COST_BALLOON;
}
void balloon::main(int front){
	musume::main(front);
//	state = ATK;
	switch (state){
	case MOV:
		x += 4; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		break;
	case ATK:
		
		if ((ani_count / ANIM_SPEED%ANI_BALLOON_ATK)
			== ANI_BALLOON_ATK - 1 && atk){
			atk = false;
			Game::getIns()->effect_create(x + 59, y + 111, BOMB);
		}
		if (!((ani_count / ANIM_SPEED%ANI_BALLOON_ATK)
			== ANI_BALLOON_ATK - 1))atk = true;
			break;
	case DIE:
		del();
		break;
	}
}

void balloon::draw(int cx){
	switch (state){
	case MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_balloon[ani_count / ANIM_SPEED%ANI_BALLOON], true);
		break;
	case ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_balloon_atk[ani_count / ANIM_SPEED%ANI_BALLOON_ATK], true);

		break;
	case DIE:
		break;

	}

	unit::draw(cx);
}

int balloon::getNum(){
	return num;
}

void balloon::setNum(int i){
	num = i;
}

int balloon::getPower(){
	return power;
}
int balloon::getAtkType(){
	return atk_type;
}
void balloon::damage(int d, int op_a_type){

	if (op_a_type == NONE || op_a_type == type){
		hp -= max(d - defense, 0);
		if (hp < 0){
			state = DIE;
		}
	}

}