#include "bomb.h"
#include "Images.h"
#include "Game.h"
bomb::bomb(int fx, int fy) :effect(fx, fy){
	type = BOMB;
	width = WID_BOMB;
	height = HEI_BOMB;
}
void bomb::main(){
	effect::main();
	y += 5;
	if (y>FIELD_H) 
		Game::getIns()->push_del_effect(*(new shared_ptr<effect>(this)));
}

void bomb::draw(int cx){
	DrawGraph(x - cx,y,Images::getIns()->g_bomb[ani_count/4%2],true);
	
}