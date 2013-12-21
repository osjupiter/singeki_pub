#include "Game.h"
#include"mouse.h"
#include "object.h"
#include "hohei.h"
#include "bigrobo.h"
#include "tank.h"
#include "balloon.h"
#include "bomb.h"
#include "explode.h"
#include <time.h>
#include <algorithm>
const int Game::stage_W[9] = {0,STAGE1_W, STAGE2_W, STAGE3_W, STAGE4_W, STAGE5_W, STAGE6_W, STAGE7_W, STAGE8_W };
Game* Game::ins;

Game::Game(){
	ins = this;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 3; j++){
			shared_ptr<background> p(new background(stage_W[i], i, j, FIELD_W * 3));
			back_list.push_back(p);
		}
	}

	for (int i=0; i < 9; i++){
		shared_ptr<castle> p(new castle(stage_W[i], 0, i));
		castle_list.push_back(p);
	}
	hohei::setNum(0);
	tank::setNum(0);
	balloon::setNum(0);
	srand((unsigned int)time(NULL));
	x=0;

}

Game* Game::getIns(){ return ins; }

bool Game::getClock(unsigned int clk){
	static unsigned int tm=0;
	unsigned int nowt;
	if ((nowt=(unsigned int)(GetNowCount())) - tm > clk){ tm = nowt; return true; }
	else return false;
}


int Game::getX(){
	return x;
}


void Game::birth(int st,int type){
	int line=(int)(rand()/(RAND_MAX+1.0)*3);
	switch (type){
	case HOHEI:{
		shared_ptr<musume> p(new hohei(stage_W[st], WINDOW_Y-HEI_HOHEI-line*3,line));
		musume_list[line].push_back(p);		
		break;
	}
	case BALLOON:{
		shared_ptr<musume> p(new balloon(stage_W[st], 50 - line * 10, line));
		musume_list[line].push_back(p);

		break;
	}
	case BIG:{
		line = 2;
		shared_ptr<musume> p(new bigrobo(stage_W[st], WINDOW_Y - HEI_BIG - line * 3, line));
		musume_list[line].push_back(p);

		break;
	}
	case TANK:{
		shared_ptr<enemy> p(new tank(stage_W[st], WINDOW_Y - HEI_TANK - line * 3, line));
		enemy_list[line].push_back(p);
		break;
	}

	default:
		break;
	}
}


void Game::enemy_birth(){
	if (getClock(STAGE1_W-front_line)) birth(STAGE1_W, TANK);
}

void Game::effect_create(int fx,int fy,int type){
	switch(type){
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



void Game::main(){
	int now_stage = castle::getCleared();
	int frontE = INT_MAX, frontM = 0;
	int target_X=INT_MAX,target_X_S=INT_MAX;
	shared_ptr<enemy> target_e;
	shared_ptr<musume> target_m;
	shared_ptr<enemy> target_e_sky;
	shared_ptr<musume> target_m_sky;


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
	frontE = target_X;
	/*�������C��*/
	target_X = INT_MIN; target_X_S = INT_MIN;

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

			//���S����
			/*if (!i->getLife()){
				delete_musumelist.push_back(i);
			}*/
		}
	}

	for (auto i : effect_list){
		i->main();
	}

	frontM = target_X;
	/*�G���C��*/
	for (int j = 0; j < 3; j++){
		for (auto i : enemy_list[j]){
			i->main(frontM);
			if (i->getState() == ATK){
				if (target_m != NULL)	
					target_m->damage(i->getPower(), i->getAtkType());
				if (target_m_sky != NULL)
					target_m_sky->damage(i->getPower(), i->getAtkType());
			}
			/*if (!i->getLife()){
				delete_enemylist.push_back(i);
			}*/
		}
	}

	front_line = frontM;
	
	for (auto i : castle_list){
		i->main();
		
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
	DrawFormatString(FIELD_W - 100, 0, GetColor(255, 255, 255), "%d %d %d", musume_list[0].size() + musume_list[1].size() + musume_list[2].size(), enemy_list[0].size() + enemy_list[1].size() + enemy_list[2].size(),effect_list.size());
	DrawFormatString(FIELD_W - 50, 12, GetColor(255, 255, 255), "%d", x);
	if (CheckHitKey(KEY_INPUT_X)) scrollRight(18);
	if (CheckHitKey(KEY_INPUT_Z)) scrollLeft(18);
	if (mouse_in::getIns()->LeftClick())  for (int i = 0; i < 1; i++)birth(0, HOHEI);
	if (mouse_in::getIns()->RightClick())  for (int i = 0; i < 10; i++) birth(0, HOHEI);
	DrawBox(FIELD_W, 0, WINDOW_X, WINDOW_Y, GetColor(0, 255, 255), true);
/*	if (!delete_musumelist.empty()){
		printfDx("del%dused ", musume_list[0].front().use_count());*/
}


void Game::scrollLeft(int sx){
	x -= sx;
	if (x < 0)x = 0;
}

void Game::scrollRight(int sx){
	x += sx;
	if (x + FIELD_W > STAGE8_W) x = STAGE8_W - FIELD_W ;
}