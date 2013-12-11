#include "enemy.h"

enemy::enemy(int fx, int fy, int ln) :unit(fx, fy, ln){

}

void enemy::main(int front){
	unit::main();
	if (x < front + dist) state = ATK;
	else state = MOV;
}

void enemy::draw(int cx){

}