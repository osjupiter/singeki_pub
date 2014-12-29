#include "kuroshimi.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 5
#define DIST_KUROSHIMI 200
kuroshimi::kuroshimi(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_KUROSHIMI){
	width = WID_KUROSHIMI;
	height = HEI_KUROSHIMI;
	y = WINDOW_Y - height;
	atk_type = ALL;
	dist = dist + DIST_KUROSHIMI;
	type = ALL;
}

void kuroshimi::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		if (x + width < 0) state = UnitState::DIE;
		break;
	case UnitState::ATK:
		atk = false;
		if (ani_count / ANIM_SPEED%ANI_KUROSHIMI_A == 2){
			if (!stopper){
				if (!atk){
					stopper = true;
				}
			}
		}
		else{ stopper = false; }

		if (((ani_count / ANIM_SPEED) == ANI_KUROSHIMI_A)){
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

void kuroshimi::draw(int cx){
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_kuroshimi_w[ani_count / ANIM_SPEED%ANI_KUROSHIMI_W], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_kuroshimi_a[ani_count / ANIM_SPEED%ANI_KUROSHIMI_A], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_kuroshimi_a[ani_count / ANIM_SPEED%ANI_KUROSHIMI_A], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_kuroshimi_a[ani_count / ANIM_SPEED %ANI_KUROSHIMI_A], true);
		break;
	}

	enemy::draw(cx);
}
