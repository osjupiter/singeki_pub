#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class bazooka : public musume{
private:
	bool stopper;

	static int num;
public:
	bazooka(int fx, int ln);
	void main(int);
	void draw(int);
	static void init();
	static int getNum();
	static void setNum(int);

	void damage(int, int);
};