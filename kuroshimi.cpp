#include "kuroshimi.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 2
#define DIST_KUROSHIMI 200
kuroshimi::kuroshimi(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_KUROSHIMI){
	width = WID_KUROSHIMI;
	height = HEI_KUROSHIMI;
	y = WINDOW_Y - height;
	atk_type = RAND;
	dist = rand()%514;
	type = RAND;
	back = 0;
	p_back = 0;
}

void kuroshimi::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		if (x + width < 0) state = UnitState::DIE;
		if (x + width > STAGE8_W-500) state = UnitState::DIE;

		break;
	case UnitState::ATK:
		atk = false;
		state_change_flag = false;
		if (ani_count / ANIM_SPEED%ANI_KUROSHIMI_A == 2){
			if (!stopper){
				if (!atk){
					stopper = true;
					dist = max(rand() % 400, 0);
				}
			}
		}
		else{ stopper = false; }

		if (((ani_count / ANIM_SPEED) % ANI_KUROSHIMI_A == ANI_KUROSHIMI_A-1)){
			state_change_flag = true;
			changeState(UnitState::WAIT);
			if (rand() % 2){
				back = rand()%2000 + 1000;
				p_back = x;
			}
		}
		break;
	case UnitState::WAIT:
		atk = false;
			state_change_flag = false;
			x += speed - 2;
			if(x - p_back > back){
				state_change_flag = true;
				changeState(UnitState::MOV);

			}
			
		break;
	case UnitState::DIE:
			del();
		
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
