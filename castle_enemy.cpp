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

	ii one[] = { ii(30000, 13) };
	ii two[] = { ii(80, 10), ii(130, 12) };
	ii three[] = { ii(130, 11), ii(49, 10) };
	ii four[] = { ii(85, 12), ii(150, 11) };
	ii five[] = { ii(60, 10), ii(70, 11), ii(33, 10) };
	ii six[] = { ii(33, 10), ii(80, 12), ii(110, 11), ii(50, 10), ii(80, 12) };
	ii seven[] = { ii(50, 10), ii(70, 10), ii(100, 11)
		, ii(50, 10), ii(70, 10), ii(100, 11)
		, ii(50, 10), ii(70, 10), ii(100, 11)
		, ii(50, 10), ii(70, 10), ii(100, 11), ii(20, 12) };

	ii eight[] = { ii(49, 12), ii(70, 10), ii(90, 11) };
	ii nine[] = { ii(30, 10), ii(100, 12), ii(100, 11) };

	ii oneEvent[] = { ii(0, 13) };
	ii twoEvent[] = { ii(0, 10) };
	ii threeEvent[] = { ii(30, 11) };
	ii fourEvent[] = { ii(0, 13), ii(30, 10), ii(20, 11), };
	ii fiveEvent[] = { ii(1000, 13) };
	ii sixEvent[] = { ii(30, 10), ii(20, 11), ii(50, 12) };
	ii sevenEvent[] = { ii(0, 13), ii(30, 10), ii(20, 11), ii(50, 12), ii(2000, 13) };
	ii eightEvent[] = { ii(30, 10), ii(20, 11), ii(500, 13), ii(2500, 13), ii(3500, 13), ii(4000, 13) };
	ii nineEvent[] = { ii(30, 11) };




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
			Images::getIns()->playSE("sound/sen_ka_heirappa01.mp3");

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