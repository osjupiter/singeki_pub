#include "tank.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
#define ANIM_SPEED_DIE 1

int tank::num;


tank::tank(int fx, int fy, int ln,int lv) : enemy(fx, fy, ln,lv){
	power = POWER_TANK;
	hp = MAXHP_TANK*lv;
	width = WID_TANK;
	height = HEI_TANK;
	speed = SPEED_TANK;
	defense = DEFENSE_TANK*lv;
	num++;
	type = RAND;
	atk_type = A_TYPE_TANK;
	cost = COST_TANK;
	atk_freq = A_FREQ_TANK;
	unit_type=UnitType::_TANK;
}


void tank::init(){
	num = 0;	
}


void tank::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		if (x + width < 0) state = DIE;
		break;
	case UnitState::ATK:
		if (ani_count / ANIM_SPEED%ANI_TANK_ATK == 2){
			if (!atk){
				Images::playSE("sound/taihou03.mp3");
				atk = true;
			}
			else{ atk = false; }
		}
		break;
	case UnitState::WAIT:
		atk = false;
		break;
	case UnitState::DIE:
		if (ani_count / ANIM_SPEED_DIE >= ANI_TANK_DEL){
			del();
		}
		break;
		
	}
	
}

void tank::draw(int cx){
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_tank[ani_count / ANIM_SPEED%ANI_TANK], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_tank_atk[ani_count / ANIM_SPEED%ANI_TANK_ATK], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_tank_atk[ani_count / ANIM_SPEED%ANI_TANK_ATK], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_tank_dei[ani_count / ANIM_SPEED_DIE%ANI_TANK_DEL], true);
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


