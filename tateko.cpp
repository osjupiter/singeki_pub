#include "tateko.h"
#include "Images.h"

#define ANIM_SPEED_W 5
#define ANIM_SPEED_A 3


tateko::tateko(int fx, int ln) : musume(fx, ln, UnitType::_TATEKO){
	dist = rand() % 40 - width;
	width = WID_TATEKO;
	height = HEI_TATEKO;
	type = RAND;
	atk = false;	
	y = WINDOW_Y - HEI_TATEKO + line * 3;
	stopper = false;
}
void tateko::main(int front){
	musume::main(front);

	switch (state){
	case UnitState::MOV:
		x += param->getParam(SPEED); //‰¡ˆÚ“®
		break;
	case UnitState::ATK:
	
		break;
	case UnitState::DIE:

		break;
	}
}

void tateko::draw(int cx){

	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_tateko_w[ani_count / ANIM_SPEED_W%ANI_TATEKO_W], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_tateko_a[ani_count / ANIM_SPEED_A%ANI_TATEKO_A], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_tateko_a[0], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_tateko_w[0], true);
		break;
	}

	character::draw(cx);

}
