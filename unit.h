#pragma once
#include"object.h"
#include "difine.h"
#include <memory>
using namespace std; 

class unit:public object{
protected:
	Direction dir;
	int line; //—v‚ç‚ñ‚Ì‚Å‚Í
	int dist;
	int hp;
	int maxhp;
	int wait_time;
	bool state_change_flag;
	UnitType unit_type;

	bool life;//—v‚ç‚ñ‚Ì‚Å‚Í


	Position type;

	unsigned int ani_count;
public:
	unit(int,int);
	virtual void main();
	virtual void draw(int);
	int getLine();
	bool getLife();
//	virtual void damage(int,int);
	//int getPower();
	int getHP(){ return hp; }
	
	Position getType();
	//int getAtkType();
	void switchDirection();
	UnitType getUnitType();

};