#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class bazooka : public musume{
private:

	static int num;
public:
	bazooka(int fx, int ln);
	void main(int);
	void draw(int);
	static void init();
	static int getNum();
	static void setNum(int);
	void decideDirection(int front);
	void damage(int, int);
	Position decideTargetPos(int target_x_rand, int target_x_sky);

};