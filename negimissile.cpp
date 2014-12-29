#include "negimissile.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3
negimissile::negimissile(int fx, int fy, Direction d, int p, int destx_, int desty_, int lv) :effect(fx, fy){
	type = NEGIMISSILE;
	width = WID_NEGIMISSILE;
	height = HEI_NEGIMISSILE;
	dir = d;
	power = p;
	destx = destx_;

	g_type = lv;
	switch (g_type){
	case 0:
		tarpos = SKY;
		break;
	case 1:
		tarpos = SKY;
		break;
	case 2:
		tarpos = RAND;
		break;
	}
}
void negimissile::main(){
	effect::main();
	if (g_type == 0){
		x +=  8 * dir;
		y -= 9;
	}
	if (g_type == 1){
		x += 10 * dir;
		y -= 5;
	}
	if (g_type == 2){
		x += 15 * dir;
	}
	else if (g_type == 1){
	
	}
	else{
	
	}
	if ((g_type == 0  && y<-50)
		|| (g_type == 1 && y<0/*-129*/)
		|| (g_type == 2 && dir*(x -destx) > 500)) {
		del();
		int center = (x + x + width) / 2;
		Game::getIns()->effect_create(x + width / 2 - WID_NOMALEXP / 2, (y + y + height) / 2 - HEI_NOMALEXP / 2, NOMALEXP);

		shared_ptr<AttackRange> p(new AttackRange(center - WID_NOMALEXP / 2, center + WID_NOMALEXP / 2, power, tarpos));
		Game::getIns()->push_attack_list(p, ENEMY);
	}
}

void negimissile::draw(int cx){
	if (dir == LEFT){
		DrawGraph(x - cx, y, Images::getIns()->g_negimissile[g_type][ani_count / ANIM_SPEED % ANI_NEGIMISSILE], true);
	}
	else
		DrawTurnGraph(x - cx, y, Images::getIns()->g_negimissile[g_type][ani_count / ANIM_SPEED % ANI_NEGIMISSILE], true);

	effect::draw(cx);
}