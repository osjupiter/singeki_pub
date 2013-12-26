#include "copter.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int copter::num = 0;

copter::copter(int fx, int fy, int ln,int lv) : enemy(fx, fy, ln,lv){
	
	power = POWER_COPTER*lv;
	hp = MAXHP_COPTER*lv;
	width = WID_COPTER;
	height = HEI_COPTER;
	num++;
	atk = false;
	defense = DEFENSE_COPTER*lv;
	type = SKY;
	atk_type = RAND;
	cost = COST_COPTER;
	atk_freq = A_FREQ_COPTER;
	stopper = false;
	speed = SPEED_COPTER;
	unit_type=UnitType::_COPTER;
}
void copter::init(){
	num = 0;

}
void copter::main(int front){
	enemy::main(front);
	//	state = ATK;
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		break;
	case ATK:
		atk = false;
		if ((ani_count / ANIM_SPEED)== ANI_COPTER - 1 ){
			if (!stopper){
				stopper = true;
				Game::getIns()->effect_create(x + width / 2, y + 155, MISSILE, dir,power,front);
				Images::playSE("sound/misairu.mp3");
			}
		}
		else{
			stopper = false;
		}
	
		if (((ani_count / ANIM_SPEED) == ANI_COPTER)){ 
			changeState(WAIT);
			
		}
		break;
	case UnitState::DIE:
		del();
		break;
	}
}

void copter::draw(int cx){
	switch (state){
	case UnitState::MOV:
		if (dir==LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_copter[ani_count / ANIM_SPEED%ANI_COPTER], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_copter[ani_count / ANIM_SPEED%ANI_COPTER], true);
		break;
	case UnitState::ATK:
		if (dir==LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_copter[ani_count / ANIM_SPEED%ANI_COPTER], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_copter[ani_count / ANIM_SPEED%ANI_COPTER], true);
		break;
	case UnitState::WAIT:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_copter[ani_count / ANIM_SPEED%ANI_COPTER], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_copter[ani_count / ANIM_SPEED%ANI_COPTER], true);
		break;
	case UnitState::DIE:
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

