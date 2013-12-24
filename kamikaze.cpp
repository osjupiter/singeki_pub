#include "kamikaze.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int kamikaze::num = 0;

int kamikaze::maxhp;
int kamikaze::power;
int kamikaze::speed;
int kamikaze::defense;
int kamikaze::atk_freq;
int kamikaze::atk_type;
int kamikaze::clk;
int kamikaze::cost;

kamikaze::kamikaze(int fx, int fy, int ln) : musume(fx, fy, ln){
	dist = -dist + 100;
	
	hp = maxhp;
	width = WID_KAMIKAZE;
	height = HEI_KAMIKAZE;
	num++;
	atk = false;
	type = SKY;
	gap_y = 0;
	gap_vy=1;
}
void kamikaze::init(){
	num = 0;
	maxhp = 500;
	power = 10;
	speed = 4;
	defense = 1;
	atk_freq = 5;
	atk_type = SKY;
	clk = CLK_KAMIKAZE;
	cost = COST_KAMIKAZE;
}
void kamikaze::main(int front){
	musume::main(front);
	//	state = ATK;
	switch (state){
	case MOV:
		x += 4; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
	/*	if (gap_y == -3)
			gap_vy = gap_vy*-1;
		else if (gap_y == 0)
			gap_vy = gap_vy*-1;
		gap_y+=gap_vy;*/

		break;
	case ATK:
	/*	if (gap_y == -3)
			gap_vy = gap_vy*-1;
		else if (gap_y == 0)
			gap_vy = gap_vy*-1;
		gap_y += gap_vy;
		*/
		if ((ani_count / ANIM_SPEED%ANI_KAMIKAZE_ATK)
			== ANI_KAMIKAZE_ATK - 1 && atk){
			atk = false;
//			Game::getIns()->effect_create(x + 59, y + 111, BOMB);
		}
		if (!((ani_count / ANIM_SPEED%ANI_KAMIKAZE_ATK)
			== ANI_KAMIKAZE_ATK - 1))atk = true;
		break;
	case DIE:
		del();
		break;
	}
}

void kamikaze::draw(int cx){
	switch (state){
	case MOV:
		DrawGraph(x - cx, y+gap_y, Images::getIns()->g_kamikaze[ani_count / ANIM_SPEED%ANI_KAMIKAZE], true);
		break;
	case ATK:
		DrawGraph(x - cx, y + gap_y, Images::getIns()->g_kamikaze_atk[ani_count / ANIM_SPEED%ANI_KAMIKAZE_ATK], true);
		break;
	case DIE:
		break;

	}

	unit::draw(cx);
}

int kamikaze::getNum(){
	return num;
}

void kamikaze::setNum(int i){
	num = i;
}

int kamikaze::getPower(){
	return power;
}
int kamikaze::getAtkType(){
	return atk_type;
}
void kamikaze::damage(int d, int op_a_type){

	if (op_a_type == NONE || op_a_type == type){
		hp -= max(d - defense, 0);
		if (hp < 0){
			state = DIE;
		}
	}

}