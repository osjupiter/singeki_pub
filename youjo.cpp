#include "youjo.h"
#include "Game.h"

#define ANIM_SPEED 5
#define ANIM_SPEED_D 5
#define ANIM_SPEED_A 2
#define DIST_YOUJO 50
youjo::youjo(int fx, int ln) :musume(fx, ln, UnitType::_YOUJO){
	dist = dist + DIST_YOUJO;

	y = WINDOW_Y - HEI_YOUJO - line * 3;
	width = WID_YOUJO;
	height = HEI_YOUJO;
	atk = false;
	stopper = false;
	type = RAND;
	image = &(Images::getIns()->g_youjo_w[0]);
}

void youjo::main(int front){
	musume::main(front);
	atk = false;

	switch (state){
	case UnitState::MOV:
		x += param->getParam(SPEED); //‰¡ˆÚ“®
		break;
	case UnitState::ATK:
		x += param->getParam(SPEED) * 2;
		state_change_flag = false;
		if (x >= front) {
			state_change_flag = true;
			ani_count = 0;
			changeState(UnitState::ST0);
		}
		
/*
		state_change_flag = false;
		if ((ani_count / ANIM_SPEED == ANI_YOUJO_A - 2)){
			state_change_flag = true;
			changeState(UnitState::ST0);		
		}
*/
		break;
	case UnitState::ST0:
		state_change_flag = false;

		if ((ani_count / ANIM_SPEED_A == ANI_YOUJO_A - 2))
			no_die_flag = true;

		if ((ani_count / ANIM_SPEED_A == ANI_YOUJO_A -1)){
			Game::getIns()->effect_create(x, FIELD_H - HEI_SHOCK, SHOCK);
			shared_ptr<AttackRange> p(new AttackRange(x, x + WID_YOUJO, param->getParam(POWER), RAND));
			Game::getIns()->push_attack_list(p, MUSUME);
			image = 0;
			no_die_flag = false;
			changeState(UnitState::DIE);
		}
/*		no_die_flag = true;
		if (ani_count / ANIM_SPEED_A >= ANI_YOUJO_A){ 
				ani_count = (ANI_YOUJO_A - 2)*ANIM_SPEED_A; 
		}
		if(x >= front){
			Game::getIns()->effect_create(x, FIELD_H - HEI_SHOCK, SHOCK);

			shared_ptr<AttackRange> p(new AttackRange(x, x + WID_YOUJO, param->getParam(POWER), RAND));
			Game::getIns()->push_attack_list(p, MUSUME);
			image = 0;
			no_die_flag = false;
			changeState(UnitState::DIE);
		}
*/
		break;
	case UnitState::DIE:

		break;
	}
}

void youjo::draw(int cx){
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y , Images::getIns()->g_youjo_w[ani_count / ANIM_SPEED%ANI_YOUJO_W], true);
		character::draw(cx);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y+10, Images::getIns()->g_youjo_d[ani_count / ANIM_SPEED_D%ANI_YOUJO_D], true);
		character::draw(cx);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_youjo_w[ani_count / ANIM_SPEED%ANI_YOUJO_W], true);
		character::draw(cx);
		break;
	case UnitState::ST0:
		DrawGraph(x - cx, y, Images::getIns()->g_youjo_a[ani_count / ANIM_SPEED_A%ANI_YOUJO_A], true);
		break;
	case UnitState::DIE:
		//DrawGraph(x - cx, y + gap_y, Images::getIns()->g_kamikaze[ani_count / ANIM_SPEED%ANI_KAMIKAZE_ATK], true);
		if (image != NULL) DrawGraph(x - cx, y, *image, true);
	
		break;

	}

	
}