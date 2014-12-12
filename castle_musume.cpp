#include "castle.h"
#include "difine.h"
#include "Game.h"
#include "bigExplode.h"

const int meka_castle_hp[9] = { 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000 };

castle_musume::castle_musume(int fx, int fy, int st) :castle(fx, fy, st){
	hp = meka_castle_hp[st];
	maxhp = hp;
	state = CastleState::ACTIVE;
}

void castle_musume::main(int front){
	switch (state){
	case CastleState::ACTIVE:
		if (isProductTime())
			Game::getIns()->birth(stage, product_type);
			
		break;
	case CastleState::STAY:
		break;
	case CastleState::DIE:
		
			loop_count++;
			if (loop_count / ANIM_SPEED_BIGEXP >= 8){
				state = CastleState::DIE;
			}
		
		break;

	}
}

void castle_musume::draw(int cx){
	switch (state){
	case CastleState::ACTIVE:
		DrawGraph(x - draw_gap[stage][2] - cx, y, Images::getIns()->g_castle[stage][2], true);
		break;
	case CastleState::STAY:
		break;
	case CastleState::DIE:
		if (stage != 0)
			DrawGraph(x - draw_gap[stage][2] - cx, y, Images::getIns()->g_mekahaikyo, true);
		break;
	}

	castle::draw(cx);
}

bool castle_musume::isProductTime(){
	int p = Game::getIns()->getParam(product_type, ParamType::CLK);
	if (now_clk++ >= p){ now_clk = 0; return true; }
	return false;
}