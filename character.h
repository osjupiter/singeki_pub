#pragma once
#include "unit.h"
#include "difine.h"
#include <string>
#include "Parameter.h"

class character : public unit{
protected:
	UnitState state;
	bool no_die_flag;
	PropertyType property;
	string name;
	shared_ptr<Parameter> param;
	bool atk;
	bool stopper;
	bool no_damage_flag;
public:
	character(int, int, UnitType);
	virtual void main(int front);
	virtual void draw(int cx);
	virtual void draw(int cx, int x, int y,int img);
	virtual UnitState getState();
	bool isMusume();
	PropertyType getProperty();
	virtual int getPower()=0;
	virtual bool getAtk();
	virtual Position getAtkType()=0;
	virtual void damage(int, Position, UnitType)=0;
	virtual void changeState(UnitState)=0;
	virtual Position decideTargetPos(int target_x_rand, int target_x_sky)=0;
	virtual bool isInSight(int front); //‘Šè‚ÌÅ‘Oü‚ªUŒ‚”ÍˆÍ“à‚É‚¢‚é‚©
	virtual void decideDirection(int front);
};

