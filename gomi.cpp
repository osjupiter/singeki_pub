#include "gomi.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3


gomi::gomi(int fx, int fy, int p) :effect(fx, fy){
	type = GOMI;
	width = WID_GOMI;
	height = HEI_GOMI;
	power = p;
	for (int i = 0; i < 25; i++){
		d[i] = rand() % 2;
	}
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			int tmp = rand() % 3;
			count[i * 5 + j] = ani_count - 1 * ANIM_SPEED*i - tmp;
		}
	}
}

void gomi::main(){
	effect::main();
	
	y += 5;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			count[i * 5 + j]++;
		}
	}

	for (int i = 0; i < 5; i++){
		if (count[i * 5] / ANIM_SPEED%ANI_GOMI == 4){
			shared_ptr<AttackRange> p(new AttackRange(x + 140, x + 5 * 80 + 40 + 140, power / 5, ALL));
			Game::getIns()->push_attack_list(p, ENEMY);
		}
		if (count[24] / ANIM_SPEED == ANI_GOMI){
			del();
		}
	}


}

void gomi::draw(int cx){
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			int id = i * 5 + j;
			if (count[id] < 0 || count[id] / ANIM_SPEED >= ANI_GOMI) continue;
			if (i % 2 == 1)
				DrawGraph(x + j * 80 - cx, y+i*80, Images::getIns()->g_gomi[0][count[id] / ANIM_SPEED % ANI_GOMI], true);
			else
				DrawGraph(x + j * 80 + 40 - cx, y+i*80, Images::getIns()->g_gomi[1][count[id] / ANIM_SPEED % ANI_GOMI], true);
		}
	}
}
