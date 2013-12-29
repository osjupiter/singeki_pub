#include "Game.h"
#include"mouse.h"
#include "object.h"
#include "hohei.h"
#include "bigrobo.h"
#include "tank.h"
#include "railgun.h"
#include "copter.h"
#include "segway.h"
#include "beam.h"
#include "kamikaze.h"
#include "Status.h"
#include "gunshot.h"
#include "cannonshot.h"
#include "gekko.h"
#include "bazooka.h"
#include "tepodon.h"
#include "mekaNemu.h"
#include "balloon.h"
#include "bomb.h"
#include "missile.h"
#include "shock.h"
#include "explode.h"
#include "bigExplode.h"
#include "nomalExp.h"
#include <time.h>
#include <algorithm>

const int castle_resouce[9] = { 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000 };
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

	cameraTargetSpeed=0;
	cameraMoveCount=0;
	birth_limit=300;
	musume_nuber_list.assign(10,0);
	
	//for DEBUG
/*	for (int i = 0; i < 7; i++){
		stageInc();
	}*/
	
}

void Game::param_init(){
	param_list[HOHEI] = shared_ptr<Parameter>(
		new Parameter(POWER_HOHEI, MAXHP_HOHEI
		, SPEED_HOHEI, DEFENSE_HOHEI, A_TYPE_HOHEI, CLK_HOHEI, COST_HOHEI, A_FREQ_HOHEI,ParamType::MAXHP,ParamType::CLK,ParamType::SPEED));
	param_list[BALLOON] = shared_ptr<Parameter>(
		new Parameter(POWER_BALLOON, MAXHP_BALLOON
		, SPEED_BALLOON, DEFENSE_BALLOON, A_TYPE_BALLOON, CLK_BALLOON, COST_BALLOON, A_FREQ_BALLOON,ParamType::POWER,ParamType::MAXHP,ParamType::SPEED));
	param_list[BAZOOKA] = shared_ptr<Parameter>(
		new Parameter(POWER_BAZOOKA, MAXHP_BAZOOKA
		, SPEED_BAZOOKA, DEFENSE_BAZOOKA, A_TYPE_BAZOOKA, CLK_BAZOOKA, COST_BAZOOKA, A_FREQ_BAZOOKA,ParamType::POWER,ParamType::COST,ParamType::CLK));
	param_list[BIG] = shared_ptr<Parameter>(
		new Parameter(POWER_BIG, MAXHP_BIG
		, SPEED_BIG, DEFENSE_BIG, A_TYPE_BIG, CLK_BIG, COST_BIG, A_FREQ_BIG,ParamType::DEFENSE,ParamType::SPEED,ParamType::POWER));
	param_list[KAMIKAZE] = shared_ptr<Parameter>(
		new Parameter(POWER_KAMIKAZE, MAXHP_KAMIKAZE
		, SPEED_KAMIKAZE, DEFENSE_KAMIKAZE, A_TYPE_KAMIKAZE, CLK_KAMIKAZE, COST_KAMIKAZE, A_FREQ_KAMIKAZE,ParamType::POWER,ParamType::SPEED,ParamType::CLK));
	param_list[SEGWAY] = shared_ptr<Parameter>(
		new Parameter(POWER_SEGWAY, MAXHP_SEGWAY
		, SPEED_SEGWAY, DEFENSE_SEGWAY, A_TYPE_SEGWAY, CLK_SEGWAY, COST_SEGWAY, A_FREQ_SEGWAY,ParamType::SPEED,ParamType::A_FREQ,ParamType::POWER));

}

void Game::background_init(){
	for (int i = 0; i < STAGE_NUM; i++){
		for (int j = 0; j < 5; j++){
			if (j == 2){
				shared_ptr<background> p(new background(stage_W[i], i, j, stage_W[i+1]-stage_W[i], true));
				back_list.push_back(p);
			}
			else{
				shared_ptr<background> p(new background(stage_W[i], i, j, stage_W[i+1] - stage_W[i], false));
				back_list.push_back(p);
			}
		}
	}
}

void Game::castle_init(){

	shared_ptr<castle> p(new castle(stage_W[0], 0, 0));
	castle_list.push_back(p);
	
	p = shared_ptr<castle>(new shiro_yama(stage_W[1], 0, 1));
	castle_list.push_back(p);

	p = shared_ptr<castle>(new castle(stage_W[2], 0, 2));
	castle_list.push_back(p);

	p = shared_ptr<castle>(new castle(stage_W[3], 0, 3));
	castle_list.push_back(p);

	p = shared_ptr<castle>(new castle(stage_W[4], 0, 4));
	castle_list.push_back(p);

	p = shared_ptr<castle>(new castle(stage_W[5], 0, 5));
	castle_list.push_back(p);

	p = shared_ptr<castle>(new castle(stage_W[6], 0, 6));
	castle_list.push_back(p);

	p = shared_ptr<castle>(new castle(stage_W[7], 0, 7));
	castle_list.push_back(p);

	p = shared_ptr<castle>(new mekaNemu(stage_W[8], 0, 8));
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


void Game::birth(int st,int type){
	int line=(int)(rand()/(RAND_MAX+1.0)*3);
	//自分のユニットのときリソース確認消費
	if(type<10){
		int t=getParam(type,ParamType::COST);
		if (getResource() < t) return;
		if(getMusumeSum()>=getBirthLimit())return;
		useResource(t);
		musume_nuber_list.at(type)++;
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
	case GEKKO:{
				   shared_ptr<enemy> p(new gekko(stage_W[st], WINDOW_Y - HEI_GEKKO  - line * 3, line, getNowStage()));
					enemy_list[line].push_back(p);
					break;
	}
	case RAILGUN:{
				shared_ptr<enemy> p(new railgun(stage_W[st], WINDOW_Y - HEI_RAILGUN - line * 3, line, getNowStage()));
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
	case BEAM:{
					 shared_ptr<effect> p(new beam(fx, fy, atk_power));
					 effect_list.push_back(p);
					 break;
	}
	case BIGEXP:{
				 shared_ptr<effect> p(new bigExp(fx, fy));
				 effect_list.push_back(p);
				 break;
	}
	case NOMALEXP:{
					shared_ptr<effect> p(new nomalExp(fx, fy));
					effect_list.push_back(p);
					break;
	}
	case WISP:{
					  shared_ptr<effect> p(new wisp(fx, fy));
					  effect_list.push_back(p);
					  break;
	}	
	case DROP:{
					  shared_ptr<effect> p(new drop(fx, fy));
					  effect_list.push_back(p);
					  break;
	}
	}
}

void Game::damage_effect_create(int fx,int fy,int e_type,bool TurnFlag){
	switch (e_type) {
	case GUNSHOT:{
					 shared_ptr<effect> p(new gunshot(fx, fy, TurnFlag));
					 effect_list.push_back(p);
					 break;
	}
	case CANNONSHOT:{
						shared_ptr<effect> p(new cannonshot(fx, fy, TurnFlag));
						effect_list.push_back(p);
						break;
	}
	}
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

	if(cameraMoveCount-->0){
		x+=cameraTargetSpeed;
		int r_end = stage_W[getNowStage()] + WID_CASTLE / 2 - 100;
		if (x + FIELD_W > r_end){ x = r_end - FIELD_W;cameraMoveCount=0;}
		if (x + FIELD_W > STAGE8_W){ x = STAGE8_W - FIELD_W ;cameraMoveCount=0;}
		if (x < 0){x = 0;cameraMoveCount=0;}

	}

	for (auto i : back_list){
			i->main(x);
	}

	for (int j=0; j < 3; j++){
		for (auto i : enemy_list[j]){
			if (i->getState() != UnitState::DIE){
				if (castle_list.at(now_stage)->getX() > i->getX()){

					if (i->getType() == RAND && target_X > i->getX()){
						target_e = i;
						target_X = i->getX();
					}
				
					if (i->getType() == SKY && target_X_S > i->getX()){
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

			if (front_type == RAND){
//				front = front_tmp;
				front = min(castle_list.at(now_stage)->getX(), front_tmp);
			}
			else if(front_type == SKY){
//				front = front_S_tmp;
				front = min(castle_list.at(now_stage)->getX(), front_S_tmp);
			}

			i->main(front);
			if (i->getState() != UnitState::DIE){
				if (castle_list.at(now_stage - 1)->getX() + castle_list.at(now_stage - 1)->getW() < i->getX()){
					if (i->getType() == RAND && target_X < i->getX()){

						target_m = i;
						target_X = i->getX()+i->getW();
					}


					if (i->getType() == SKY && target_X_S < i->getX()){
						target_m_sky = i;
						target_X_S = i->getX() + i->getW();
					}
				}
			}

			/*ダメージ*/
			if (i->getState() == ATK){
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
			if (i->getState() == ATK){
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

	
	
	for (auto i : castle_list){
		i->main(front_line);
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
	//if (mouse_in::getIns()->LeftClick())  birth(getNowStage() - 1, HOHEI);

	atkrange_musume_list.clear();
	atkrange_enemy_list.clear();

}

void Game::stageInc(){
	for (int j = 0; j < 3; j++){
		for (auto i:enemy_list[j]){
			i->changeState(UnitState::DIE);
		}
	}
	gainResource(castle_resouce[nowstage]);
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
	

	if(memfree_list.size()<10)
		memfree_list.clear();
	else
		memfree_list.erase(memfree_list.begin(),memfree_list.begin()+10);


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

	//if (mouse_in::getIns()->LeftClick())  birth(getNowStage()-1, HOHEI);
	//if (mouse_in::getIns()->LeftClick())  birth(0, HOHEI);

	if (mouse_in::getIns()->RightClick())Game::getIns()->birth(getNowStage() , COPTER);

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

pair<list<shared_ptr<enemy>>*,list<shared_ptr<musume>>*> Game::getDarkness(){
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
		"敵に与えるダメージを強化する。",
		"最大HPを増加させる。",
		"足が速くなる。",
		"ダメージを暗いにくくなる。",
		"^o^",
		"生産速度が増加する。",
		"生産コストが安くなる。",
		"攻撃後の大気時間が短くなる",
	};
	return s[p];
	/*
		base[POWER] = pw;
	base[MAXHP] = mh;
	base[SPEED] = sp;
	base[DEFENSE] = def;
	base[A_TYPE] = a_type;
	base[CLK] = clock;
	base[COST] = cos;
	base[A_FREQ] = a_freq;
	*/

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