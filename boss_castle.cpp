#include "boss_castle.h"
#include "Game.h"
#include "bigExplode.h"

boss_castle::boss_castle(int fx, int fy, int st, vector<vector<string>> list, UnitType ut) :castle_enemy(fx, fy, st,list){
	unit_type = ut;
	if (st == 1){
		boss_unit = Game::getIns()->x_birth(x, unit_type, false);
	}
}

void boss_castle::main(int front){
	switch (state){
	case CastleState::ACTIVE:
		if (boss_unit != nullptr){
			x = boss_unit->getX() + 1;
			hp = boss_unit->getHP();
			if (boss_unit->getState() == UnitState::DIE){
				Game::getIns()->effect_create(x, 0, BIGEXP);
				loop_count = 0;
				state = CastleState::DIE;
			}
		}
		
		
		break;
	case CastleState::DIE:
/*		loop_count++;
		if (loop_count / ANIM_SPEED_BIGEXP >= 8){
			loop_count = 0;
			Game::getIns()->stageClear();
			SoundController::getSE()->playSE("sound/sen_ka_heirappa01.mp3");

		}*/
		break;
	}
	
	castle_enemy::main(front);

}

void boss_castle::draw(int cx){


}

void boss_castle::damage(int, UnitType op_unit_type){

}


void boss_castle::setState(CastleState st){
	if (st == CastleState::ACTIVE){
		boss_unit = Game::getIns()->x_birth(x, unit_type, false);

	}
	state = st;
}