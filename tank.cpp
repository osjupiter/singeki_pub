#include "tank.h"
#include "Images.h"
#include "Game.h"
#include "Status.h"

#define ANIM_SPEED 3
#define ANIM_SPEED_DIE 2
#define DIST_TANK 150

int tank::num;


tank::tank(int fx, int fy, int ln,int lv) : enemy(fx, fy, ln,lv){
	width = WID_TANK;
	height = HEI_TANK;


	dist = dist + DIST_TANK;
	power = POWER_TANK +POWER_TANK*lv;
	hp = MAXHP_TANK+MAXHP_TANK*lv;
	speed = SPEED_TANK + 0.5*SPEED_TANK*lv;
	defense = DEFENSE_TANK*lv;
	num++;
	type = RAND;
	atk_type = A_TYPE_TANK;
	cost = COST_TANK+40*lv;
	atk_freq = A_FREQ_TANK-0.05*A_FREQ_TANK*lv;
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
			
		}
		else{ atk = false; }

		if (((ani_count / ANIM_SPEED) == ANI_TANK)){
			changeState(WAIT);

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
		if (dir==LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_tank[level/3][ani_count / ANIM_SPEED%ANI_TANK], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_tank[level / 3][ani_count / ANIM_SPEED%ANI_TANK], true);
		break;
	case UnitState::ATK:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_tank_atk[level / 3][ani_count / ANIM_SPEED%ANI_TANK_ATK], true);
		else 
			DrawTurnGraph(x - cx, y, Images::getIns()->g_tank_atk[level / 3][ani_count / ANIM_SPEED%ANI_TANK_ATK], true);
		break;
	case UnitState::WAIT:
		if (dir==LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_tank_atk[level / 3][ani_count / ANIM_SPEED%ANI_TANK_ATK], true);
		else 
			DrawTurnGraph(x - cx, y, Images::getIns()->g_tank_atk[level / 3][ani_count / ANIM_SPEED%ANI_TANK_ATK], true);
		break;
	case UnitState::DIE:
		if (dir==LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_tank_dei[level / 3][ani_count / ANIM_SPEED_DIE%ANI_TANK_DEL], true);
		else 
			DrawTurnGraph(x - cx, y, Images::getIns()->g_tank_dei[level / 3][ani_count / ANIM_SPEED_DIE%ANI_TANK_DEL], true);
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


