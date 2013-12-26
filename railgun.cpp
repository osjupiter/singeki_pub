#include "railgun.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int railgun::num = 0;

railgun::railgun(int fx, int fy, int ln, int lv) : enemy(fx, fy, ln, lv){

	power = POWER_RAILGUN*lv;
	hp = MAXHP_RAILGUN*lv;
	width = WID_RAILGUN;
	height = HEI_RAILGUN;
	num++;
	atk = false;
	defense = DEFENSE_RAILGUN*lv;
	type = RAND;
	atk_type = RAND;
	cost = COST_RAILGUN;
	atk_freq = A_FREQ_RAILGUN;
	stopper = false;
	speed = SPEED_RAILGUN;
}
void railgun::init(){
	num = 0;

}
void railgun::main(int front){
	enemy::main(front);
	//	state = ATK;
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		break;
	case ATK:
		atk = false;
		if ((ani_count / ANIM_SPEED) == ANI_RAILGUN - 1){
			if (!stopper){
				stopper = true;
				
			
			}
		}
		else{
			stopper = false;
		}

		if (((ani_count / ANIM_SPEED) == ANI_RAILGUN)){
			changeState(WAIT);

		}
		break;
	case UnitState::DIE:
		del();
		break;
	}
}

void railgun::draw(int cx){
	switch (state){
	case UnitState::MOV:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_rail[ani_count / ANIM_SPEED%ANI_RAILGUN], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_rail[ani_count / ANIM_SPEED%ANI_RAILGUN], true);
		break;
	case UnitState::ATK:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_rail[ani_count / ANIM_SPEED%ANI_RAILGUN], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_rail[ani_count / ANIM_SPEED%ANI_RAILGUN], true);
		break;
	case UnitState::WAIT:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_rail[ani_count / ANIM_SPEED%ANI_RAILGUN], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_rail[ani_count / ANIM_SPEED%ANI_RAILGUN], true);
		break;
	case UnitState::DIE:
		break;

	}

	unit::draw(cx);
}

int railgun::getNum(){
	return num;
}

void railgun::setNum(int i){
	num = i;
}

