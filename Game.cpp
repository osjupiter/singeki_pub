#include "Game.h"
#include"mouse.h"
#include <time.h>
#include <algorithm>

Game::Game(){
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 3; j++){
			shared_ptr<background> p(new background(i*FIELD_W *3, i, j, FIELD_W *3));
			back_list.push_back(p);
	}
	for (int i=0; i < 8; i++){
		shared_ptr<castle> p(new castle((i+1)*FIELD_W * 3, 0, i));
		castle_list.push_back(p);
	}
	hohei::setNum(0);
	tank::setNum(0);

	srand((unsigned int)time(NULL));
	x=0;

}

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
		shared_ptr<musume> p(new hohei(st, WINDOW_Y-HEI_HOHEI-line*20,line));
		musume_list[line].push_back(p);
		
		break;
	}
	case TANK:{
		shared_ptr<enemy> p(new tank(st, WINDOW_Y - HEI_TANK - line * 20, line));
		enemy_list[line].push_back(p);
		break;
	}
	default:
		break;
	}
}

void Game::enemy_birth(){
	if (getClock(500)) birth(STAGE1_W, TANK);
}


void Game::main(){
	int frontE,frontM;
	int target_X=INT_MAX;
	shared_ptr<enemy> target_e;
	shared_ptr<musume> target_m;
	for (int j=0; j < 3; j++){
		for (auto i : enemy_list[j]){
			if (target_X>i->getX()){
				target_e = i;
				target_X = i->getX();
			}
		}
	}
	frontE = target_X;
	/*ñ°ï˚ÉÅÉCÉì*/
	target_X = INT_MIN;
	for (int j = 0; j < 3; j++){
		for (auto i : musume_list[j]){
			i->main(frontE);
			if (target_X<i->getX()){
				target_m = i;
				target_X = i->getX();
			}
			if (i->getState()==ATK && target_e!=NULL)
				target_e->damage(i->getPower());
			if (!i->getLife()){
				delete_musumelist.push_back(i);
			}
		}
	}
	frontM = target_X;
	/*ìGÉÅÉCÉì*/
	for (int j = 0; j < 3; j++){
		for (auto i : enemy_list[j]){
			i->main(frontM);
			if (i->getState() == ATK && target_m != NULL)
				target_m->damage(i->getPower());
			if (!i->getLife()){
				delete_enemylist.push_back(i);
			}
		}
	}

	
	
	enemy_birth();
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
	
	Test();
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
}


void Game::Test(){
	DrawFormatString(FIELD_W - 50, 0, GetColor(255, 255, 255), "%d %d", musume_list[0].size() + musume_list[1].size() + musume_list[2].size(), enemy_list[0].size() + enemy_list[1].size() + enemy_list[2].size());
	DrawFormatString(FIELD_W - 50, 12, GetColor(255, 255, 255), "%d", x);
	if (mouse_in::getIns()->LeftClick())for (int i = 0; i < 1; i++) birth(i*10%400, HOHEI);
	if (mouse_in::getIns()->RightClick())for (int i = 0; i < 1; i++)birth(i * 10 % 400, HOHEI);
	if (mouse_in::getIns()->LeftPush()) scrollLeft(18);
	if (mouse_in::getIns()->RightPush()) scrollRight(18);
	DrawBox(FIELD_W, 0, WINDOW_X, WINDOW_Y, GetColor(0, 255, 255), true);

}


void Game::scrollLeft(int sx){
	x -= sx;
	if (x < 0)x = 0;
}

void Game::scrollRight(int sx){
	x += sx;
	if (x + FIELD_W > FIELD_W * 15) x = FIELD_W * 14;
}