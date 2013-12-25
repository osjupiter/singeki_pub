#pragma once
#include  "DxLib.h"
#include "unit.h"

class enemy : public unit{
protected:
	int level;
	int power;
	int speed;
	int atk_freq;
	int defense;
	Position atk_type;
	int clk;
	int cost;
	
public:
	enemy(int,int,int,int);
	virtual void main(int);
	virtual void draw(int);
	void del();
	int getPower();
	Position getAtkType();
	void damage(int, Position);
	void changeState(UnitState);
};