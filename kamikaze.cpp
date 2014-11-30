#include "kamikaze.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
#define DIST_KAMIKAZE 400
int kamikaze::num = 0;



kamikaze::kamikaze(int fx, int ln) : musume(fx, ln, UnitType::_KAMIKAZE){
	dist = dist + DIST_KAMIKAZE;
	
	y = 50 - line * 3;
	width = WID_KAMIKAZE;
	height = HEI_KAMIKAZE;
	num++;
	atk = false;
	stopper = false;
	type = SKY;
	gap_y = 0;
	gap_vy=1;
	image = &(Images::getIns()->g_kamikaze[0]);
}
void kamikaze::init(){
	num = 0;

}
void kamikaze::main(int front){
	musume::main(front);
	
	switch (state){
	case UnitState::MOV:
		x += param->getParam(SPEED); //‰¡ˆÚ“®
		break;
	case UnitState::ATK:
	/*	if (gap_y == -3)
			gap_vy = gap_vy*-1;
		else if (gap_y == 0)
			gap_vy = gap_vy*-1;
		gap_y += gap_vy;
		*/
	
	
		if ((ani_count / ANIM_SPEED == ANI_KAMIKAZE_ATK)){
			Game::getIns()->effect_create(x, y + 75,TEPODON, dir, param->getParam(POWER), front );			
			changeState(UnitState::DIE);
			image = 0;
		}
		
		break;
	case UnitState::DIE:
		
		break;
	}
}

void kamikaze::draw(int cx){
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y+gap_y, Images::getIns()->g_kamikaze[ani_count / ANIM_SPEED%ANI_KAMIKAZE], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y + gap_y, Images::getIns()->g_kamikaze_atk[ani_count / ANIM_SPEED%ANI_KAMIKAZE_ATK], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y + gap_y, Images::getIns()->g_kamikaze_atk[ani_count / ANIM_SPEED%ANI_KAMIKAZE_ATK], true);
		break;
	case UnitState::DIE:
		//DrawGraph(x - cx, y + gap_y, Images::getIns()->g_kamikaze[ani_count / ANIM_SPEED%ANI_KAMIKAZE_ATK], true);
		if(image!=NULL)DrawGraph(x - cx, y + gap_y, *image, true);
		break;

	}

	character::draw(cx);
}

int kamikaze::getNum(){
	return num;
}

void kamikaze::setNum(int i){
	num = i;
}
