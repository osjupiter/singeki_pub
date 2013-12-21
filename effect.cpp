#include "DxLib.h"
#include "Images.h"
#include "effect.h"
#include "Game.h"

#include "GV.h"


effect::effect(int fx,int fy):object(fx,fy){
	
	ani_count=0;
}


void effect::main(){
	ani_count++;
}


void effect::draw(int cx){
	//DrawCircle(x + width / 2 - cx, y + height / 2, width / 4, GetColor(255, 0, 0), true);

}

void effect::del(){
	Game::getIns()->push_del_effect(*(new shared_ptr<effect>(this)));
}

