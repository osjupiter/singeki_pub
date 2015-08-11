#include "copter.h"
#include "Images.h"
#include "Game.h"
#include "Status.h"

#define ANIM_SPEED 3
#define ANIM_SPEED_DIE 3
#define DIST_COPTER 140;
int copter::num = 0;

copter::copter(int fx, int ln,int lv) : enemy(fx,ln,lv,UnitType::_COPTER){
	dist = dist + DIST_COPTER;
	
	width = WID_COPTER;
	height = HEI_COPTER;
	num++;
	atk = false;
	y = 50 - line * 3;
	
	type = SKY;

	stopper = false;

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
	case UnitState::ATK:
		atk = false;
		if ((ani_count / ANIM_SPEED)== ANI_COPTER - 1 ){
			if (!stopper){
				stopper = true;
				Game::getIns()->effect_create(x + width / 2-WID_MISSILE/2+10*dir, y + 140, MISSILE, dir,power,front);
				SoundController::getSE()->playSE("sound/misairu.mp3");
			}
		}
		else{
			stopper = false;
			state_change_flag = false;
		}
	
		if (((ani_count / ANIM_SPEED) == ANI_COPTER)){
			state_change_flag = true;
			changeState(UnitState::WAIT);
			
		}
		break;
	case UnitState::DIE:

		if (ani_count==1)
			SoundController::getSE()->playSE("sound/sen_ge_hasai02.mp3");

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

	enemy::draw(cx);
}

int copter::getNum(){
	return num;
}

void copter::setNum(int i){
	num = i;
}

