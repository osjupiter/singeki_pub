#include "senkoutei.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
#define DIST_SENKOU 120
senkoutei::senkoutei(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_SENKOUTEI){
	width = WID_SENKOU;
	height = HEI_SENKOU;
	y = WINDOW_Y - height;
	atk_type = ALL;
	dist = rand()%40 + DIST_SENKOU;
	type = RAND;
}

void senkoutei::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		if (x + width < 0) state = UnitState::DIE;
		break;
	case UnitState::ATK:
		atk = false;
		if (ani_count / ANIM_SPEED%ANI_SENKOU_A == 2){
			if (!stopper){
					
					Game::getIns()->effect_create(x + width / 2 - WID_GYORAI / 2 + 10 * dir, y +220-95, GYORAI, dir, power, front, atk_position,level);
					SoundController::getSE()->playSE("sound/misairu.mp3");
					stopper = true;
			}
		}
		else{ stopper = false; }

		if (((ani_count / ANIM_SPEED) == ANI_SENKOU_A)){
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

void senkoutei::draw(int cx){
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_senkoutei_w[level / 3][ani_count / ANIM_SPEED%ANI_SENKOU_W], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_senkoutei_a[level / 3][ani_count / ANIM_SPEED%ANI_SENKOU_A], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_senkoutei_w[level / 3][ani_count / ANIM_SPEED%ANI_SENKOU_W], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_senkoutei_w[level / 3][ani_count / ANIM_SPEED %ANI_SENKOU_W], true);
		break;
	}

	enemy::draw(cx);
}
