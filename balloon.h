#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class balloon : public musume{
private:

	
	static int num;
public:
	balloon(int fx, int ln);
	void main(int);
	void draw(int);
	static void init();
	static int getNum();
	static void setNum(int);
	void decideDirection(int front);
	void damage(int, int);
};