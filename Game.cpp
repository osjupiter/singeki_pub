#include "Game.h"
#include"mouse.h"
#include "object.h"
#include "hohei.h"
#include "bigrobo.h"
#include "tank.h"
#include "copter.h"
#include "segway.h"
#include "kamikaze.h"
#include "bazooka.h"
#include "tepodon.h"
#include "balloon.h"
#include "bomb.h"
#include "missile.h"
#include "shock.h"
#include "explode.h"
#include <time.h>
#include <algorithm>

#define RESOURCE_INIT 200000
const int Game::stage_W[9] = {0,STAGE1_W, STAGE2_W, STAGE3_W, STAGE4_W, STAGE5_W, STAGE6_W, STAGE7_W, STAGE8_W };
Game* Game::ins;

Game::Game(){
	param_init();

	ins = this;
	resource = RESOURCE_INIT;
	background_init();
	castle_init();
	srand((unsigned int)time(NULL));
	x=0;
	nowstage = 1;
	balloon::init();
	bazooka::init();
	bigrobo::init();
	copter::init();
	hohei::init();
	kamikaze::init();
	tank::init();
	segway::init();
//	castle::setNowstage(1);
	
}

void Game::param_init(){
	param_list[HOHEI] = shared_ptr<Parameter>(
		new Parameter(POWER_HOHEI, MAXHP_HOHEI
		, SPEED_HOHEI, DEFENSE_HOHEI, A_TYPE_HOHEI, CLK_HOHEI, COST_HOHEI, A_FREQ_HOHEI));
	param_list[BALLOON] = shared_ptr<Parameter>(
		new Parameter(POWER_BALLOON, MAXHP_BALLOON
		, SPEED_BALLOON, DEFENSE_BALLOON, A_TYPE_BALLOON, CLK_BALLOON, COST_BALLOON, A_FREQ_BALLOON));
	param_list[BAZOOKA] = shared_ptr<Parameter>(
		new Parameter(POWER_BAZOOKA, MAXHP_BAZOOKA
		, SPEED_BAZOOKA, DEFENSE_BAZOOKA, A_TYPE_BAZOOKA, CLK_BAZOOKA, COST_BAZOOKA, A_FREQ_BAZOOKA));
	param_list[BIG] = shared_ptr<Parameter>(
		new Parameter(POWER_BIG, MAXHP_BIG
		, SPEED_BIG, DEFENSE_BIG, A_TYPE_BIG, CLK_BIG, COST_BIG, A_FREQ_BIG));
	param_list[KAMIKAZE] = shared_ptr<Parameter>(
		new Parameter(POWER_KAMIKAZE, MAXHP_KAMIKAZE
		, SPEED_KAMIKAZE, DEFENSE_KAMIKAZE, A_TYPE_KAMIKAZE, CLK_KAMIKAZE, COST_KAMIKAZE, A_FREQ_KAMIKAZE));
	param_list[SEGWAY] = shared_ptr<Parameter>(
		new Parameter(POWER_SEGWAY, MAXHP_SEGWAY
		, SPEED_SEGWAY, DEFENSE_SEGWAY, A_TYPE_SEGWAY, CLK_SEGWAY, COST_SEGWAY, A_FREQ_SEGWAY));

}

void Game::background_init(){
	for (int i = 0; i < STAGE_NUM; i++){
		for (int j = 0; j < 5; j++){
			if (j == 2){
				shared_ptr<background> p(new background(stage_W[i], i, j, FIELD_W * 3, true));
				back_list.push_back(p);
			}
			else{
				shared_ptr<background> p(new background(stage_W[i], i, j, FIELD_W * 3, false));
				back_list.push_back(p);
			}
		}
	}
}

void Game::castle_init(){

	for (int i = 0; i < 9; i++){
		shared_ptr<castle> p(new castle(stage_W[i], 0, i));
		castle_list.push_back(p);
	
	}

}

Game* Game::getIns(){ return ins; }

bool Game::getClock(unsigned int clk){
	static unsigned int tm=0;
	unsigned int nowt;
	if ((nowt=(unsigned int)(GetNowCount())) - tm > clk){ tm = nowt; return true; }
	else return false;
}

int Game::getResource(){
	return resource;
}
void Game::useResource(int cost){
	resource -= cost;
}
void Game::gainResource(int gain){
	resource += gain;
}

int Game::getNowStage(){
	return nowstage;
}
int Game::getX(){
	return x;
}


void Game::birth(int st,int type){
	int line=(int)(rand()/(RAND_MAX+1.0)*3);
	//自分のユニットのときリソース確認消費
	if(type<10){
		int t=getParam(type,ParamType::COST);
		if (getResource() < t) return;
		useResource(t);
	}
	switch (type){
	case HOHEI:
	{
		shared_ptr<musume> p(new hohei(stage_W[st], WINDOW_Y - HEI_HOHEI - line * 3, line, param_list[HOHEI]));
		musume_list[line].push_back(p);		
		break;
	}
	case BALLOON:{
		shared_ptr<musume> p(new balloon(stage_W[st], 50 - line * 10, line, param_list[BALLOON]));
		musume_list[line].push_back(p);
		break;
	}
	case BIG:{
		line = 2;
		shared_ptr<musume> p(new bigrobo(stage_W[st], WINDOW_Y - HEI_BIG - line * 3, line, param_list[BIG]));
		musume_list[line].push_back(p);

		break;
	}
	case KAMIKAZE:{
				shared_ptr<musume> p(new kamikaze(stage_W[st], 50 - line * 3, line, param_list[KAMIKAZE]));
				musume_list[line].push_back(p);
				break;
	}
	case BAZOOKA:
	{
			shared_ptr<musume> p(new bazooka(stage_W[st], WINDOW_Y - HEI_BAZOOKA - line * 3, line, param_list[BAZOOKA]));
			musume_list[line].push_back(p);
			break;
	}
	case SEGWAY:
	{
				   shared_ptr<musume> p(new segway(stage_W[st], WINDOW_Y - HEI_SEGWAY - line * 3, line, param_list[SEGWAY]));
					musume_list[line].push_back(p);
					break;
	}
	case TANK:{
		shared_ptr<enemy> p(new tank(stage_W[st], WINDOW_Y - HEI_TANK - line * 3, line,getNowStage()));
		enemy_list[line].push_back(p);
		break;
	}
	case COPTER:{
					shared_ptr<enemy> p(new copter(stage_W[st], 50 - line * 3, line, getNowStage()));
		enemy_list[line].push_back(p);
		 break;
	}
	default:
		break;
	}
}

void Game::setProduct(int tw_num, int m_type){
	if (getNowStage() <= tw_num)return;
	castle_list.at(tw_num)->setProduct(m_type);
}
int Game::getProduct(int tw_num){
	if (getNowStage() <= tw_num)return 0;
	return castle_list.at(tw_num)->getProduct();
}

double Game::getProductCLKPAR(int tw_num){
	if (getNowStage() <= tw_num)return 0;
	return castle_list.at(tw_num)->getProductCLKPAR();
}

void Game::enemy_birth(){
	if (getClock(STAGE1_W-front_line)) birth(STAGE1_W, TANK);
}

void Game::effect_create(int fx, int fy, int type, Direction dr, int atk_power, int dest){
	switch(type) {
	case BOMB:{
				  shared_ptr<effect> p(new bomb(fx, fy, atk_power));
		effect_list.push_back(p);
		break; 
	}
	case EXP:{
		shared_ptr<effect> p(new explode(fx, fy));
		effect_list.push_back(p);
		break;
	}
	case SHOCK:{
				 shared_ptr<effect> p(new shock(fx, fy));
				 effect_list.push_back(p);
				 break;
	}
	case MISSILE:{
				   shared_ptr<effect> p(new missile(fx, fy,dr,atk_power));
				   effect_list.push_back(p);
				   break;
	}
	case TEPODON:{
					 shared_ptr<effect> p(new tepodon(fx, fy, atk_power,dest));
					 effect_list.push_back(p);
					 break;
	}
	}
}

void Game::push_del_musume(shared_ptr<musume> p){
	delete_musumelist.push_back(p);
}
void Game::push_del_enemy(shared_ptr<enemy> p){
	delete_enemylist.push_back(p);
}
void Game::push_del_effect(shared_ptr<effect> p){
	delete_effectlist.push_back(p);
}
void Game::push_attack_list(shared_ptr<AttackRange> p, int unittype){
	switch (unittype){
	case MUSUME:
		atkrange_musume_list.push_back(p);
		break;
	case ENEMY:
		atkrange_enemy_list.push_back(p);
		break;
	}
}



void Game::main(){
	int now_stage = getNowStage();
	int front=-1;
	int front_tmp, front_S_tmp;
	Position front_type;
	int target_X=INT_MAX,target_X_S=INT_MAX;
	shared_ptr<enemy> target_e;
	shared_ptr<musume> target_m;
	shared_ptr<enemy> target_e_sky;
	shared_ptr<musume> target_m_sky;

	for (auto i : back_list){
			i->main(x);
	}

	for (int j=0; j < 3; j++){
		for (auto i : enemy_list[j]){
			if (i->getType() == RAND && target_X > i->getX()){
				target_e = i;
				target_X = i->getX();
			}
			if (i->getType()==SKY && target_X_S > i->getX()){
				target_e_sky = i;
				target_X_S = i->getX();
			}
		}
	}

	target_X = min(castle_list.at(now_stage)->getX(),target_X);
	target_X_S = min(castle_list.at(now_stage)->getX(), target_X_S);

	front_tmp = target_X;
	front_S_tmp = target_X_S;

	/*味方メイン*/
	target_X = stage_W[now_stage - 1] - 1;
	target_X_S = stage_W[now_stage - 1] - 1;

	for (int j = 0; j < 3; j++){
		for (auto i : musume_list[j]){			
			
			
			front_type = i->decideTargetPos(front_tmp, front_S_tmp);

			if (front_type == RAND){
				front = front_tmp;
			}
			else if(front_type == SKY){
				front = front_S_tmp;
			}

			i->main(front);
			if (i->getType() == RAND && target_X < i->getX()){
				target_m = i;
				target_X = i->getX();
			}

			if (i->getType()==SKY && target_X_S < i->getX()){
				target_m_sky = i;
				target_X_S = i->getX();
			}

		//	if (i->getState() == ATK){
			if (front_type == RAND){
				if (target_e != NULL)
					target_e->damage(i->getPower(), i->getAtkType());
				else castle_list.at(now_stage)->damage(i->getPower());
			}
			else if (front_type == SKY){
				if (target_e_sky != NULL)
					target_e_sky->damage(i->getPower(), i->getAtkType());
				else castle_list.at(now_stage)->damage(i->getPower());
			}
			//}

			
		}
	}

	for (auto i : effect_list){
		i->main();
		
	}

	front_tmp = target_X;
	front_S_tmp = target_X_S;

	/*敵メイン*/
	for (int j = 0; j < 3; j++){
		for (auto i : enemy_list[j]){
			front_type = i->decideTargetPos(front_tmp, front_S_tmp);

			if (front_type == RAND){
				front = front_tmp;
			}
			else if (front_type == SKY){
				front = front_S_tmp;
			}
			i->main(front);
		//	if (i->getState() == ATK){
			if (front_type == RAND){
				if (target_m != NULL)
					target_m->damage(i->getPower(), i->getAtkType());
				else castle_list.at(now_stage - 1)->damage(i->getPower());
			}
			else if (front_type == RAND){
				if (target_m_sky != NULL)
					target_m_sky->damage(i->getPower(), i->getAtkType());
				else castle_list.at(now_stage - 1)->damage(i->getPower());
			}
		//	}

		}
	}

	front_line = front;
	
	for (auto i : castle_list){
		i->main();
	}

	for (auto k : atkrange_enemy_list){
		for (int j = 0; j < 3; j++){
			for (auto i : musume_list[j]){
				if (k->judge(i->getX(), i->getW(),i->getType()))
					i->damage(k->getDamage(),k->getAtkType());
			}
		}
	}

	for (auto k : atkrange_musume_list){
		for (int j = 0; j < 3; j++){
			for (auto i : enemy_list[j]){
				if (k->judge(i->getX(), i->getW(), i->getType()))
					i->damage(k->getDamage(), k->getAtkType());
			}
		}
	}

	delete_object();

}

void Game::draw(){
	
	for (auto i : back_list){
		if (i->inCamera(x))
			i->draw(x);
	}

	for (auto i : castle_list){
		if (i->inCamera(x))
			i->draw(x);
	}

	for (int i = 2; i >= 0; i--){
		for (auto j : enemy_list[i]){
			if (j->inCamera(x))
				j->draw(x);
		}
	}

	for (int i = 2; i >= 0; i--){
		for (auto j : musume_list[i]){
			if (j->inCamera(x))
				j->draw(x);
		}
	}
	
	for (auto i : effect_list){		
		if (i->inCamera(x))
			i->draw(x);
	}

	Test();
	atkrange_musume_list.clear();
	atkrange_enemy_list.clear();

}

void Game::stageInc(){
	if (nowstage+1 == STAGE_NUM + 1)return;
	nowstage++;
	castle_list.at(nowstage-1)->setState(OCCUPY);
	castle_list.at(nowstage)->setState(ACTIVE);
}

void Game::delete_object(){
	if (!delete_musumelist.empty()){
		for (auto i : delete_musumelist){

			for (int j = 0; j < 3; j++){
				musume_list[j].remove(i);
			}
		}
		
		delete_musumelist.clear();
	}
	if (!delete_enemylist.empty()){
		for (auto i : delete_enemylist){
			for (int j = 0; j < 3; j++){
				enemy_list[j].remove(i);
				
			}
			
		}
		delete_enemylist.clear();
	}

	if (!delete_effectlist.empty()){
		for (auto i : delete_effectlist){		
			effect_list.remove(i);

		}

		delete_effectlist.clear();
	}


}



void Game::Test(){
	DrawFormatString(FIELD_W - 200, 100, GetColor(255, 255, 255), "m%d en%d ef%d", musume_list[0].size() + musume_list[1].size() + musume_list[2].size(), enemy_list[0].size() + enemy_list[1].size() + enemy_list[2].size(),effect_list.size());
	DrawFormatString(FIELD_W - 200, 113, GetColor(255, 255, 255), "x %d", x);

	DrawFormatString(FIELD_W - 200, 126, GetColor(255, 255, 255), "resouce %d", getResource());
	DrawFormatString(FIELD_W - 200, 139, GetColor(255, 255, 255), "stage %d", getNowStage());
	DrawFormatString(FIELD_W - 200, 152, GetColor(255, 255, 255), "clear %d over %d",isClear(),isGameover());
	for (auto i : back_list){
		DrawLine(i->getX() - x, 0, i->getX() - x, 450, GetColor(0, 0, 255), 2);
	}

	if (CheckHitKey(KEY_INPUT_Z)) for (int i = 0; i < 1; i++);
	if (CheckHitKey(KEY_INPUT_X)) for (int i = 0; i < 1; i++)setProduct(0,KAMIKAZE);
	if (CheckHitKey(KEY_INPUT_C)) for (int i = 0; i < 3; i++)enemy_list[i].clear();
	if (CheckHitKey(KEY_INPUT_V)) for (int i = 0; i < 3; i++)musume_list[i].clear();

	for (auto i : atkrange_enemy_list){
		i->draw(x);
	}
	for (auto i : atkrange_musume_list){
		i->draw(x);
	}

	for (int i = 1; i < UNIT_M_NUM+1; i++){
		param_list[i]->draw(0, 200+30*i);
	}

	//if (mouse_in::getIns()->LeftClick())  birth(castle::getNowstage(), HOHEI);
	if (mouse_in::getIns()->LeftClick())  birth(0, HOHEI);

	if (mouse_in::getIns()->RightClick())Game::getIns()->birth(1, COPTER);

/*	if (!delete_musumelist.empty()){
		printfDx("del%dused ", musume_list[0].front().use_count());*/
}



void Game::scrollLeft(int sx){
	x -= sx;
	if (x < 0)x = 0;
}

void Game::scrollRight(int sx){
	int r_end = stage_W[getNowStage()] + WID_CASTLE / 2 - 100;
	x += sx;	
	if (!CheckHitKey(KEY_INPUT_Z))
		if (x + FIELD_W > r_end) x = r_end - FIELD_W;
	if (x + FIELD_W > STAGE8_W) x = STAGE8_W - FIELD_W ;
}


/*パラメータ取得関数*/
int Game::getParam(int u_type, ParamType p_type){
	if(u_type==0)return 0;
	return param_list[u_type]->getParam(p_type);
}
int Game::getParamLevel(int u_type, ParamType p_type){
	return param_list[u_type]->getParamLevel(p_type);
}
/*
int Game::getParamCost(int u_type, ParamType p_type){
	return param_list[u_type]->getCost(p_type);
}*/

bool Game::incParamLevel(int u_type, ParamType p_type,int lvcost){
	if (getResource() <= lvcost) return false;
	
	if (param_list[u_type]->LevelUp(p_type)){
		useResource(lvcost);
		return true;
	}
	return false;
}

bool Game::isClear(){
	int now_st = castle_list.at(STAGE_NUM)->getState();
	return !(now_st == CastleState::ACTIVE || now_st == CastleState::STAY);
}

bool Game::isGameover(){
	return (castle_list.at(getNowStage()-1)->getState()==MEKA_DIE);
}
