#include "castle.h"
#include "Images.h"
#include "Game.h"
const int castle_hp[9] = { 5000, 5000, 5000, 50000, 5000, 5000, 50000, 50000,50000};
const int unit_clk[6] = { 0,CLK_HOHEI, CLK_BALLOON, CLK_BIG ,CLK_KAMIKAZE,CLK_BAZOOKA};
int castle::nowstage=1;


castle::castle(int fx, int fy, int st) :unit(fx, fy, 0){
	hp = castle_hp[st];
	width = 273;
	x = fx - width / 2;
	height = 450;
	defense = 1;
	stage = st;
	tm = 0;
	if (st == 0)state = OCCUPY;
	else if (st == 1)state = ACTIVE;
	else state = WAIT;
	dir = NODIR;
	product_type = NONE;
	product_clk = NONE;

}

void castle::main(){
	switch (state){
	case ACTIVE:
		if (getClock(1000)){
			Game::getIns()->birth(stage, TANK);
			//Game::getIns()->birth(stage, COPTER);
		}
		break;
	case WAIT:

		break;
	case DIE:
		state = OCCUPY;
		nowstage++;
		Game::getIns()->stageInc(nowstage);
		break;
	case OCCUPY:
		if (getClock(product_clk))
			Game::getIns()->birth(stage, product_type);
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

int castle::getNowstage(){
	return nowstage;
}

void castle::setProduct(int p_type){
	
	product_type = p_type;
	//product_clk = unit_clk[p_type];
	product_clk =Game::getIns()->getParam(p_type,ParamType::CLK);
}
int castle::getProduct(){
	return product_type;
	
}

void castle::setState(int s){
	state = s;
}