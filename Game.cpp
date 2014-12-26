#include "Game.h"
#include"mouse.h"
#include "object.h"

#include "Status.h"

#include "castle.h"
#include "boss_castle.h"

#include "Factory.h"
#include <time.h>
#include <algorithm>
#include "CsvReader.h"


const int castle_resouce[9] = { 4000, 4000, 4500, 5000, 5000, 5500, 6000, 6500, 7000 };
const int Game::stage_W[9] = {0,STAGE1_W, STAGE2_W, STAGE3_W, STAGE4_W, STAGE5_W, STAGE6_W, STAGE7_W, STAGE8_W };
Game* Game::ins;

Game::Game(int _world){
	param_init();
	world = _world;
	ins = this;
	resource = RESOURCE_INIT+5000000;
	background_init();
	castle_init();
	srand((unsigned int)time(NULL));
	x=0;
	nowstage = 1;
	pauseFlag = false;

	cameraTargetSpeed=0;
	cameraMoveCount=0;
	birth_limit=300;
	musume_nuber_list.assign(END_MUSUME,0);
	
	//for DEBUG
	/*
	for (int i = 0; i < 7; i++){
		stageInc();
	}
	//*/
	
}

void Game::param_init(){
	auto data=CsvReader::parseTable("dat/test.txt",",");
	ParamType tmp[UNITTYPE_NUM][11];
	int i=0;
	for(auto a:data){
		for(int j=0;j<11;j++){
			tmp[i][j]=static_cast<ParamType>(stoi(a[j]));
		}
		i++;
	}
	int line = 0;
	
	for (i = 0; i < END_MUSUME;i++){
		if (i == _NONE) continue;
		param_list[i] = shared_ptr<Parameter>(
			new Parameter(tmp[line][0], tmp[line][1], tmp[line][2], tmp[line][3], static_cast<Position>(tmp[line][10]), tmp[line][4], tmp[line][5]
			, tmp[line][6], tmp[line][7], tmp[line][8], tmp[line][9]));
		line++;
	}
	
/*	param_list[_HOHEI] = shared_ptr<Parameter>(
		new Parameter(POWER_HOHEI, MAXHP_HOHEI
		, SPEED_HOHEI, DEFENSE_HOHEI, A_TYPE_HOHEI, CLK_HOHEI, COST_HOHEI, A_FREQ_HOHEI,tmp[0][0],tmp[0][1],tmp[0][2]));
	param_list[_BALOON] = shared_ptr<Parameter>(
		new Parameter(POWER_BALLOON, MAXHP_BALLOON
		, SPEED_BALLOON, DEFENSE_BALLOON, A_TYPE_BALLOON, CLK_BALLOON, COST_BALLOON, A_FREQ_BALLOON,tmp[1][0],tmp[1][1],tmp[1][2]));	
	param_list[_BIG] = shared_ptr<Parameter>(
		new Parameter(POWER_BIG, MAXHP_BIG
		, SPEED_BIG, DEFENSE_BIG, A_TYPE_BIG, CLK_BIG, COST_BIG, A_FREQ_BIG,tmp[2][0],tmp[2][1],tmp[2][2]));
	param_list[_KAMIKAZE] = shared_ptr<Parameter>(
		new Parameter(POWER_KAMIKAZE, MAXHP_KAMIKAZE
		, SPEED_KAMIKAZE, DEFENSE_KAMIKAZE, A_TYPE_KAMIKAZE, CLK_KAMIKAZE, COST_KAMIKAZE, A_FREQ_KAMIKAZE,tmp[3][0],tmp[3][1],tmp[3][2]));
	param_list[_BAZOOKA] = shared_ptr<Parameter>(
		new Parameter(POWER_BAZOOKA, MAXHP_BAZOOKA
		, SPEED_BAZOOKA, DEFENSE_BAZOOKA, A_TYPE_BAZOOKA, CLK_BAZOOKA, COST_BAZOOKA, A_FREQ_BAZOOKA, tmp[4][0], tmp[4][1], tmp[4][2]));
	param_list[_SEGWAY] = shared_ptr<Parameter>(
		new Parameter(POWER_SEGWAY, MAXHP_SEGWAY
		, SPEED_SEGWAY, DEFENSE_SEGWAY, A_TYPE_SEGWAY, CLK_SEGWAY, COST_SEGWAY, A_FREQ_SEGWAY,tmp[5][0],tmp[5][1],tmp[5][2]));
	param_list[_YOUJO] = shared_ptr<Parameter>(
		new Parameter(POWER_YOUJO, MAXHP_YOUJO
		, SPEED_YOUJO, DEFENSE_YOUJO, A_TYPE_YOUJO, CLK_YOUJO, COST_YOUJO, A_FREQ_YOUJO, tmp[6][0], tmp[6][1], tmp[6][2]));
	param_list[_TATEKO] = shared_ptr<Parameter>(
		new Parameter(POWER_TATEKO, MAXHP_TATEKO
		, SPEED_TATEKO, DEFENSE_TATEKO, A_TYPE_TATEKO, CLK_TATEKO, COST_TATEKO, A_FREQ_TATEKO, tmp[7][0], tmp[7][1], tmp[7][2]));
	param_list[_HIME] = shared_ptr<Parameter>(
		new Parameter(POWER_HIME, MAXHP_HIME
		, SPEED_HIME, DEFENSE_HIME, A_TYPE_HIME, CLK_HIME, COST_HIME, A_FREQ_HIME, tmp[8][0], tmp[8][1], tmp[8][2]));
	param_list[_IKAROS] = shared_ptr<Parameter>(
		new Parameter(POWER_IKAROS, MAXHP_IKAROS
		, SPEED_IKAROS, DEFENSE_IKAROS, A_TYPE_IKAROS, CLK_IKAROS, COST_IKAROS, A_FREQ_IKAROS, tmp[9][0], tmp[9][1], tmp[9][2]));
	param_list[_MAJO] = shared_ptr<Parameter>(
		new Parameter(POWER_MAJO, MAXHP_MAJO
		, SPEED_MAJO, DEFENSE_MAJO, A_TYPE_MAJO, CLK_MAJO, COST_MAJO, A_FREQ_MAJO, tmp[10][0], tmp[10][1], tmp[10][2]));
	param_list[_NOUKA] = shared_ptr<Parameter>(
		new Parameter(POWER_NOUKA, MAXHP_NOUKA
		, SPEED_NOUKA, DEFENSE_NOUKA, A_TYPE_NOUKA, CLK_NOUKA, COST_NOUKA, A_FREQ_NOUKA, tmp[10][0], tmp[11][1], tmp[11][2]));
	param_list[_TANK] = shared_ptr<Parameter>(
		new Parameter(POWER_TANK, MAXHP_TANK
		, SPEED_TANK, DEFENSE_TANK, A_TYPE_TANK, CLK_TANK, COST_TANK, A_FREQ_TANK, tmp[11][0], tmp[11][1], tmp[11][2]));
	param_list[_COPTER] = shared_ptr<Parameter>(
		new Parameter(POWER_COPTER, MAXHP_COPTER
		, SPEED_COPTER, DEFENSE_COPTER, A_TYPE_COPTER, CLK_COPTER, COST_COPTER, A_FREQ_COPTER, tmp[12][0], tmp[12][1], tmp[12][2]));
	param_list[_GEKKO] = shared_ptr<Parameter>(
		new Parameter(POWER_GEKKO, MAXHP_GEKKO
		, SPEED_GEKKO, DEFENSE_GEKKO, A_TYPE_GEKKO, CLK_GEKKO, COST_GEKKO, A_FREQ_GEKKO, tmp[13][0], tmp[13][1], tmp[13][2]));
	param_list[_RAILGUN] = shared_ptr<Parameter>(
		new Parameter(POWER_RAILGUN, MAXHP_RAILGUN
		, SPEED_RAILGUN, DEFENSE_RAILGUN, A_TYPE_RAILGUN, CLK_RAILGUN, COST_RAILGUN, A_FREQ_RAILGUN, tmp[14][0], tmp[14][1], tmp[14][2]));
		//*/
}

void Game::background_init(){
	for (int i = 0; i < STAGE_NUM; i++){
		for (int j = 0; j < 5; j++){
				shared_ptr<background> p(new background(stage_W[i], i, j, stage_W[i+1]-stage_W[i], false));
				back_list.push_back(p);
			
		}
	}
}

void Game::castle_init(){

	auto pop_list = CsvReader::parseTable("dat/荒野spown.txt", ",");

	shared_ptr<castle> p(new castle_musume(stage_W[0], 0, 0));
	castle_list.push_back(p);
	
	p = shared_ptr<castle>(new castle_enemy(stage_W[1], 0, 1, pop_list));
	castle_list.push_back(p);

	p = shared_ptr<castle>(new castle_enemy(stage_W[2], 0, 2, pop_list));
	castle_list.push_back(p);

	p = shared_ptr<castle>(new castle_enemy(stage_W[3], 0, 3, pop_list));
	castle_list.push_back(p);

	p = shared_ptr<castle>(new castle_enemy(stage_W[4], 0, 4,pop_list));
	castle_list.push_back(p);

	p = shared_ptr<castle>(new castle_enemy(stage_W[5], 0, 5, pop_list));
	castle_list.push_back(p);

	p = shared_ptr<castle>(new castle_enemy(stage_W[6], 0, 6, pop_list));
	castle_list.push_back(p);

	p = shared_ptr<castle>(new castle_enemy(stage_W[7], 0, 7, pop_list));
	castle_list.push_back(p);

	p = shared_ptr<castle>(new boss_castle(stage_W[8], 0, 8, pop_list, UnitType::_SAIHATE));
	castle_list.push_back(p);

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


shared_ptr<character> Game::birth(int st, int type, int front){
	int line = (int)(rand() / (RAND_MAX + 1.0) * 3);
	//自分のユニットのときリソース確認消費
	if (type < static_cast<int>(UnitType::END_MUSUME)){
		int t=getParam(type,ParamType::COST);
		if (getResource() < t) return nullptr;
		if(getMusumeSum()>=getBirthLimit()) return nullptr;
		useResource(t);
		musume_nuber_list.at(type)++;
		shared_ptr<character> p(Factory::create_chara(stage_W[st], st, line, (UnitType)type));
		if (p != NULL) musume_list[line].push_back(p);
		return p;
	}
	else {
		shared_ptr<character> p(Factory::create_chara(stage_W[st], st,line, (UnitType)type));
		if(p != NULL) enemy_list[line].push_back(p);
		return p;
	}

}

shared_ptr<character> Game::x_birth(int x, int type, bool use_resouce){
	int line = (int)(rand() / (RAND_MAX + 1.0) * 3);
	//自分のユニットのときリソース確認消費
	if (type < static_cast<int>(UnitType::END_MUSUME)){

		int t = getParam(type, ParamType::COST);
		if (getMusumeSum() >= getBirthLimit())return nullptr;
		if (use_resouce){
			if (getResource() < t) return nullptr;
			useResource(t);
		}
		musume_nuber_list.at(type)++;
		shared_ptr<character> p(Factory::create_chara(x, x, line, (UnitType)type));
		if (p != NULL) musume_list[line].push_back(p);
		return p;
	}
	else {
		shared_ptr<character> p(Factory::create_chara(x, 0, line, (UnitType)type));
		if (p != NULL) enemy_list[line].push_back(p);
		return p;
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
//	if (getClock(STAGE1_W-front_line)) birth(STAGE1_W, TANK);
}

void Game::effect_create(int fx, int fy, int type, Direction dr, int atk_power, int dest){
	shared_ptr<effect> p(Factory::create_effect(fx,fy,type,dr,atk_power,dest));
	if (p != NULL) effect_list.push_back(p);
}

void Game::damage_effect_create(int fx,int fy,int e_type,bool TurnFlag){
	shared_ptr<effect> p(Factory::create_damage_effect(fx, fy, e_type, TurnFlag));
	if (p != NULL) effect_list.push_back(p);
}


void Game::push_del_musume(shared_ptr<musume> p){
	musume_nuber_list.at((int)p->getUnitType())--;
	delete_musumelist.push_back(p);
}
void Game::push_del_enemy(shared_ptr<enemy> p){
	delete_enemylist.push_back(p);
}
void Game::push_del_effect(shared_ptr<effect> p){
	delete_effectlist.push_back(p);
}

void Game::push_castle_list(int stage_num){
	shared_ptr<castle> p(new castle(stage_W[stage_num], 0, stage_num));
	castle_list.push_back(p);
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
	if (pauseFlag)return;
	int now_stage = getNowStage();
	int front=-1;
	int front_tmp, front_S_tmp;
	Position front_type;
	int target_X=INT_MAX,target_X_S=INT_MAX;
	shared_ptr<character> target_e;
	shared_ptr<character> target_m;
	shared_ptr<character> target_e_sky;
	shared_ptr<character> target_m_sky;

	if(cameraMoveCount-->0){
		x+=cameraTargetSpeed;
		int r_end = stage_W[getNowStage()] + WID_CASTLE / 2 - 100;
		if (!getPauseFlag()) //背景デバッグ用if
		if (x + FIELD_W > r_end){ x = r_end - FIELD_W;cameraMoveCount=0;}
		if (x + FIELD_W > STAGE8_W){ x = STAGE8_W - FIELD_W ;cameraMoveCount=0;}
		if (x < 0){x = 0;cameraMoveCount=0;}
		for (auto i : back_list) {
			i->scroll(x);
		}
	}

	for (auto i : back_list){
			i->main(x);
	}

	for (int j=0; j < 3; j++){
		for (auto i : enemy_list[j]){
			if (i->getState() != UnitState::DIE){
				if (castle_list.at(now_stage)->getX() > i->getX()){

					if ((i->getType() == RAND || i->getType() == ALL) && target_X > i->getX()){
						target_e = i;
						target_X = i->getX();
					}
						
					if ((i->getType() == SKY || i->getType() == ALL) && target_X_S > i->getX()){
						target_e_sky = i;
						target_X_S = i->getX();
					}
				}
			}
		}
	}

/*	target_X = min(castle_list.at(now_stage)->getX(), target_X);
	target_X_S = min(castle_list.at(now_stage)->getX(), target_X_S);*/

	front_tmp = target_X;
	front_S_tmp = target_X_S;

	/*味方メイン*/
	target_X = stage_W[now_stage - 1] - 1;
	target_X_S = stage_W[now_stage - 1] - 1;

	for (int j = 0; j < 3; j++){
		for (auto i : musume_list[j]){			
			
			
			front_type = i->decideTargetPos(front_tmp, front_S_tmp);

			if (front_type == RAND || i->getType() == ALL){
//				front = front_tmp;
				front = min(castle_list.at(now_stage)->getX(), front_tmp);
			}
			else if (front_type == SKY || i->getType() == ALL){
//				front = front_S_tmp;
				front = min(castle_list.at(now_stage)->getX(), front_S_tmp);
			}

			i->main(front);
			if (i->getState() != UnitState::DIE){
				if (castle_list.at(now_stage - 1)->getX() + castle_list.at(now_stage - 1)->getW() < i->getX()){
					if ((i->getType() == RAND || i->getType() == ALL) && target_X < i->getX()){

						target_m = i;
						target_X = i->getX()+i->getW();
					}


					if ((i->getType() == SKY || i->getType() == ALL) && target_X_S < i->getX()){
						target_m_sky = i;
						target_X_S = i->getX() + i->getW();
					}
				}
			}

			/*ダメージ*/
			if (i->getAtk()){
			if (front_type == RAND){
				if (target_e != NULL)
					target_e->damage(i->getPower(), i->getAtkType(),i->getUnitType());
				else castle_list.at(now_stage)->damage(i->getPower(),i->getUnitType());
			}
			else if (front_type == SKY){
				if (target_e_sky != NULL)
					target_e_sky->damage(i->getPower(), i->getAtkType(), i->getUnitType());
				else castle_list.at(now_stage)->damage(i->getPower(),i->getUnitType());
			}
			}

			
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
//				front = front_tmp;
				front = max(castle_list.at(now_stage-1)->getX() + castle_list.at(now_stage-1)->getW(), front_tmp);
			}
			else if (front_type == SKY){
//				front = front_S_tmp;
				front = max(castle_list.at(now_stage-1)->getX() + castle_list.at(now_stage-1)->getW(), front_S_tmp);

			}
			i->main(front);
			/*ダメージ*/
			if (i->getAtk()){
			if (front_type == RAND){
				if (target_m != NULL)
					target_m->damage(i->getPower(), i->getAtkType(), i->getUnitType());
				else castle_list.at(now_stage - 1)->damage(i->getPower(), i->getUnitType());
			}
			else if (front_type == SKY){
				if (target_m_sky != NULL)
					target_m_sky->damage(i->getPower(), i->getAtkType(), i->getUnitType());
				else castle_list.at(now_stage - 1)->damage(i->getPower(), i->getUnitType());
			}
			}

		}
	}
	front_line = max(front_tmp,front_S_tmp);

	vector<shared_ptr<castle>>::iterator eraseIterator = castle_list.begin();
	stage_clear = false;
	for (auto i : castle_list){
		i->main(front_line);
		if (stage_clear){
			stageInc();
			break;
		}
	}
	

	for (auto k : atkrange_enemy_list){
		for (int j = 0; j < 3; j++){
			for (auto i : musume_list[j]){
				if (k->judge(i->getX(), i->getW(),i->getType()))
					i->damage(k->getDamage(),k->getAtkType(),UnitType::_NONE);
			}

		}
		int wid_nowcastle = castle_list.at(now_stage - 1)->getW();
		if (k->judge(castle_list.at(now_stage - 1)->getX() - wid_nowcastle / 2, wid_nowcastle, Position::ALL))
			castle_list.at(now_stage - 1)->damage(k->getDamage(), UnitType::_NONE);
	}

	for (auto k : atkrange_musume_list){
		for (int j = 0; j < 3; j++){
			for (auto i : enemy_list[j]){
				if (k->judge(i->getX(), i->getW(), i->getType()))
					i->damage(k->getDamage(), k->getAtkType(),UnitType::_NONE);
			}
		}
		int wid_nowcastle = castle_list.at(now_stage)->getW();
		if (k->judge(castle_list.at(now_stage)->getX() - wid_nowcastle / 2, wid_nowcastle, Position::ALL))
			castle_list.at(now_stage)->damage(k->getDamage(), UnitType::_NONE);
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

	
}

void Game::stageInc(){
	for (int j = 0; j < 3; j++){
		for (auto i:enemy_list[j]){
			i->changeState(UnitState::DIE);
		}
	}
	gainResource(castle_resouce[nowstage]);
	if (nowstage + 1 == STAGE_NUM + 1)return;
	vector<shared_ptr<castle>>::iterator eraseIterator = castle_list.begin();
	for (int i = 0; i < nowstage; i++){
		eraseIterator++;
	}
	eraseIterator = castle_list.erase(eraseIterator);
	nowstage++;	
	
	shared_ptr<castle_musume> p(new castle_musume(stage_W[nowstage - 1], 0, nowstage - 1));
	castle_list.insert(eraseIterator, p);

	
	//castle_list.at(nowstage-1)->setState(OCCUPY);
	//敵城は順番に入ってるはず
	castle_list.at(nowstage)->setState(CastleState::ACTIVE);
}

void Game::stageClear(){
	stage_clear = true;
}

void Game::delete_object(){
	if (!delete_musumelist.empty()){
		for (auto i : delete_musumelist){

			for (int j = 0; j < 3; j++){
				musume_list[j].remove(i);
			}
			memfree_list.push_back(i);
		}
		
		delete_musumelist.clear();
		
		
	}
	if (!delete_enemylist.empty()){
		for (auto i : delete_enemylist){
			for (int j = 0; j < 3; j++){
				enemy_list[j].remove(i);
			}
			memfree_list.push_back(i);
			
		}
		delete_enemylist.clear();
	}

	if (!delete_effectlist.empty()){
		for (auto i : delete_effectlist){		
			effect_list.remove(i);
			memfree_list.push_back(i);
		}
		delete_effectlist.clear();
	}
	
/*	atkrange_musume_list.clear();
/*	atkrange_enemy_list.clear();

	/*一斉開放による処理落ちを防止*/
	if(memfree_list.size()<10)
		memfree_list.clear();
	else
		memfree_list.erase(memfree_list.begin(),memfree_list.begin()+10);


}



void Game::Test(){
	DrawFormatString(FIELD_W - 200, 113, GetColor(255, 255, 255), "TEST");
/*	DrawFormatString(FIELD_W - 200, 100, GetColor(255, 255, 255), "m%d en%d ef%d", musume_list[0].size() + musume_list[1].size() + musume_list[2].size(), enemy_list[0].size() + enemy_list[1].size() + enemy_list[2].size(),effect_list.size());
	DrawFormatString(FIELD_W - 200, 113, GetColor(255, 255, 255), "x %d", x);

	DrawFormatString(FIELD_W - 200, 126, GetColor(255, 255, 255), "resouce %d", getResource());
	DrawFormatString(FIELD_W - 200, 139, GetColor(255, 255, 255), "stage %d", getNowStage());
	DrawFormatString(FIELD_W - 200, 152, GetColor(255, 255, 255), "clear %d over %d",isClear(),isGameover());
	for (auto i : back_list){
		DrawLine(i->getX() - x, 0, i->getX() - x, 450, GetColor(0, 0, 255), 2);
	}

	if (CheckHitKey(KEY_INPUT_Z)) for (int i = 0; i < 1; i++);
	if (CheckHitKey(KEY_INPUT_X)) for (int i = 0; i < 1; i++);
	if (CheckHitKey(KEY_INPUT_C)) for (int i = 0; i < 3; i++)enemy_list[i].clear();
	if (CheckHitKey(KEY_INPUT_V)) for (int i = 0; i < 3; i++)musume_list[i].clear();



	for (int i = 1; i < END_MUSUME; i++){
		param_list[i]->draw(0, 200+30*i);
	}

	*/
	for (auto i : atkrange_enemy_list){
		i->draw(x);
	}
	for (auto i : atkrange_musume_list){
		i->draw(x);
	}
	atkrange_musume_list.clear();
	atkrange_enemy_list.clear();

	static bool hit = false;
	static int b_unit = _YOUJO;
	if (CheckHitKey(KEY_INPUT_C)) {
		if (!hit){
			b_unit++;
			if (b_unit == END_MUSUME) b_unit = _YOUJO;
			hit = true;
		}
	}
	else{ hit = false; }
	if (mouse_in::getIns()->RightClick()){
		birth(nowstage-1, b_unit);
		;
	}
}



void Game::scrollLeft(int sx){
	x -= sx;
	if (x < 0)x = 0;
	for (auto i : back_list) {
		i->scroll(x);
	}
}

void Game::scrollRight(int sx){
	int r_end = stage_W[getNowStage()] + WID_CASTLE / 2 - 100;
	x += sx;	
	
	//デバッグ用一時実装
	if (!getPauseFlag())
		if (x + FIELD_W > r_end) x = r_end - FIELD_W;
	if (x + FIELD_W > STAGE8_W) x = STAGE8_W - FIELD_W ;
	for (auto i : back_list) {
		i->scroll(x);
	}
}
void Game::setCamera(int tar){
	cameraMoveCount=10;
	cameraTargetSpeed=(tar-x)/10;
}


/*パラメータ取得関数*/
int Game::getParam(int u_type, ParamType p_type){
	if(u_type==0)return 0;
	return param_list[u_type]->getParam(p_type);
}
int Game::getParamLevel(int u_type, ParamType p_type){
	return param_list[u_type]->getParamLevel(p_type);
}


bool Game::incParamLevel(int u_type, ParamType p_type,int lvcost){
	if (getResource() < lvcost) return false;
	
	if (param_list[u_type]->LevelUp(p_type)){
		useResource(lvcost);
		return true;
	}
	return false;
}

bool Game::isClear(){
	CastleState now_st = castle_list.at(STAGE_NUM)->getState();
	return !(now_st == CastleState::ACTIVE || now_st == CastleState::STAY);
}

bool Game::isGameover(){
	return (castle_list.at(getNowStage() - 1)->getState() == CastleState::DIE);
}

pair<list<shared_ptr<character>>*,list<shared_ptr<character>>*> Game::getDarkness(){
	return std::make_pair(enemy_list,musume_list);
}


vector<int> Game::getMusumeNumber(){
	return musume_nuber_list;
}

void Game::setBirthLimit(int i){
	birth_limit=i;
}
int Game::getBirthLimit(){
	return birth_limit;
}

bool Game::getPauseFlag(){ return pauseFlag; }

void Game::turnPauseFlag(){
	pauseFlag = !pauseFlag;
}

int Game::getMusumeSum(){
	int sum=0;
	for(int i=static_cast<int>(UnitType::_HOHEI);i<static_cast<int>(UnitType::END_MUSUME);i++){
		sum+=musume_nuber_list.at(i);
	}
	return sum;
}


ParamType* Game::getRainForce(int id){
	return param_list[id]->getRainForce();
}

shared_ptr<Parameter> Game::getParam(int id){
		if(id==0)throw "配列範囲外";  
		return param_list[id];
	}

string Game::getParamSummary(ParamType p){
	string s[]={
		"敵へのダメージを増加させる。",
		"最大HPを増加させる。",
		"足が速くなる。",
		"ダメージを食らいにくくなる。",
		"^o^",
		"生産速度が増加する。",
		"生産コストが安くなる。",
		"攻撃後の待機時間が短くなる。",
	};
	return s[p];


}

string Game::getParamName(ParamType p){
	string s[]={
		"攻撃強化",
		"HP増加",
		"スピードアップ",
		"防御アップ",
		"^o^",
		"高速生産",
		"コストダウン",
		"攻撃回数増加",
	};
	return s[p];
}

string Game::getUnitName(UnitType p){
	int i=static_cast<int>(p);
	string s[]={
		"生産中止",
		"歩兵",
		"風船兵",
		"ロボ兵",
		"ミサイル兵",
		"バズーカ兵",
		"セグウェイ兵",
		"ぶるま",
		"太田さん",
		"姫騎士",
		"イカロス兵",
		"魔女",
		"農家",
		"セグウェイ兵",
		"セグウェイ兵",
		"セグウェイ兵",
		"セグウェイ兵",
		"わりとメンヘラ",
		"わりとメンヘラ",
		"わりとメンヘラ",
	};
	return s[i];
}

string Game::getUnitSummary(UnitType p){
	int i=static_cast<int>(p);
	string s[]={
		"節約しよう",
		"一般兵、数が多い",
		"空から爆弾を落とす",
		"とてもかたい",
		"帰宅部所属",
		"空に攻撃ができる。",
		"わりとメンヘラ",
		"運動界から逃げてきた",
		"けっこうかたい",
		"くっ殺",
		"人生なめてそう",
		"世界の良心",
		"宇宙一のギャンブラー",
		"わりとメンヘラ",
		"わりとメンヘラ",
		"わりとメンヘラ",
		"わりとメンヘラ",
		"わりとメンヘラ",
	};
	return s[i];
}