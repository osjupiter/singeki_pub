#pragma once
#include "DxLib.h"
#include "enemy.h"
#include "GV.h"
#include "Game.h"

class copter : public enemy{
private:
	bool stopper;
	static int num;
	
public:
	copter(int, int, int);
	void main(int);
	void draw(int);
	static void init();
	
	static int getNum();
	static void setNum(int);

	
};