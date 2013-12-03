#include "Game.h"
#include"mouse.h"


Game::Game(){
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++){
			shared_ptr<background> p(new background(i*FIELD_W *3, i, j, FIELD_W *3));
			back_list.push_back(p);
	}
	x=0;

}

int Game::getX(){
	return x;
}

void Game::birth(int x, int y, int type){
	switch (type){
	case HOHEI:{
		shared_ptr<object> p(new hohei(x, y));
		musume_list.push_back(p);
		break;
	}

	default:
		break;
	}	
}



void Game::main(){
	Test();
	for (auto i : musume_list){
		i->main();
	}	
	delete_object();
	
}

void Game::draw(){
	
	for (auto i : back_list){
		if (i->inCamera(x))
			i->draw(x);
	}

	for (auto i : musume_list){
	
		if (i->inCamera(x))
			i->draw(x);
	}
	
}

void Game::delete_object(){
	for (auto i : musume_list){
		if (!i->getLife()){
			delete_list.push_back(i);		
		}			
	}

	for (auto i : delete_list){
		musume_list.remove(i);
	}
	if (!delete_list.empty())	
		delete_list.clear();
}


void Game::Test(){
	DrawFormatString(0, 32, GetColor(255, 255, 255), "%d", musume_list.size());
	DrawFormatString(0, 44, GetColor(255, 255, 255), "%d",x);
	if (mouse_in::getIns()->Left() == 3)for (int i = 0; i < 1; i++) birth(i%400,360, HOHEI);
	if (mouse_in::getIns()->Right() == 3)for (int i = 0; i < 1; i++)birth(i % 400,340, HOHEI);
	if (mouse_in::getIns()->Left() == 1) scrollLeft(18);
	if (mouse_in::getIns()->Right() == 1) scrollRight(18);
	DrawBox(FIELD_W, 0, WINDOW_X, WINDOW_Y, GetColor(0, 255, 255), true);

}


void Game::scrollLeft(int sx){
	x -= sx;
	if (x < 0)x = 0;
}

void Game::scrollRight(int sx){
	x += sx;
}