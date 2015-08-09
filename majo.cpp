#include "majo.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 4
#define ANIM_SPEED_M 2

#define DIST_MAJO 200


majo::majo(int fx, int ln) : musume(fx, ln, UnitType::_MAJO){
	dist = dist + DIST_MAJO;
	width = WID_MAJO_W;
	height = HEI_MAJO;
	stopper = false;
	type = SKY;
	maho_count = -1;
	y = 150 - line * 7;
}


void majo::main(int front){
	musume::main(front);

	switch (state){
	case UnitState::MOV:
		x += param->getParam(SPEED) * dir; //‰¡ˆÚ“®
		break;
	case UnitState::ATK:
		state_change_flag = false;
		if (ani_count == 1){
			SoundController::getSE()->playSE("sound/–‚•ûw.mp3");
		}
		if (ani_count > 1 && maho_count<ANI_MAHOJIN-1){
			maho_count++;
		}
		if (ani_count / ANIM_SPEED == ANI_MAJO_A - 1){
			if (!stopper){
				if (!atk){
					Game::getIns()->effect_create(x + 76 - 36, y, MAHOU, dir, param->getParam(POWER),x+width+ dist/*front*/, FIELD_H - HEI_MAHOU);

//					Game::getIns()->effect_create(front, FIELD_H - HEI_EXP, EXP);
//						shared_ptr<AttackRange> p(new AttackRange(front, front + WID_EXP - 10, param->getParam(POWER), RAND));

					//	shared_ptr<AttackRange> p(new AttackRange(x + width + dist, x + width + dist + WID_EXP - 10, param->getParam(POWER), RAND));
			//		Game::getIns()->push_attack_list(p, MUSUME);
					stopper = true;
					
				}
			}
			else {
				atk = false;
			}
		}
		else { stopper = false; }
		if ((ani_count / ANIM_SPEED == ANI_MAJO_A)){
			state_change_flag = true;
			maho_count = -1;
			changeState(UnitState::WAIT);
			atk = false;
		}

		break;
	case UnitState::DIE:

		break;

	}
}
void majo::draw(int cx){

	switch (state){
	case UnitState::MOV:
		//DrawGraph(x - cx, y, Images::getIns()->g_majo_w[ani_count / ANIM_SPEED%ANI_MAJO_W], true);
		character::draw(cx, x, y, Images::getIns()->g_majo_w[ani_count / ANIM_SPEED%ANI_MAJO_W]);
		break;
	case UnitState::ATK:
//		DrawGraph(x - cx, y, Images::getIns()->g_majo_a[ani_count / ANIM_SPEED%ANI_MAJO_A], true);
		character::draw(cx, x, y, Images::getIns()->g_majo_a[ani_count / ANIM_SPEED%ANI_MAJO_A]);
		if (dir == RIGHT){
			DrawGraph(x - cx+76-36, y, Images::getIns()->g_mahojin[maho_count%ANI_MAHOJIN], true);
		}
		else if (dir == LEFT){
			DrawTurnGraph(x -WID_MAHOJIN+36+23- cx, y, Images::getIns()->g_mahojin[maho_count%ANI_MAHOJIN], true);
		}
		break;
	case UnitState::WAIT:
//		DrawGraph(x - cx, y, Images::getIns()->g_majo_w[ani_count / ANIM_SPEED%ANI_MAJO_W], true);
		character::draw(cx, x, y, Images::getIns()->g_majo_w[ani_count / ANIM_SPEED%ANI_MAJO_W]);
		break;
	case UnitState::DIE:
//		DrawGraph(x - cx, y, Images::getIns()->g_majo_w[0], true);
		character::draw(cx, x, y, Images::getIns()->g_majo_w[ani_count / ANIM_SPEED%ANI_MAJO_W]);
		break;
	}

	character::draw(cx);

}

void majo::decideDirection(int front){
	return;
}