#include "castle.h"
#include "boss_castle.h"
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



castle_enemy::castle_enemy(int fx, int fy, int st,int wl, vector<vector<string>> list) :castle(fx, fy, st,wl){
	hp = castle_hp[st];
	maxhp = hp;

	if (st == 1) setState(CastleState::ACTIVE);
	else setState(CastleState::STAY);
	ii tmp;

	for (auto data : list){
		int i_data[4] = { stoi(data[0]), stoi(data[1]), stoi(data[2]), stoi(data[3])};
		if (i_data[0] == st){
			tmp = ii(i_data[2], i_data[3]);
			if (i_data[1] == 1){

				eventlist.push_back(tmp);
			}
			else{
				spownlist[i_data[1]].push_back(tmp);
			}
		}
	}
	
	/*
	ii one[] = { ii(400, _GOREMU) };
	ii two[] = { ii(80, _TANK), ii(130, _GEKKO) };
	ii three[] = { ii(130, _COPTER), ii(49, _TANK) };
	ii four[] = { ii(85, _GEKKO), ii(150, _COPTER) };
	ii five[] = { ii(60, _TANK), ii(70, _COPTER), ii(33, _TANK) };
	ii six[] = { ii(33, _TANK), ii(80, _GEKKO), ii(110, _COPTER), ii(50, _TANK), ii(80, _GEKKO) };
	ii seven[] = { ii(50, _TANK), ii(70, _COPTER), ii(100, _COPTER)
		, ii(50, _TANK), ii(70, _TANK), ii(100, _COPTER)
		, ii(50, _TANK), ii(70, _TANK), ii(100, _COPTER)
		, ii(50, _TANK), ii(70, _TANK), ii(100, _COPTER), ii(20, _GEKKO) };

	ii eight[] = { ii(49, _GEKKO), ii(70, _TANK), ii(90, _COPTER) };
	ii nine[] = { ii(30, _TANK), ii(100, _GEKKO), ii(100, _COPTER) };

	ii oneEvent[] = { ii(0,_GOREMU) };
	ii twoEvent[] = { ii(0, _TANK) };
	ii threeEvent[] = { ii(30, _COPTER) };
	ii fourEvent[] = { ii(0, _RAILGUN), ii(30, _TANK), ii(20, _COPTER), };
	ii fiveEvent[] = { ii(1000, _RAILGUN) };
	ii sixEvent[] = { ii(30, _TANK), ii(20, _COPTER), ii(50, _GEKKO) };
	ii sevenEvent[] = { ii(0, _RAILGUN), ii(30, 10), ii(20, _COPTER), ii(50, _GEKKO), ii(2000, _RAILGUN) };
	ii eightEvent[] = { ii(30, _TANK), ii(20, _COPTER), ii(500, _RAILGUN), ii(2500, _RAILGUN), ii(3500, _RAILGUN), ii(4000, _RAILGUN) };
	ii nineEvent[] = { ii(30, _COPTER) };
	

		HELPassign(one);
		Eventassign(oneEvent);

		*/
	for (int i = 0; i < 5; i++){
		spownIndex[i] = 0;
		spown_clk[i] = 0;
	}
	exist_ID = 0;
}

void castle_enemy::main(int front){
	switch (state){

	case CastleState::ACTIVE:


		for (int i = 0; i < 5; i++){

			spown_clk[i]++;
			if (spownlist[i].empty())continue;
			if (spown_clk[i] >= spownlist[i].at(spownIndex[i]).first){
				Game::getIns()->birth(stage, spownlist[i].at(spownIndex[i]).second);
				spownIndex[i]++;
				if (spownIndex[i] >= spownlist[i].size()){
					spownIndex[i] = 0;
					spown_clk[i] = 0;
				}
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
			SoundController::getSE()->playSE("sound/sen_ka_heirappa01.mp3",true);

		}
		break;
	}
}


void castle_enemy::draw(int cx){
	int koma = (hp < castle_hp[stage] / 2) ? 1 : 0;
	switch (state){
	case CastleState::ACTIVE:
		
		DrawGraph(x - Images::getIns()->draw_gap[stage][koma] - cx, y, Images::getIns()->g_castle[stage][koma], true);
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