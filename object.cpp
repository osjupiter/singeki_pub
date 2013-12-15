#include "object.h"

int object::getX(){
	return x;
}

int object::getY(){
	return y;
}

int object::getW(){
	return width;
}

/*
void object::main(){
	
}

void object::draw(int){
	
}*/

bool object::inCamera(int cx){
	return (cx <= getX() + getW() && getX() <= cx + FIELD_W);
}