#include "himekishi.h"
#include "Images.h"
#include "SoundController.h"
#define ANIM_SPEED_W 5
#define ANIM_SPEED_A 2
#define DIST_HIME 1

himekishi::himekishi(int fx, int ln) : musume(fx, ln, UnitType::_HIME){
	dist = rand() % 3*2;
	width = WID_HIME_W;
	height = HEI_HIME;
	type = RAND;
	atk = false;
	y = WINDOW_Y - HEI_HIME + line * 4;
	stopper = false;
}
void himekishi::main(int front){
	musume::main(front);

	switch (state){
	case UnitState::MOV:
		x += param->getParam(SPEED); //‰¡ˆÚ“®
		break;
	case UnitState::ATK:
		if (ani_count / ANIM_SPEED_A % ANI_HIME_A == 3){
			if (!stopper){
				if (!atk){
					stopper = true;
					atk = true;
					SoundController::getSE()->playSE("sound/ƒŒƒCƒsƒA.mp3");


				}
			}else {

				atk = false;
			}
		}
		else{ stopper = false; }
		if ((ani_count / ANIM_SPEED_A == ANI_HIME_A)){
			changeState(UnitState::WAIT);
			atk = false;
		}


		break;
	case UnitState::WAIT:

		break;
	case UnitState::DIE:

		break;
	}
}

void himekishi::draw(int cx){

	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_hime_w[ani_count / ANIM_SPEED_W%ANI_HIME_W], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_hime_a[ani_count / ANIM_SPEED_A%ANI_HIME_A], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_hime_a[0], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_hime_w[ani_count / ANIM_SPEED_W%ANI_HIME_W], true);
		break;
	}

	character::draw(cx);

}
