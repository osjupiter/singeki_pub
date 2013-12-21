#include "castle.h"
#include "Images.h"
#include "Game.h"
const int castle_hp[8] = { 5000, 50000, 50000, 50000, 50000, 50000, 50000, 50000 };
int castle::cleared=1;
#define ACTIVE 4
#define WAIT 5
#define OCCUPY 6
castle::castle(int fx,int fy,int st):unit(fx,fy,0){
	hp = castle_hp[st];
	width = 273;
	x = fx-width/2;
	height = 450;
	defense = 1;
	stage = st;
	tm = 0;
	if (st == 0)state = OCCUPY;
	else if (st == 1)state=ACTIVE;
	else state = WAIT;
}

void castle::main(){
	switch (state){
	case ACTIVE:
		if (getClock(3000))
			Game::getIns()->birth(stage, TANK);
		break;
	case WAIT:

		break;
	case DIE:
		state = OCCUPY;
		cleared++;
		break;
	case OCCUPY:

		break;
	}
}

void castle::draw(int cx){
	switch (state){
	case ACTIVE:
		DrawGraph(x - cx, y, Images::getIns()->castle[0], true);
		DrawFormatString(FIELD_W - 50, 200, GetColor(0, 0, 0), "%d", hp);
		break;
	case WAIT:
		DrawGraph(x - cx, y, Images::getIns()->castle[0], true);
		break;
	case DIE:

		break;
	case OCCUPY:

		break;
	}
	
}

void castle::damage(int d){
	switch (state){
	case ACTIVE:
		hp -= max(d - defense, 0);
		if (hp < 0){
			state = DIE;
		}
		break;
	case WAIT:

		break;
	case DIE:

		break;
	case OCCUPY:

		break;
	}
}

bool castle::getClock(unsigned int clk){
	
	unsigned int nowt;
	if ((nowt = (unsigned int)(GetNowCount())) - tm > clk){ tm = nowt; return true; }
	else if (nowt < 0)tm = 0;
	return false;
}

int castle::getCleared(){
	return cleared;
}

void castle::setState(int s){
	state = s;
}