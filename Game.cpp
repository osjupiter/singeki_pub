#include "Game.h"
#include"mouse.h"


Game::Game(){
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++){
			shared_ptr<background> p(new background(i*FIELD_W *3, i, j, FIELD_W *3));
			back_list.push_back(p);
	}

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

void Game::loop (){
	main();
	draw();
	Test();
}

void Game::main(){
	
	for (auto i : musume_list){
		i->main();
		if (!i->getLife()){
			delete_list.push_back(i);
		}
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
	if (!delete_list.empty()){
		for (auto i : delete_list){
			musume_list.remove(i);
		}

		delete_list.clear();
	}
}


void Game::Test(){
	DrawFormatString(0, 32, GetColor(255, 255, 255), "%d", musume_list.size());
	DrawFormatString(0, 44, GetColor(255, 255, 255), "%d",x);
	if (mouse_in::getIns()->Left() == 3)for (int i = 0; i < 10; i++) birth(i*10%400,340+i*3%10, HOHEI);
	if (mouse_in::getIns()->Right() == 3)for (int i = 0; i < 10; i++)birth(i * 10 % 400, 360+i*3%10, HOHEI);
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
	if (x + FIELD_W > FIELD_W * 12) x = FIELD_W * 11;
}