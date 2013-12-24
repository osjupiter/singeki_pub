#pragma once
#include "DxLib.h"
#include "enemy.h"
#include "GV.h"

class copter : public enemy{
private:
	bool atk;
	static int num;
	
public:
	copter(int, int, int,int);
	void main(int);
	void draw(int);
	static int getNum();
	static void setNum(int);
};