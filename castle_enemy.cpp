#include "castle.h"
#include "bigExplode.h"
#include "Game.h"


const int castle::castle_hp[9] = { 10000, 10000, 30000, 40000, 60000, 80000, 100000, 300000, 500000 };

template<typename TYPE, std::size_t SIZE>
std::size_t array_length(const TYPE(&)[SIZE])
{
	return SIZE;
}

#define HELPassign(x) spownlist.assign(x,x+array_length(x))

#define Eventassign(x) eventlist.assign(x,x+array_length(x))
castle_enemy::castle_enemy(int fx, int fy, int st) :castle(fx, fy, st){
	hp = castle_hp[st];
	maxhp = hp;

	if (st == 1)state = CastleState::ACTIVE;
	else state = CastleState::STAY;

	ii one[] = { ii(30000, _TANK) };
	ii two[] = { ii(80, _TANK), ii(130, _GEKKO) };
	ii three[] = { ii(130, _COPTER), ii(49, _TANK) };
	ii four[] = { ii(85, _GEKKO), ii(150, _COPTER) };
	ii five[] = { ii(60, _TANK), ii(70, _COPTER), ii(33, _TANK) };
	ii six[] = { ii(33, _TANK), ii(80, _GEKKO), ii(110, _COPTER), ii(50, _TANK), ii(80, _GEKKO) };
	ii seven[] = { ii(50, _TANK), ii(70, 10), ii(100, _COPTER)
		, ii(50, _TANK), ii(70, _TANK), ii(100, _COPTER)
		, ii(50, _TANK), ii(70, _TANK), ii(100, _COPTER)
		, ii(50, _TANK), ii(70, _TANK), ii(100, _COPTER), ii(20, _GEKKO) };

	ii eight[] = { ii(49, _GEKKO), ii(70, 10), ii(90, _COPTER) };
	ii nine[] = { ii(30, _TANK), ii(100, _GEKKO), ii(100, _COPTER) };

	ii oneEvent[] = { ii(0, _RAILGUN) };
	ii twoEvent[] = { ii(0, _TANK) };
	ii threeEvent[] = { ii(30, _COPTER) };
	ii fourEvent[] = { ii(0, _RAILGUN), ii(30, _TANK), ii(20, _COPTER), };
	ii fiveEvent[] = { ii(1000, _RAILGUN) };
	ii sixEvent[] = { ii(30, _TANK), ii(20, _COPTER), ii(50, _GEKKO) };
	ii sevenEvent[] = { ii(0, _RAILGUN), ii(30, 10), ii(20, _COPTER), ii(50, _GEKKO), ii(2000, _RAILGUN) };
	ii eightEvent[] = { ii(30, _TANK), ii(20, _COPTER), ii(500, _RAILGUN), ii(2500, _RAILGUN), ii(3500, _RAILGUN), ii(4000, _RAILGUN) };
	ii nineEvent[] = { ii(30, _COPTER) };




	switch (st){
	case 1:
		HELPassign(one);
		Eventassign(oneEvent);
		break;
	case 2:
		HELPassign(two);
		Eventassign(twoEvent);
		break;
	case 3:
		HELPassign(three);
		Eventassign(threeEvent);
		break;
	case 4:
		HELPassign(four);
		Eventassign(fourEvent);
		break;
	case 5:
		HELPassign(five);
		Eventassign(fiveEvent);
		break;
	case 6:
		HELPassign(six);
		Eventassign(sixEvent);
		break;
	case 7:
		HELPassign(seven);
		Eventassign(sevenEvent);
		break;
	case 8:
		HELPassign(eight);
		Eventassign(eightEvent);
		break;
	case 9:
		HELPassign(nine);
		Eventassign(nineEvent);
		break;

	}

	spownID = 0;
	exist_ID = 0;
}

void castle_enemy::main(int front){
	switch (state){

	case CastleState::ACTIVE:

		now_clk++;


		if (now_clk >= spownlist.at(spownID).first){
			Game::getIns()->birth(stage, spownlist.at(spownID).second);
			spownID++;
			if (spownID >= spownlist.size()){
				spownID = 0;
				now_clk = 0;
			}
		}
		if (exist_ID < eventlist.size()){
			exist_clk++;
			if (exist_clk >= eventlist.at(exist_ID).first){
				Game::getIns()->birth(stage, eventlist.at(exist_ID).second);
				exist_ID++;
			}
		}

		break;
	case CastleState::STAY:

		break;
	case CastleState::DIE:
		loop_count++;
		if (loop_count / ANIM_SPEED_BIGEXP >= 8){
			loop_count = 0;
			Game::getIns()->stageClear();
			SoundController::getSE()->playSE("sound/sen_ka_heirappa01.mp3");

		}
		break;
	}
}


void castle_enemy::draw(int cx){
	int koma = (hp < castle_hp[stage] / 2) ? 1 : 0;
	switch (state){
	case CastleState::ACTIVE:
		
		DrawGraph(x - draw_gap[stage][koma] - cx, y, Images::getIns()->g_castle[stage][koma], true);
		//		DrawFormatString(FIELD_W - 50, 200, GetColor(255, 255, 255), "%d", hp);
		break;
	case CastleState::STAY:
		DrawGraph(x - cx, y, Images::getIns()->g_castle[stage][0], true);
		break;
	case CastleState::DIE:

		break;
	}

	castle::draw(cx);
}