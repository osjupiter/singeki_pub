#include "beebar.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3

beebar::beebar(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_BEEBAR){
	width = WID_BEEBAR_W;
	height = HEI_BEEBAR_W;
	y = 100 + ln * 5;
	atk_type = RAND;
	dist = dist%50 + 170;
	type = SKY;
}

void beebar::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		if (x + width < 0) state = UnitState::DIE;
		break;
	case UnitState::ATK:
		atk = false;
		if (ani_count / ANIM_SPEED%ANI_BEEBAR_A == 3){
			if (!stopper){
				if (!atk){
					stopper = true;
					atk = true;
				}
			}
		}
		else{ stopper = false; }

		if (((ani_count / ANIM_SPEED) == ANI_BEEBAR_A)){
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

void beebar::draw(int cx){
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_beebar_w[level / 3][ani_count / ANIM_SPEED%ANI_BEEBAR_W], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx - 120, y, Images::getIns()->g_beebar_a[level / 3][ani_count / ANIM_SPEED%ANI_BEEBAR_A], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_beebar_w[level / 3][ani_count / ANIM_SPEED%ANI_BEEBAR_W], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_beebar_w[level / 3][ani_count / ANIM_SPEED%ANI_BEEBAR_W], true);
		break;
	}

	enemy::draw(cx);
}
