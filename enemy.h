#pragma once
#include  "DxLib.h"
#include "unit.h"

class enemy : public unit{

	int level;
public:
	enemy(int,int,int,int);
	virtual void main(int);
	virtual void draw(int);
	virtual void del();
	virtual int getPower();
	virtual int getAtkType();
	virtual void damage(int, int);
};