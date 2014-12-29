#include "castle.h"
#include "Images.h"
#include "Game.h"
#include "bigExplode.h"

//const int meka_castle_hp[9] = { 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000 };

//const int unit_clk[6] = { 0,CLK_HOHEI, CLK_BALLOON, CLK_BIG ,CLK_KAMIKAZE,CLK_BAZOOKA};
const int castle::draw_gap[9][3] = { //é‰æ‘œ’†‰›‚Æ”wŒiØ‚ê–Ú‰B‚µ•”•ª‚Ì·
	{0,0,20},
	{62,-16,-16}, 
	{25,30,-70}, 
	{5,5,0}, 
	{170,160,0},  
	{0,0,0}, 
	{0,0,0}, 
	{0,0,0}, 
	{0,0,0}, 
};



//int castle::nowstage=1;




castle::castle(int fx, int fy, int st,int wl) :unit(fx, fy){
	world = wl;
	width = (st==0) ? 300:WID_CASTLE;
	height = (st == 0) ? 180 : HEI_CASTLE;
	//width = 300;
	if (st == 0) x = 0;
	else x = fx - width / 2;
	loop_count = 0;
	
	defense = 0;
	stage = st;
	tm = 0;


	dir = NODIR;
	product_type = _NONE;
	now_clk = 0;
	exist_clk = 0;

	
}

CastleState castle::getState(){
	return state;
}

void castle::main(int front){
/*	switch (state){

	case CastleState::ACTIVE:
	
		now_clk++;
		
		
		if(now_clk>=spownlist
		
		spownID).first){
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
	case CastleState::DIE:
		loop_count ++ ;
		if (loop_count / ANIM_SPEED_BIGEXP >= 8){			
			loop_count = 0;
<<<<<<< HEAD
			Game::getIns()->stageClear();			
			Images::getIns()->playSE("sound/sen_ka_heirappa01.mp3");
=======
			Game::getIns()->stageInc();
			hp = meka_castle_hp[stage];
			SoundController::getSE()->playSE("sound/sen_ka_heirappa01.mp3");
>>>>>>> 5e692be8e0f7d1066d8ddc8ebb5fa0c9292004ec

		}
		break;*/
/*	case CastleState::MEKA_DIE:

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
		break;*/

//	}
}


void castle::draw(int cx){
/*	int koma = (hp < castle_hp[stage] / 2) ? 1 : 0;
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
	case CastleState::OCCUPY:
		DrawGraph(x - draw_gap[stage][2] - cx, y, Images::getIns()->g_castle[stage][2], true);
		//DrawFormatString(FIELD_W - 50, 200, GetColor(255, 255, 255), "%d", hp);

		break;
	case CastleState::MEKA_DIE:
		if (stage!=0)
			DrawGraph(x - draw_gap[stage][2] - cx, y, Images::getIns()->g_mekahaikyo, true);
		break;
		
	}*/


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
			case UnitType::_IKAROS:
				Game::getIns()->damage_effect_create(x +100+rand_x, y + height - HEI_GUNSHOT + 25-rand_y, GUNSHOT);
				break;
			case UnitType::_TANK:
			case UnitType::_BEEBAR:
				Game::getIns()->damage_effect_create(x + width - WID_CANNONSHOT * 2 - rand_x, y + HEI_CASTLE - HEI_CANNONSHOT - rand_y, CANNONSHOT);
				break;
			case UnitType::_GEKKO:
				Game::getIns()->damage_effect_create(x + width - WID_GUNSHOT * 2 - rand_x, y + HEI_CASTLE - HEI_GUNSHOT - rand_y, GUNSHOT, true);
				break;
			case UnitType::_HIME:
				Game::getIns()->damage_effect_create(x + rand_x, y + height - HEI_ZANGEKI + 25 - rand_y, ZANGEKI);
				break;
			case UnitType::_MONORIS:
				Game::getIns()->damage_effect_create(x + width - WID_MONOB_H * 2 - rand_x, y + HEI_CASTLE - HEI_MONOB_H - rand_y, MONOB_H, true);
				break;			
			}
		}
		
	
		hp -= max(d - defense, 0);
		if (hp < 0){
				Game::getIns()->effect_create(x, 0, BIGEXP);
			loop_count = 0;
			state = CastleState::DIE;
		}
		break;
	case CastleState::STAY:

		break;
	case CastleState::DIE:
		break;
	}
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

void castle::setState(CastleState s){
	state = s;
}