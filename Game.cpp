#include "Game.h"
#include"mouse.h"
#include "object.h"
#include "hohei.h"
#include "bigrobo.h"
#include "tank.h"
#include "copter.h"
#include "kamikaze.h"
#include "bazooka.h"

#include "balloon.h"
#include "bomb.h"
#include "missile.h"
#include "shock.h"
#include "explode.h"
#include <time.h>
#include <algorithm>

#define RESOURCE_INIT 2000
const int Game::stage_W[9] = {0,STAGE1_W, STAGE2_W, STAGE3_W, STAGE4_W, STAGE5_W, STAGE6_W, STAGE7_W, STAGE8_W };
Game* Game::ins;

Game::Game(){
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

	ins = this;
	resource = RESOURCE_INIT;
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

	for (int i=0; i < 9; i++){
		shared_ptr<castle> p(new castle(stage_W[i], 0, i));
		castle_list.push_back(p);
	}

	srand((unsigned int)time(NULL));
	x=0;

	balloon::init();
	bazooka::init();
	bigrobo::init();
	copter::init();
	hohei::init();
	kamikaze::init();
	tank::init();
	
	
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
	return castle::getNowstage();
}
int Game::getX(){
	return x;
}


void Game::birth(int st,int type){
	int line=(int)(rand()/(RAND_MAX+1.0)*3);
	switch (type){
	case HOHEI:
	{
		if (getResource() < COST_HOHEI) break;
		shared_ptr<musume> p(new hohei(stage_W[st], WINDOW_Y - HEI_HOHEI - line * 3, line, param_list[HOHEI]));
		musume_list[line].push_back(p);		
		useResource(COST_HOHEI);
		break;
	}
	case BALLOON:{
		if (getResource() < COST_BALLOON) break;
		shared_ptr<musume> p(new balloon(stage_W[st], 50 - line * 10, line, param_list[BALLOON]));
		musume_list[line].push_back(p);
		useResource(COST_BALLOON);
		break;
	}
	case BIG:{
		if (getResource() < COST_BIG) break;
		line = 2;
		shared_ptr<musume> p(new bigrobo(stage_W[st], WINDOW_Y - HEI_BIG - line * 3, line, param_list[BIG]));
		musume_list[line].push_back(p);
		useResource(COST_BIG);

		break;
	}
	case KAMIKAZE:{
				if (getResource() < COST_KAMIKAZE) break;
				shared_ptr<musume> p(new kamikaze(stage_W[st], 50 - line * 3, line, param_list[KAMIKAZE]));
				musume_list[line].push_back(p);
				useResource(COST_KAMIKAZE);

				break;
	}
	case BAZOOKA:
	{
			if (getResource() < COST_BAZOOKA) break;
			shared_ptr<musume> p(new bazooka(stage_W[st], WINDOW_Y - HEI_BAZOOKA - line * 3, line, param_list[BAZOOKA]));
			musume_list[line].push_back(p);
			useResource(COST_BAZOOKA);
			break;
	}
	case TANK:{
		shared_ptr<enemy> p(new tank(stage_W[st], WINDOW_Y - HEI_TANK - line * 3, line,castle::getNowstage()));
		enemy_list[line].push_back(p);
		break;
	}
	case COPTER:{
					shared_ptr<enemy> p(new copter(stage_W[st], 50 - line * 3, line, castle::getNowstage()));
		enemy_list[line].push_back(p);
		 break;
	}
	default:
		break;
	}
}

void Game::setProduct(int tw_num, int m_type){
	if (castle::getNowstage() <= tw_num)return;
	castle_list.at(tw_num)->setProduct(m_type);
}
int Game::getProduct(int tw_num){
	if (castle::getNowstage() <= tw_num)return 0;
	return castle_list.at(tw_num)->getProduct();
}

void Game::enemy_birth(){
	if (getClock(STAGE1_W-front_line)) birth(STAGE1_W, TANK);
}

void Game::effect_create(int fx, int fy, int type, Direction dr){
	switch(type) {
	case BOMB:{
		shared_ptr<effect> p(new bomb(fx, fy));
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
				   shared_ptr<effect> p(new missile(fx, fy,dr));
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
	int now_stage = castle::getNowstage();
	int frontE = INT_MAX, frontM = 0;
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
//	if (target_e == NULL) target_X = castle_list.at(now_stage)->getX();
	target_X = min(castle_list.at(now_stage)->getX(),target_X);
	
/*	clsDx();
	printfDx("target_X %d %d", castle_list.at(now_stage)->getX(), target_X);
	*/
	frontE = target_X;
	/*味方メイン*/
	target_X = 0; target_X_S = 0;

	for (int j = 0; j < 3; j++){
		for (auto i : musume_list[j]){
			i->main(frontE);
			if (i->getType() == RAND && target_X < i->getX()){
				target_m = i;
				target_X = i->getX();
			}
			if (i->getType()==SKY && target_X_S < i->getX()){
				target_m_sky = i;
				target_X_S = i->getX();
			}

			if (i->getState() == ATK){
				if (target_e != NULL)
					target_e->damage(i->getPower(), i->getAtkType());
				else castle_list.at(now_stage)->damage(i->getPower());
				if (target_e_sky != NULL)
					target_e_sky->damage(i->getPower(),i->getAtkType());

			}

			
		}
	}

	for (auto i : effect_list){
		i->main();
		
	}

	frontM = target_X;
	/*敵メイン*/
	for (int j = 0; j < 3; j++){
		for (auto i : enemy_list[j]){
			i->main(frontM);
			if (i->getState() == ATK){
				if (target_m != NULL)	
					target_m->damage(i->getPower(), i->getAtkType());
				if (target_m_sky != NULL)
					target_m_sky->damage(i->getPower(), i->getAtkType());
			}

		}
	}

	front_line = frontM;
	
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

void Game::stageInc(int next_st){
	if (next_st == STAGE_NUM + 1)return;
	castle_list.at(next_st-1)->setState(OCCUPY);
	castle_list.at(next_st)->setState(ACTIVE);
	
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

	if (mouse_in::getIns()->LeftClick())for (int i = 0; i < 1; i++) birth(i*10%400, HOHEI);
	if (mouse_in::getIns()->RightClick())Game::getIns()->birth(1, COPTER);

/*	if (!delete_musumelist.empty()){
		printfDx("del%dused ", musume_list[0].front().use_count());*/
}



void Game::scrollLeft(int sx){
	x -= sx;
	if (x < 0)x = 0;
}

void Game::scrollRight(int sx){
	int r_end = stage_W[castle::getNowstage()];
	x += sx;	
	if (x + FIELD_W > r_end) x = r_end - FIELD_W;
	if (x + FIELD_W > STAGE8_W) x = STAGE8_W - FIELD_W ;
}


/*パラメータ取得関数*/
int Game::getParam(int u_type, ParamType p_type){
	return param_list[u_type]->getParam(p_type);
}
int Game::getParamLevel(int u_type, ParamType p_type){
	return param_list[u_type]->getParamLevel(p_type);
}
int Game::getParamCost(int u_type, ParamType p_type){
	return param_list[u_type]->getCost(p_type);
}

bool Game::incParamLevel(int u_type, ParamType p_type){
	return param_list[u_type]->LevelUp(p_type);
}

