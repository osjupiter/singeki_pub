#include "sharin.h"
#include "Images.h"
#include "Game.h"
#include "Status.h"
#include"SoundController.h"

#define ANIM_SPEED 2
#define ANIM_SPEED_DIE 2
#define DIST_SHARIN 200



sharin::sharin(int fx, int ln, int lv) : enemy(fx, ln, lv, UnitType::_SHARIN){
	width = WID_SHARIN;
	height = HEI_SHARIN;
	y = WINDOW_Y - height - line * 3;

	dist = dist + DIST_SHARIN;
	power = POWER_TANK *(1 * lv);
	hp = MAXHP_TANK + MAXHP_TANK*lv;
	speed = SPEED_TANK + 0.5*SPEED_TANK*lv;
	defense = DEFENSE_TANK*(1 + 0.8*lv);
	type = RAND;
	atk_type = A_TYPE_TANK;
	cost = COST_TANK + 40 * lv;
	atk_freq = 10;
	unit_type = UnitType::_SHARIN;
	maxhp = hp;

}


void sharin::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		if (x + width < 0) state = UnitState::DIE;
		break;
	case UnitState::ATK:
		if (ani_count / ANIM_SPEED == ANI_SHARIN -1){
			if (!atk){
				SoundController::getSE()->playSE("sound/taihou03.mp3");

				atk = true;
			}

		}
		else{ atk = false; }

		if (((ani_count / ANIM_SPEED) == ANI_SHARIN)){
			changeState(UnitState::WAIT);

		}
		break;
	case UnitState::WAIT:
		atk = false;
		break;
	case UnitState::DIE:

		if (ani_count == 1){
			Game::getIns()->effect_create(x + width / 2 - WID_NOMALEXP / 2, y + height / 2 - HEI_NOMALEXP / 2, NOMALEXP);
		}
		if (ani_count == 4)
			Game::getIns()->effect_create(x + width / 2 - WID_NOMALEXP / 2 + 10, y + height / 2 - HEI_NOMALEXP / 2, NOMALEXP);

		if (ani_count / 3 == 2){
			del();
		}
		break;

	}

}

void sharin::draw(int cx){
	switch (state){
	case UnitState::MOV:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_sharin_w[level / 3][ani_count / ANIM_SPEED%ANI_SHARIN], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_sharin_w[level / 3][ani_count / ANIM_SPEED%ANI_SHARIN], true);
		break;
	case UnitState::ATK:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_sharin_a[level / 3][ani_count / ANIM_SPEED%ANI_SHARIN], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_sharin_a[level / 3][ani_count / ANIM_SPEED%ANI_SHARIN], true);
		break;
	case UnitState::WAIT:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_sharin_w[level / 3][0], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_sharin_w[level / 3][0], true);
		break;
	case UnitState::DIE:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_sharin_w[level / 3][ani_count / ANIM_SPEED_DIE%ANI_SHARIN], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_sharin_w[level / 3][ani_count / ANIM_SPEED_DIE%ANI_SHARIN], true);
		break;
	}

	enemy::draw(cx);
}

