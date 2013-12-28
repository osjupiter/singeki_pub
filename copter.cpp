#include "copter.h"
#include "Images.h"
#include "Game.h"
#include "Status.h"

#define ANIM_SPEED 3
#define ANIM_SPEED_DIE 3
#define DIST_COPTER 100;
int copter::num = 0;

copter::copter(int fx, int fy, int ln,int lv) : enemy(fx, fy, ln,lv){
	dist = dist + DIST_COPTER;
	power = POWER_COPTER*lv;
	hp = MAXHP_COPTER+0.5*MAXHP_COPTER*lv;
	width = WID_COPTER;
	height = HEI_COPTER;
	num++;
	atk = false;
	defense = DEFENSE_COPTER*lv;
	type = SKY;
	atk_type = RAND;
	cost = COST_COPTER + 150 * lv;
	atk_freq = A_FREQ_COPTER;
	stopper = false;
	speed = SPEED_COPTER + 0.5*SPEED_COPTER*lv;
	unit_type=UnitType::_COPTER;
	maxhp = hp;

}
void copter::init(){
	num = 0;

}
void copter::main(int front){
	enemy::main(front);
	//	state = ATK;
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //とりあえず横移動
		break;
	case ATK:
		atk = false;
		if ((ani_count / ANIM_SPEED)== ANI_COPTER - 1 ){
			if (!stopper){
				stopper = true;
				Game::getIns()->effect_create(x + width / 2-WID_MISSILE/2+10*dir, y + 140, MISSILE, dir,power,front);
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
		if (ani_count / ANIM_SPEED_DIE == ANI_COPTER_DIE ){
			del();
		}
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
		if (dir == LEFT)
			DrawGraph(x - cx, 0, Images::getIns()->g_copter_die[ani_count / ANIM_SPEED%ANI_COPTER_DIE], true);
		else
			DrawTurnGraph(x - cx, 0, Images::getIns()->g_copter_die[ani_count / ANIM_SPEED%ANI_COPTER_DIE], true);
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

