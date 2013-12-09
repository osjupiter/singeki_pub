#include "Game.h"
#include"mouse.h"
#include <time.h>

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
	
	srand((unsigned int)time(NULL));
	x=0;

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
	default:
		break;
	}
}



void Game::main(){
	/*ñ°ï˚ÉÅÉCÉì*/
	for (int j = 0; j < 3; j++){
		for (auto i : musume_list[j]){
			i->main();
			if (!i->getLife()){
				delete_musumelist.push_back(i);
			}
		}
	}

	/*ìGÉÅÉCÉì*/
	for (int j = 0; j < 3; j++){
		for (auto i : enemy_list[j]){
			i->main();
			if (!i->getLife()){
				delete_enemylist.push_back(i);
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
	DrawFormatString(FIELD_W - 50, 0, GetColor(255, 255, 255), "%d", musume_list[0].size() + musume_list[1].size() + musume_list[2].size());
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