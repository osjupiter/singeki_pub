#include "steam.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 6

steam::steam(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_STEAM){
	width = WID_STEAM;
	height = HEI_STEAM;
	y = WINDOW_Y - height;
	x = x - width + 200;
	dist = 200;
	type = ALL;
}

void steam::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
//		x += speed*dir; 
		if (x + width < 0) state = UnitState::DIE;
		break;
	case UnitState::ATK:
		if (ani_count / ANIM_SPEED%ANI_STEAM_A == 2){
			if (!atk){

				atk = true;
			}

		}
		else{ atk = false; }

		if (((ani_count / ANIM_SPEED) == ANI_STEAM_A)){
			changeState(UnitState::WAIT);

		}
		break;
	case UnitState::WAIT:
		atk = false;
		break;
	case UnitState::DIE:

			del();
		break;
	case UnitState::ST0:

		break;
	}
	
}

void steam::draw(int cx){
	switch (state){
	case UnitState::MOV:
			DrawGraph(x - cx, y, Images::getIns()->g_steam_w[ani_count / ANIM_SPEED%ANI_STEAM_W], true);
		break;
	case UnitState::ATK:
			DrawGraph(x - cx, y, Images::getIns()->g_steam_a[ani_count / ANIM_SPEED%ANI_STEAM_A], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_steam_w[ani_count / ANIM_SPEED%ANI_STEAM_W], true);
		break;
	case UnitState::DIE:
//			DrawGraph(x - cx, y, Images::getIns()->g_steam_dei[level / 3][ani_count / ANIM_SPEED_DIE%ANI_STEAM_DEL], true);
		break;
	}

	enemy::draw(cx);
}
