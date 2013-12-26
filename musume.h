#pragma once
#include "Dxlib.h"
#include "GV.h"
#include "unit.h"
#include "Parameter.h"

class musume :public unit{
protected:
	int vx;
	int vy;
	Position atk_position;
	shared_ptr<Parameter> param;
	bool atk;
public:
	musume(int, int, int, shared_ptr<Parameter>);
	virtual void main(int);
	virtual void draw(int);
	void damage(int, Position);
	int getPower();
	Position getAtkType();
	void changeState(UnitState);

	Position decideTargetPos(int target_x_rand, int target_x_sky);
	void del();
};