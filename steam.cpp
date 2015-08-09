#include "steam.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 6

steam::steam(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_STEAM){
	width = WID_STEAM;
	height = HEI_STEAM;
	y = WINDOW_Y - height+20;
	x = x - width + 200+165;
	dist = 1000;
	type = ALL;
	atk_type = ALL;
	dx = x - 165;
}

void steam::main(int front){
	int d = defense;
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
//		x += speed; 
		if (x + width < 0) state = UnitState::DIE;
		break;

	case UnitState::ATK:
		state_change_flag = false;
		if ((ani_count / ANIM_SPEED%ANI_STEAM_A >7)
			&& (ani_count / ANIM_SPEED%ANI_STEAM_A <12)){
			no_damage_flag = true;
		}
		else { no_damage_flag = false; }
		if (ani_count / ANIM_SPEED%ANI_STEAM_A == 10){
			if (!stopper){
				if (!atk){
					shared_ptr<AttackRange> p(new AttackRange(x + 50, x + 550, param->getParam(POWER), SKY));
					Game::getIns()->push_attack_list(p, ENEMY);
					stopper = true;
				}
			}
		}
		else if (ani_count / ANIM_SPEED%ANI_STEAM_A == 12){
			if (!stopper){
				if (!atk){
					SoundController::getSE()->playSE("sound/スチームパンク（地割れ）.mp3",true);

					shared_ptr<AttackRange> p(new AttackRange(x- (1500), x + 550, param->getParam(POWER), RAND));
					Game::getIns()->push_attack_list(p, ENEMY);
					stopper = true;
				}
			}
		}
		else{ stopper = false; };
		

		if (((ani_count / ANIM_SPEED) == ANI_STEAM_A)){
			state_change_flag = true;
			changeState(UnitState::ST0);
		}

		break;
	case UnitState::WAIT:
		atk = false;
		break;
	case UnitState::DIE:
		del();
		break;
	case UnitState::ST0:
		state_change_flag = false;
		if (ani_count / ANIM_SPEED==ANI_STEAM_F){
			state_change_flag = true;
			changeState(UnitState::MOV);
		}

		break;
	}
	
}

void steam::draw(int cx){
	switch (state){
	case UnitState::MOV:
			DrawGraph(dx - cx, y, Images::getIns()->g_steam_w[ani_count / ANIM_SPEED%ANI_STEAM_W], true);
		break;
	case UnitState::ATK:
			DrawGraph(dx - cx, y, Images::getIns()->g_steam_a[ani_count / ANIM_SPEED%ANI_STEAM_A], true);
		break;
	case UnitState::WAIT:
		DrawGraph(dx - cx, y, Images::getIns()->g_steam_w[ani_count / ANIM_SPEED%ANI_STEAM_W], true);
		break;
	case UnitState::DIE:
//			DrawGraph(x - cx, y, Images::getIns()->g_steam_dei[level / 3][ani_count / ANIM_SPEED_DIE%ANI_STEAM_DEL], true);
		break;
	case UnitState::ST0:
		DrawGraph(dx - cx, y, Images::getIns()->g_steam_f[(ANI_STEAM_F-1) - ani_count / ANIM_SPEED%ANI_STEAM_F], true);
		break;
	}

	enemy::drawBossHP(dx,cx,y+height/2);
}
