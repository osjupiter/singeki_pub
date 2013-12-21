#pragma once
#include  "DxLib.h"
#include "unit.h"

class enemy : public unit{

	int level;
public:
	enemy(int,int,int,int);
	virtual void main(int);
	virtual void draw(int);
	void del();
	void damage(int,int);
};