#pragma once
#include "Dxlib.h"
#include "GV.h"
#include "unit.h"


class musume :public unit{
protected:
	int vx;
	int vy;
public:
	musume(int,int,int);
	virtual void main(int);
	virtual void draw(int);
	virtual void damage(int, int);
	virtual int getPower();
	virtual int getAtkType();
	void del();
};