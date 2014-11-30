#include "bigrobo.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
#define DIST_BIG 0
int bigrobo::num = 0;



bigrobo::bigrobo(int fx, int ln) : musume(fx, ln, UnitType::_BIG){
	dist = rand()%50-10;
	width = WID_BIG;
	height = HEI_BIG;
	num++;
	type = RAND;
	atk = false;
	dist = width;
	y = WINDOW_Y - HEI_BIG + line * 3;
	stopper = false;
}

void bigrobo::init(){
	num = 0;	
}

void bigrobo::main(int front){
	musume::main(front);

	switch (state){		
	case UnitState::MOV:
		x += param->getParam(SPEED); //���ړ�
		break;
	case UnitState::ATK:
		
		if (ani_count / ANIM_SPEED % ANI_BIG_ATK == ANI_BIG_ATK - 1 ){
			if (!stopper){
				Game::getIns()->effect_create(x + 95, FIELD_H - HEI_SHOCK, SHOCK);
				shared_ptr<AttackRange> p(new AttackRange(x + 120, x + 120+ WID_SHOCK, param->getParam(POWER), RAND));
				Game::getIns()->push_attack_list(p, MUSUME);
				SoundController::getSE()->playSE("sound/sen_ge_hasai02.mp3");
				state_change_flag = true;
				changeState(UnitState::WAIT);
				stopper=true;
			}
		}
		else {
			stopper = false;
		}
		if ((ani_count / ANIM_SPEED == ANI_BIG_ATK )){
			
			stopper = false;
		}
		else{
			state_change_flag = false;
		}
		break;
	case UnitState::DIE:
		
		break;
	}
}

void bigrobo::draw(int cx){
	
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_robo[ani_count / ANIM_SPEED%ANI_BIG], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx-26, y, Images::getIns()->g_robo_atk[ani_count / ANIM_SPEED%ANI_BIG_ATK], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx-26, y, Images::getIns()->g_robo_atk[0], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_robo[0], true);
		break;
	}

	character::draw(cx);

}

int bigrobo::getNum(){
	return num;
}

void bigrobo::setNum(int i){
	num = i;
}

