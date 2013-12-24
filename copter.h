#pragma once
#include "DxLib.h"
#include "enemy.h"
#include "GV.h"
#include "Game.h"

class copter : public enemy{
private:
	
	int power;
	int speed;
	int atk_freq;
	int defense;
	int atk_type;
	int clk;
	int cost;

	bool atk;
	static int num;
	
public:
	copter(int, int, int,int);
	void main(int);
	void draw(int);
	static void init();
	void del();
	static int getNum();
	static void setNum(int);
	int getPower();
	int getAtkType();
	void damage(int, int);
};