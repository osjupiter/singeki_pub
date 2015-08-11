#pragma once
#include "Dxlib.h"
#include "GV.h"
#include "character.h"
#include "Parameter.h"

class musume :public character, enable_shared_from_this<musume>{
protected:
	int vx;
	int vy;
	Position atk_position;
	
	
public:
	musume(int, int, UnitType);
	virtual void main(int);
	virtual void draw(int);
	void damage(int, Position, UnitType);
	int getPower();
	Position getAtkType();
	void changeState(UnitState);
	void drawWait(int dx_, int cx, int ty);
	virtual Position decideTargetPos(int target_x_rand, int target_x_sky);
	void del();
	virtual void decideDirection(int front);

};