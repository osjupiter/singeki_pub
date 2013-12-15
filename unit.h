#pragma once
#include"object.h"
#include "difine.h"
#include <memory>
using namespace std;


class unit:public object{
protected:
	int line;
	int dist;
	int hp;
	bool life;
	int state;
	int power;
	int defense;
	unsigned int ani_count;
public:
	unit(int,int,int);
	virtual void main();
	int getLine();
	bool getLife();
	virtual void damage(int);
	int getPower();
	int getState();
};