#include "mekaNemu.h"
#include "Images.h"
#include "AttackRange.h"
#include "Game.h"

#define ANI_MEKANEMU 3
#define WID_MEKANEMU 400

#define ANIM_SPEED 8
#define ANIM_SPEED_THUNDER 5

#define ANI_THUNDER 3
#define WID_TUNDER 324
#define HEI_TUNDER 364
#define POWER_MEKANEMU 5000
#define MEKANEMU_DIST 180
#define MEKANEMU_FREQ 100

#define THUNDER_POINT(x) x- MEKANEMU_DIST
#define RANGE_TUNDER 100
mekaNemu::mekaNemu(int fx,int fy,int st) :castle(fx,fy,st){
	x = fx - WID_MEKANEMU;
	width = WID_MEKANEMU;
	wait_time = MEKANEMU_FREQ;
	atk_flag=false;
}

void mekaNemu::main(int front){
	unit::main();
	castle::main(front);
	switch (state){
	case CastleState::ACTIVE:
		if ((front > THUNDER_POINT(x) - RANGE_TUNDER) && (wait_time<=0)){
				shared_ptr<AttackRange> p(new AttackRange(THUNDER_POINT(x) - RANGE_TUNDER, THUNDER_POINT(x) + RANGE_TUNDER, POWER_MEKANEMU, RAND));
				Game::getIns()->push_attack_list(p, ENEMY);
				Game::getIns()->effect_create(THUNDER_POINT(x) - RANGE_TUNDER, FIELD_H - HEI_SHOCK, SHOCK);
				ani_count = 0;
				atk_flag = true;
				
		}	
		else{ 
		
		}
		if (atk_flag){
			if(ani_count/ANIM_SPEED_THUNDER > ANI_THUNDER*2)
				atk_flag=false;
				wait_time = MEKANEMU_FREQ;
		}
		else{ wait_time--; }

		
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

void mekaNemu::draw(int cx){
	DrawLine(THUNDER_POINT(x) - RANGE_TUNDER-cx,0, THUNDER_POINT(x) - RANGE_TUNDER-cx, WINDOW_Y,GetColor(255, 255, 0),5);
	DrawLine(15200 - cx, 0, 15200 - cx, WINDOW_Y, GetColor(0, 255, 0), 5);

	switch (state){
	case CastleState::ACTIVE:
		DrawGraph(x - cx, y, Images::getIns()->g_castle[stage][ani_count/ANIM_SPEED%ANI_MEKANEMU], true);
		if (atk_flag)
			DrawGraph(x - cx - WID_TUNDER+95, WINDOW_Y-HEI_TUNDER+10, Images::getIns()->g_thunder_mekanemu[ani_count / ANIM_SPEED_THUNDER%ANI_THUNDER], true);
		DrawFormatString(FIELD_W - 50, 200, GetColor(0, 0, 0), "%d", hp);
		break;
	case CastleState::STAY:
	/*	DrawGraph(x - cx, y, Images::getIns()->g_castle[stage][ani_count / ANIM_SPEED%ANI_MEKANEMU], true);
		if (atk_flag)
			DrawGraph(x - cx - WID_TUNDER+110, WINDOW_Y - HEI_TUNDER, Images::getIns()->g_thunder_mekanemu[ani_count / ANIM_SPEED%ANI_THUNDER], true);
*/
		break;
	case CastleState::EN_DIE:
		break;
	case CastleState::OCCUPY:
	
		break;
	case CastleState::MEKA_DIE:
		break;
	}

}