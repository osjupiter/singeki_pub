#include "anime.h"

int anime::getX(){
	return x;
}

int anime::getY(){
	return y;
}
void anime::birth(int x, int y, int type){
	switch (type){
	case HOHEI:{
		shared_ptr<object> p(new hohei(x, y));
		musume.push_back(p);
		break;
	}

	default:
		break;
	}
}

void anime::main(){
	
	for (auto i : musume){
		i->main();
	}	
}

void anime::draw(){
	for (auto i : musume){
		i->draw(0);
	}
}


