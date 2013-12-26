#pragma once
#include"object.h"
#include "difine.h"
#include <memory>
using namespace std; 

class unit:public object{
protected:
	Direction dir;
	int line;
	int dist;
	int hp;
	int wait_time;

	bool life;
	int state;
//	int power;
//	int defense;
	Position type;
//	int atk_type;
//	int atk_freq;
//	int cost;
	unsigned int ani_count;
public:
	unit(int,int,int);
	virtual void main();
	virtual void draw(int);
	int getLine();
	bool getLife();
//	virtual void damage(int,int);
	//int getPower();
	int getState(); 
	Position getType();
	//int getAtkType();
	void switchDirection();
};