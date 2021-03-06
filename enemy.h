#pragma once
#include  "DxLib.h"
#include "character.h"

class enemy : public character,public enable_shared_from_this<enemy>{
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
	
public:
	enemy(int,int,int,UnitType);
	virtual void main(int);
	virtual void draw(int);
	void del();
	int getPower();
	Position getAtkType();
	void damage(int, Position, UnitType);
	void changeState(UnitState);
	virtual Position decideTargetPos(int target_x_rand, int target_x_sky);
	void drawWait(int dx_, int cx, int ty);
	virtual void decideDirection(int front);

};