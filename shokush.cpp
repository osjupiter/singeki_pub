#include "shokush.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
#define ANIM_SPEED_S 1

#define DIST_SHOKUSH 30
shokush::shokush(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_SHOKUSH){
	width = WID_SHOKUSH;
	height = HEI_SHOKUSH;
	y = WINDOW_Y - height;
	atk_type = RAND;
	dist = DIST_SHOKUSH - rand()%35;
	type = RAND;
	visible = false;

}

void shokush::main(int front){
	pre_state = state;
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		if (visible){

			changeState(UnitState::WAIT);
		}
		else{
			no_damage_flag = true;
		}

		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®

		break;
	case UnitState::ATK:
		if (!visible){
			changeState(UnitState::ST0);
		
		}
		else	state_change_flag = false;
		if (ani_count / ANIM_SPEED == 4){
			if (!stopper){
				Game::getIns()->effect_create(x, y, KIRAKIRA, dir, power,0,0,level);
				stopper = true;
				SoundController::getSE()->playSE("sound/“ä‚ÌŽèƒLƒ‰ƒLƒ‰‰¹.mp3", true);
				
			}
		}
		else { stopper = false; }

		if (ani_count / ANIM_SPEED == ANI_SHOKUSH_A){
			state_change_flag = true;
			changeState(UnitState::WAIT);
		}

		break;
	case UnitState::WAIT:

		break;
	case UnitState::ST0:   //oŒ»
		if (ani_count / ANIM_SPEED_S == ANI_SHOKUSH_S){
			changeState(UnitState::ATK);
			visible = true;
			no_damage_flag = false;
		}
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

void shokush::draw(int cx){
	switch (state){
	case UnitState::MOV:
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_shokush_a[level / 3][ani_count / ANIM_SPEED%ANI_SHOKUSH_A], true);
		break;
	case UnitState::ST0:
		DrawGraph(x - cx, y, Images::getIns()->g_shokush_s[level / 3][ani_count / ANIM_SPEED_S%ANI_SHOKUSH_S], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_shokush_a[level / 3][ani_count / ANIM_SPEED%ANI_SHOKUSH_A], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_shokush_a[level / 3][ani_count / ANIM_SPEED %ANI_SHOKUSH_A], true);
		break;
	}

	if (state != UnitState::MOV)enemy::draw(cx);

}
