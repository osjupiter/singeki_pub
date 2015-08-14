#include "himekishi.h"
#include "Images.h"
#include "SoundController.h"
#include "Game.h"
#define ANIM_SPEED_W 5
#define ANIM_SPEED_A 2
#define ANIM_SPEED_AE 4
#define ANIM_SPEED_H 1
#define ANIM_SPEED_C 2
#define ANIM_SPEED_O 2
#define ANIM_SPEED_HC 2
#define H_FLAME (10)

#define DIST_HIME 75

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
		wait_time = param->getParam(A_FREQ);
		break;
	case UnitState::ATK:
		state_change_flag = false;
		if (ani_count == 1){
			SoundController::getSE()->playSE("sound/sen_ge_bom18_•P‹Rm‘åO•ó‹ï‚r‚d.mp3", true);
		}
		if (ani_count / ANIM_SPEED_HC % 2 == 0){
			if (!stopper){
				if (!atk){
					stopper = true;
					shared_ptr<AttackRange> p(new AttackRange(x + 80, x + 605, param->getParam(POWER) / 5, RAND));
					Game::getIns()->push_attack_list(p, MUSUME);
//					atk = true;
//					SoundController::getSE()->playSE("sound/ƒŒƒCƒsƒA.mp3");

				}
			}else {

				atk = false;
			}
		}
		else{ stopper = false; }
		if ((ani_count / ANIM_SPEED_HC  == H_FLAME)){
			state_change_flag = true;
			SoundController::getSE()->stopSE("sound/sen_ge_bom18_•P‹Rm‘åO•ó‹ï‚r‚d.mp3");
			changeState(UnitState::ST1);
			ani_count = 0;
			state_change_flag = false;

			atk = false;
		}


		break;
	case UnitState::WAIT:
		state_change_flag = false;
		if (ani_count == 1){
			SoundController::getSE()->playSE("sound/aura1_•P‹Rmƒ`ƒƒ[ƒW‚r‚d.mp3", true);
		}
		if (wait_time <= 0){
			state_change_flag = true;
			changeState(UnitState::ST0);
			ani_count = 0;
			state_change_flag = false;
		}
		break;
	case UnitState::ST0:
		state_change_flag = false;
		if (ani_count / ANIM_SPEED_A == ANI_HIME_A ){
			state_change_flag = true;
			changeState(UnitState::ATK);
			ani_count = 0;
			state_change_flag = false;
		}
		break;
	case UnitState::ST1:
		state_change_flag = false;
		if (ani_count / ANIM_SPEED_AE == ANI_HIME_AE){
			state_change_flag = true;
			wait_time = param->getParam(A_FREQ);
			changeState(UnitState::MOV);
		}
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
		DrawGraph(x - cx, y, Images::getIns()->g_hime_hc[ani_count / ANIM_SPEED_HC%ANI_HIME_HC], true);
		if ((ani_count / ANIM_SPEED_H)<2){
			DrawGraph(x - cx, y + HEI_HIME - HEI_HIME_H, Images::getIns()->g_hime_h[((ANI_HIME_H-1)-(ani_count / ANIM_SPEED_H))], true);
		}
		else{
			DrawGraph(x - cx, y + HEI_HIME - HEI_HIME_H, Images::getIns()->g_hime_h[((ani_count / ANIM_SPEED_H) % (ANI_HIME_H - 2))], true);
		}
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_hime_w[0], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_hime_c[ani_count / ANIM_SPEED_C%ANI_HIME_C], true);
		DrawGraph(x + 8- cx, y+HEI_HIME_C-HEI_HIME_O, Images::getIns()->g_hime_o[ani_count / ANIM_SPEED_O%ANI_HIME_O], true);
		break;
	case UnitState::ST0:
		DrawGraph(x - cx, y, Images::getIns()->g_hime_a[ani_count / ANIM_SPEED_C%ANI_HIME_A], true);
		DrawGraph(x + 8 - cx, y + HEI_HIME - HEI_HIME_O, Images::getIns()->g_hime_o[ani_count / ANIM_SPEED_O%ANI_HIME_O], true);
	case UnitState::ST1:
		DrawGraph(x - cx, y, Images::getIns()->g_hime_ae[ani_count / ANIM_SPEED_AE%ANI_HIME_AE], true);
		break;
	}

	character::draw(cx);

}
