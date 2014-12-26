#include "yukidama.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3


yukidama::yukidama(int fx, int fy, int p):effect(fx, fy){
	type = YUKIDAMA;
	width = WID_YUKIDAMA;
	height = HEI_YUKIDAMA;
	power = p;
	for (int i = 0; i < 25;i++){
		d[i] = rand() % 2;		
	}
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			int tmp = rand()%3;
			count[i*5+j] = ani_count - 1 * ANIM_SPEED*i - tmp;
		}
	}
}

void yukidama::main(){
	effect::main();
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			count[i*5+j]++;
		}
	}
	if (ani_count / ANIM_SPEED%ANI_YUKIDAMA == 0){
		shared_ptr<AttackRange> p(new AttackRange(x, x + 400, power, ALL));
		Game::getIns()->push_attack_list(p, ENEMY);
	}
	if (ani_count / ANIM_SPEED == ANI_YUKIDAMA*5-1){
		del();
	}

}

void yukidama::draw(int cx){
	for (int i = 0; i < 5; i++){		
		for (int j = 0; j < 5; j++){
			int id =i * 5 + j;
			if (count[id] < 0 || count[id] / ANIM_SPEED >= ANI_YUKIDAMA) continue;
			if (i%2 == 1)
				DrawGraph(x + j*80 - cx, y, Images::getIns()->g_yukidama2[count[id] / ANIM_SPEED % ANI_YUKIDAMA], true);
			else
				DrawGraph(x + j * 80+40 - cx, y, Images::getIns()->g_yukidama2[count[id] / ANIM_SPEED % ANI_YUKIDAMA], true);
		}
	}
}
