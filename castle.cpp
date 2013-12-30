#include "castle.h"
#include "Images.h"
#include "Game.h"
#include "bigExplode.h"
const int castle::castle_hp[9] = { 10000, 10000, 30000, 40000, 60000, 80000, 100000, 300000,500000};
const int meka_castle_hp[9] = { 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000 };

//const int unit_clk[6] = { 0,CLK_HOHEI, CLK_BALLOON, CLK_BIG ,CLK_KAMIKAZE,CLK_BAZOOKA};
const int castle::draw_gap[9][3] = {
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
	width = (st==0) ? 300:WID_CASTLE;
	height = (st == 0) ? 180 : HEI_CASTLE;
	//width = 300;
	if (st == 0) x = 0;
	else x = fx - width / 2;
	loop_count = 0;
	maxhp = hp;

	defense = 0;
	stage = st;
	tm = 0;
	if (st == 0)state = CastleState::OCCUPY;
	else if (st == 1)state = CastleState::ACTIVE;
	else state = CastleState::STAY;
	dir = NODIR;
	product_type = NONE;
	now_clk=0;
	exist_clk=0;

	
	ii one[] = { ii(100, 10) };
	ii two[] = { ii(80, 10), ii(130, 12) };
	ii three[] = { ii(130, 11),ii(49,10) };
	ii four[] = { ii(85, 12), ii(150, 11) };
	ii five[] = { ii(60, 10), ii(70, 11), ii(30, 10) };
	ii six[] = { ii(33, 10), ii(80, 12), ii(110, 11), ii(50, 10), ii(80, 12) };
	ii seven[] = { ii(50, 10), ii(70, 10), ii(100, 11)
		,ii(50, 10), ii(70, 10), ii(100, 11) 
		, ii(50, 10), ii(70, 10), ii(100, 11) 
		, ii(50, 10), ii(70, 10), ii(100, 11), ii(20, 12) };

	ii eight[] = { ii(49, 12), ii(70, 10), ii(90, 11) };
	ii nine[] = { ii(30, 10), ii(100, 12) ,ii(100, 11)  };

	ii oneEvent[]={ii(0,10)};
	ii twoEvent[]={ii(0,10)};
	ii threeEvent[]={ii(30,11)};
	ii fourEvent[] = { ii(0, 13), ii(30, 10), ii(20, 11), };
	ii fiveEvent[]={ii(1000,13)};
	ii sixEvent[] = { ii(30, 10), ii(20, 11), ii(50, 12) };
	ii sevenEvent[] = { ii(0, 13), ii(30, 10), ii(20, 11), ii(50, 12),ii(2000, 13) };
	ii eightEvent[] = { ii(30, 10), ii(20, 11), ii(500, 13), ii(2500, 13), ii(3500, 13), ii(4000, 13) };
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

void castle::main(int front){
	switch (state){

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
		loop_count ++ ;
		if (loop_count / ANIM_SPEED_BIGEXP >= 8){
			state = OCCUPY;
			now_clk = 0;
			loop_count = 0;
			Game::getIns()->stageInc();
			hp = meka_castle_hp[stage];
			Images::getIns()->playSE("sound/sen_ka_heirappa01.mp3");

		}
		break;
	case CastleState::MEKA_DIE:

		break;
	case OCCUPY:
		//if (getClock(product_clk))
		if(isProductTime())
			Game::getIns()->birth(stage, product_type);
		if (hp < 0){
			loop_count++;
			if (loop_count / ANIM_SPEED_BIGEXP >= 8){
				state = CastleState::MEKA_DIE;
			}
		}
		break;

	}
}


void castle::draw(int cx){
	int koma = (hp < castle_hp[stage] / 2) ? 1 : 0;
	switch (state){
	case CastleState::ACTIVE:
		DrawGraph(x - draw_gap[stage][koma] - cx, y, Images::getIns()->g_castle[stage][koma], true);
//		DrawFormatString(FIELD_W - 50, 200, GetColor(255, 255, 255), "%d", hp);
		break;
	case CastleState::STAY:
		DrawGraph(x - cx, y, Images::getIns()->g_castle[stage][0], true);
		break;
	case CastleState::EN_DIE:

		break;
	case CastleState::OCCUPY:
		DrawGraph(x - draw_gap[stage][2] - cx, y, Images::getIns()->g_castle[stage][2], true);
		//DrawFormatString(FIELD_W - 50, 200, GetColor(255, 255, 255), "%d", hp);

		break;
	case CastleState::MEKA_DIE:
		if (stage!=0)
			DrawGraph(x - draw_gap[stage][2] - cx, y, Images::getIns()->g_mekahaikyo, true);
		break;
	}


	int dx = x + width / 2 - 60 / 2;
	int dy = 240;
	DrawLine(dx - cx, dy + 3, dx + 60 - cx, dy + 3, GetColor(255, 0, 0), 5);
	int i = hp;
	for (int j = dx; i >10000; i -= 10000, j += 7){
		DrawLine(j - cx, dy + 9, j - cx, dy + 15, GetColor(0, 255, 0), 3);

	}

	DrawLine(dx - cx, dy + 3, dx + 60 * max(i,0) / (10000 * 1.0) - cx, dy + 3, GetColor(0, 255, 0), 5);

}

void castle::damage(int d, UnitType op_unit_type){
	int rand_x = rand() % 100, rand_y = rand() % 90;
	switch (state){
	case CastleState::ACTIVE:
		if (rand() % 30 == 0){
			switch (op_unit_type){
				case UnitType::_BAZOOKA:
				Game::getIns()->damage_effect_create(x + 100 +rand_x, y + height - HEI_CANNONSHOT + 35-rand_y, CANNONSHOT, true);
				break;
			case UnitType::_HOHEI:
				Game::getIns()->damage_effect_create(x +100+rand_x, y + height - HEI_GUNSHOT + 25-rand_y, GUNSHOT);
				break;
			}
		}
		
	
		hp -= max(d - defense, 0);
		if (hp < 0){
				Game::getIns()->effect_create(x, 0, BIGEXP);
/*				shared_ptr<AttackRange> p(new AttackRange(0, x+width, INT_MAX, ALL));
				Game::getIns()->push_attack_list(p, MUSUME);
	*/
			loop_count = 0;
			state = CastleState::EN_DIE;
		}
		break;
	case CastleState::STAY:

		break;
	case CastleState::EN_DIE:

		break;
	case CastleState::OCCUPY:
		if (rand() % 10 == 0){
			switch (op_unit_type){
			case UnitType::_TANK:
				Game::getIns()->damage_effect_create(x + width - WID_CANNONSHOT*2-rand_x, y + HEI_CASTLE - HEI_CANNONSHOT -rand_y, CANNONSHOT);
				break;
			case UnitType::_GEKKO:
				Game::getIns()->damage_effect_create(x + width - WID_GUNSHOT * 2 - rand_x, y + HEI_CASTLE - HEI_GUNSHOT - rand_y, GUNSHOT, true);
				break;
		
			}
		}
		if (stage != 8){
			hp -= max(d - defense, 0);
			if (hp < 0){
				Game::getIns()->effect_create(x, 0, BIGEXP);
				loop_count = 0;
				shared_ptr<AttackRange> p(new AttackRange(x, x + width, 100000, ALL));
				Game::getIns()->push_attack_list(p, ENEMY);

				state = CastleState::MEKA_DIE;
			}
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