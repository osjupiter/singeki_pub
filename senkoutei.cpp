#include "senkoutei.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
#define DIST_SENKOU 50
senkoutei::senkoutei(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_SENKOUTEI){
	width = WID_SENKOU;
	height = HEI_SENKOU;
	y = WINDOW_Y - height;
	atk_type = ALL;
	dist = -rand()%40 + DIST_SENKOU;
	type = RAND;
}



void senkoutei::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //とりあえず横移動
		if (x + width < 0) state = UnitState::DIE;
		break;
	case UnitState::ATK:
		atk = false;
		if (ani_count / ANIM_SPEED%ANI_SENKOU_A == 2){
			if (!stopper){
					
					Game::getIns()->effect_create(x + width / 2 - WID_GYORAI / 2 + 10 * dir, y +220-95, GYORAI, dir, power, front-WID_GYORAI/2, atk_position,level);
					SoundController::getSE()->playSE("sound/ビーバーブシュー(修正).mp3");
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

void senkoutei::decideDirection(int front){
	return;
	if (((x + width <= front - dist) && dir == LEFT)
		|| ((x + width > front) && dir == RIGHT))
		switchDirection();
}

Position senkoutei::decideTargetPos(int target_x_rand, int target_x_sky){
	Position ret;
	switch (atk_type){
	case ALL:
		if (dir == RIGHT){
			if (target_x_rand <= target_x_sky) ret = RAND;
			else ret = SKY;
		}
		else {
			if (target_x_rand >= target_x_sky) ret = RAND;
			else ret = SKY;
			if (target_x_sky > x) ret = RAND;
		}
		break;
	case RAND:
		ret = RAND;
		break;
	case SKY:
		ret = SKY;
		break;
	case NOATK:
		ret = RAND;
		break;
	}
	atk_position = ret;
	return ret;
}