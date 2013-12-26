#include "castle.h"
#include "Images.h"
#include "Game.h"
const int castle_hp[9] = { 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000,5000};
const int meka_castle_hp[9] = { 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000 };
//const int unit_clk[6] = { 0,CLK_HOHEI, CLK_BALLOON, CLK_BIG ,CLK_KAMIKAZE,CLK_BAZOOKA};
const int draw_gap[9][3] = {
	{0,0,20},
	{62,-16,-16}, 
	{25,30,-70}, 
	{5,5,0}, 
	{170,160,0},  
	{0,0,0}, // 2‚Ì‚Ý–¢Œˆ’è
	{0,0,0}, // 
	{0,0,0}, // 2‚Ì‚Ý–¢Œˆ’è
	{0,0,0}, //–¢Œˆ’è
};



//int castle::nowstage=1;

template<typename TYPE,std::size_t SIZE>
std::size_t array_length(const TYPE (&)[SIZE])
{
    return SIZE;
}

#define HELPassign(x) spownlist.assign(x,x+array_length(x))

#define Eventassign(x) eventlist.assign(x,x+array_length(x))

castle::castle(int fx, int fy, int st) :unit(fx, fy, 0){
	hp = castle_hp[st];
	width = WID_CASTLE;
	if (st == 0) x = 0;
	else x = fx - width / 2;

	height = HEI_CASTLE;
	defense = 1;
	stage = st;
	tm = 0;
	if (st == 0)state = CastleState::OCCUPY;
	else if (st == 1)state = CastleState::ACTIVE;
	else state = CastleState::STAY;
	dir = NODIR;
	product_type = NONE;
	now_clk=0;
	exist_clk=0;

	ii one[] = { ii(100, 13), ii(100, 12) };
	ii two[]={ii(30,10)};
	ii three[]={ii(30,10)};
	ii four[]={ii(30,10)};
	ii five[]={ii(30,10)};
	ii six[]={ii(30,10)};
	ii seven[]={ii(30,10)};
	ii eight[]={ii(30,10)};
	ii nine[]={ii(30,10)};

	ii oneEvent[]={ii(100,11)};
	ii twoEvent[]={ii(30,11)};
	ii threeEvent[]={ii(30,11)};
	ii fourEvent[]={ii(30,11)};
	ii fiveEvent[]={ii(30,11)};
	ii sixEvent[]={ii(30,11)};
	ii sevenEvent[]={ii(30,11)};
	ii eightEvent[]={ii(30,11)};
	ii nineEvent[]={ii(30,11)};



	
	switch(st){
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

	spownID=0;
	exist_ID=0;

}

void castle::main(){
	switch (state){
/*
	case CastleState::ACTIVE:
		if (getClock(1000)){
*/
	case ACTIVE:
		//if (getClock(1000)){
		/*if(now_clk++>30){
			now_clk=0;
			Game::getIns()->birth(stage, TANK);
			Game::getIns()->birth(stage, COPTER);
		}*/
		now_clk++;
		
		
		if(now_clk>=spownlist.at(spownID).first){
			Game::getIns()->birth(stage,spownlist.at(spownID).second );
			spownID++;
			if(spownID>=spownlist.size()){
				spownID=0;
				now_clk=0;
			}
		}
		if(exist_ID<eventlist.size()){
			exist_clk++;
			if(exist_clk>=eventlist.at( exist_ID).first){
				Game::getIns()->birth(stage,eventlist.at(exist_ID).second );
				exist_ID++;
			}
		}
		break;
	case CastleState::STAY:

		break;
	case CastleState::EN_DIE:
		state = OCCUPY;
	//	nowstage++;
		now_clk=0;
		Game::getIns()->stageInc();
		hp = meka_castle_hp[stage];
		break;
/*
	case CastleState::OCCUPY:
		if (getClock(product_clk))
*/
	case OCCUPY:
		//if (getClock(product_clk))
		if(isProductTime())
			Game::getIns()->birth(stage, product_type);
		break;
	}
}


void castle::draw(int cx){
	int koma = (castle_hp[stage] - hp > castle_hp[stage] / 2) ? 1 : 0;
	switch (state){
	case CastleState::ACTIVE:
		DrawGraph(x - draw_gap[stage][koma] - cx, y, Images::getIns()->g_castle[stage][koma], true);
		DrawFormatString(FIELD_W - 50, 200, GetColor(0, 0, 0), "%d", hp);
		break;
	case CastleState::STAY:
		DrawGraph(x - cx, y, Images::getIns()->g_castle[stage][0], true);
		break;
	case CastleState::EN_DIE:
		break;
	case CastleState::OCCUPY:
		DrawGraph(x - draw_gap[stage][2] - cx, y, Images::getIns()->g_castle[stage][2], true);
		DrawFormatString(FIELD_W - 50, 200, GetColor(0, 0, 0), "%d", hp);

		break;
	case CastleState::MEKA_DIE:
		break;
	}
	
}

void castle::damage(int d){
	switch (state){
	case CastleState::ACTIVE:
		hp -= max(d - defense, 0);
		if (hp < 0){
			state = CastleState::EN_DIE;
		}
		break;
	case CastleState::STAY:

		break;
	case DIE:

		break;
	case CastleState::OCCUPY:
		hp -= max(d - defense, 0);
		if (hp < 0){
			state = CastleState::MEKA_DIE;
		}
		break;
	case CastleState::MEKA_DIE:
		break;
	}
}

bool castle::isProductTime(){
	int p=Game::getIns()->getParam(product_type,ParamType::CLK);
	if(now_clk++>=p){now_clk=0;return true;}
	return false;
}

bool castle::getClock(unsigned int clk){
	
	unsigned int nowt;
	if ((nowt = (unsigned int)(GetNowCount())) - tm > clk){ tm = nowt; return true; }
	else if (nowt < 0)tm = 0;
	return false;
}
/*
int castle::getNowstage(){
	return nowstage;
}

void castle::setNowstage(int st){
	nowstage=st;
}
*/
void castle::setProduct(int p_type){
	
	product_type = p_type;
}
int castle::getProduct(){
	return product_type;
	
}
double castle::getProductCLKPAR(){
	int product_clk=Game::getIns()->getParam(product_type,ParamType::CLK);
	if(product_clk==0)return 0;
	return now_clk/(double)product_clk;
	
}

void castle::setState(int s){
	state = s;
}