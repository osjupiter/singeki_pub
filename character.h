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
	bool visible;

	bool no_damage_flag;
public:
	character(int, int, UnitType);
	virtual void main(int front);
	virtual void draw(int cx);
	virtual void drawHP(int dx_,int cx,int ty);
	virtual void drawBossHP(int dx_,int cx, int ty);

	virtual void draw(int cx, int x, int y,int img);
	virtual UnitState getState();
	bool isMusume();
	PropertyType getProperty();
	virtual int getPower()=0;
	virtual bool getAtk();
	virtual bool getVisible();
	virtual Position getAtkType()=0;
	virtual void damage(int, Position, UnitType)=0;
	virtual void changeState(UnitState)=0;
	virtual Position decideTargetPos(int target_x_rand, int target_x_sky)=0;
	virtual bool isInSight(int front); //相手の最前線が攻撃範囲内にいるか
	virtual void decideDirection(int front);
	void drawWait(int dx_, int cx, int ty,int freq);
	virtual void drawWait(int dx_, int cx, int ty) = 0;

};

