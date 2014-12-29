#include "gajigaji.h"
#include "Images.h"
#include "Game.h"
#include "Status.h"
#include"SoundController.h"

#define ANIM_SPEED 3
#define ANIM_SPEED_DIE 2
#define DIST_GAJIGAJI 0


gajigaji::gajigaji(int fx, int ln, int lv) : enemy(fx, ln, lv, UnitType::_GAJIGAJI){
	width = WID_GAJIGAJI;
	height = HEI_GAJIGAJI_W;
	y = WINDOW_Y - height - line * 3;

	dist = DIST_GAJIGAJI;
	type = RAND;
	
}


void gajigaji::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		if (x + width < 0) state = UnitState::DIE;
		break;
	case UnitState::ATK:
		if (ani_count / ANIM_SPEED%ANI_GAJIGAJI_A == 3){
			if (!stopper){
				if (!atk){
					atk = true;
					stopper = true;
					SoundController::getSE()->playSE("sound/ƒKƒWƒKƒWƒƒJ‰¹iC³j.mp3");

				}

			}
			else{ atk = false; }
		}else { stopper = false; }
		
		if (((ani_count / ANIM_SPEED) == ANI_GAJIGAJI_A)){
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

void gajigaji::draw(int cx){
	switch (state){
	case UnitState::MOV:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_gajigaji_w[level / 3][ani_count / ANIM_SPEED%ANI_GAJIGAJI_W], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_gajigaji_w[level / 3][ani_count / ANIM_SPEED%ANI_GAJIGAJI_W], true);
		break;
	case UnitState::ATK:
		if (dir == LEFT)
			DrawGraph(x - cx, y-20, Images::getIns()->g_gajigaji_a[level / 3][ani_count / ANIM_SPEED%ANI_GAJIGAJI_A], true);
		else
			DrawTurnGraph(x - cx, y-20, Images::getIns()->g_gajigaji_a[level / 3][ani_count / ANIM_SPEED%ANI_GAJIGAJI_A], true);
		break;
	case UnitState::WAIT:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_gajigaji_w[level / 3][ani_count / ANIM_SPEED%ANI_GAJIGAJI_W], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_gajigaji_w[level / 3][ani_count / ANIM_SPEED%ANI_GAJIGAJI_W], true);
		break;
	case UnitState::DIE:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_gajigaji_w[level / 3][ani_count / ANIM_SPEED_DIE%ANI_GAJIGAJI_W], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_gajigaji_w[level / 3][ani_count / ANIM_SPEED_DIE%ANI_GAJIGAJI_W], true);
		break;
	}

	enemy::draw(cx);
}



