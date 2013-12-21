#pragma once
#include"object.h"
#include "difine.h"
#include <memory>
using namespace std; 
#define RAND 1
#define SKY 2

class unit:public object{
protected:
	int line;
	int dist;
	int hp;
	bool life;
	int state;
	int power;
	int defense;
	int type;
	int atk_type;
	int cost;
	unsigned int ani_count;
public:
	unit(int,int,int);
	virtual void main();
	virtual void draw(int);
	int getLine();
	bool getLife();
	virtual void damage(int,int);
	int getPower();
	int getState(); 
	int getType();
	int getAtkType();
};