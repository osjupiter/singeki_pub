#pragma once
#include  "DxLib.h"
#include "unit.h"

class enemy : public unit,enable_shared_from_this<enemy>{
protected:
	int level;
	int power;
	int speed;
	int atk_freq;
	int defense;
	Position atk_type;
	int clk;
	int cost;
	Position atk_position;
	bool atk;
public:
	enemy(int,int,int,int);
	virtual void main(int);
	virtual void draw(int);
	void del();
	int getPower();
	Position getAtkType();
	void damage(int, Position, UnitType);
	void changeState(UnitState);
	Position decideTargetPos(int target_x_rand, int target_x_sky);
};