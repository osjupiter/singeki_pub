#pragma once
#include"object.h"

class unit:public object{
protected:
	int line;
	int dist;
	bool life;
	unsigned int ani_count;
public:
	unit(int,int,int);
	virtual void main();
	int getLine();
	bool getLife();
};