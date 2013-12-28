#include "castle.h"
#include "Images.h"
#include "AttackRange.h"
#include "Game.h"
#define YAMA_CANNON_FREQ 100

#define POWER_YAMASHIRO 500
#define P_ATTACK 3
#define ATK_RANGE 200
shiro_yama::shiro_yama(int fx, int fy, int st) :castle(fx, fy, st){
	wait_time = YAMA_CANNON_FREQ;
	break_flag = false;
}

void shiro_yama::main(int front){
	unit::main();
	castle::main(front);
	switch (state){
	case CastleState::ACTIVE:
		if (hp < castle_hp[stage] / 2)
			break_flag = true;

		if ( (wait_time <= 0) && !break_flag){
			if (rand() % P_ATTACK==0){
				int rand_x = (rand() / (RAND_MAX + 1.0))*ATK_RANGE;
				shared_ptr<AttackRange> p(new AttackRange(x-rand_x-WID_SHOCK,x-rand_x, POWER_YAMASHIRO, ALL));
				Game::getIns()->push_attack_list(p, ENEMY);
				Game::getIns()->effect_create(x - rand_x - WID_SHOCK, FIELD_H - HEI_SHOCK, SHOCK);
				Game::getIns()->effect_create(x + 168 - WID_CANNONSHOT / 2 - draw_gap[stage][0],y + 210 - HEI_CANNONSHOT / 2, CANNONSHOT);
				Images::playSE("sound/taihou03.mp3");

			}
			wait_time = YAMA_CANNON_FREQ;
		}
		else{
			wait_time--;
		}


		break;
	case CastleState::STAY:

		break;
	case CastleState::EN_DIE:

		break;
	case CastleState::OCCUPY:

		break;
	case CastleState::MEKA_DIE:

		break;
	}

}
void shiro_yama::draw(int cx){
	castle::draw(cx);

	switch (state){
	case CastleState::ACTIVE:
		if (!break_flag)
			DrawGraph(x - draw_gap[stage][0] - cx, y, Images::getIns()->houdai_yama, true);
		break;
	}


}